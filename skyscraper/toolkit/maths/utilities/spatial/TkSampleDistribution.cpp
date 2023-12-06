/**
 * @file TkSampleDistribution.cpp
 * @author VITALISED & Contributors
 * @since 2023-12-06
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// the specific implementations for the file were taken from https://github.com/lgruen/mcqmclfsr, thanks
// im too lazy to read papers

#include <toolkit/maths/utilities/spatial/TkSampleDistribution.h>

SKYSCRAPER_BEGIN

cTkMcQmcLFSR::cTkMcQmcLFSR(const uint32_t luiPeriod) : muiPeriod(luiPeriod)
{

    // Table taken from T. Hansen and G. Mullen:
    // "Primitive Polynomials over Finite Fields".
    // It is implied that the coefficient for t^m is 1.
    const unsigned primitive_polynomials[32 - 3 + 1] = {
        (1 << 1) | 1,                       // 3
        (1 << 1) | 1,                       // 4
        (1 << 2) | 1,                       // 5
        (1 << 1) | 1,                       // 6
        (1 << 1) | 1,                       // 7
        (1 << 4) | (1 << 3) | (1 << 2) | 1, // 8
        (1 << 4) | 1,                       // 9
        (1 << 3) | 1,                       // 10
        (1 << 2) | 1,                       // 11
        (1 << 6) | (1 << 4) | (1 << 1) | 1, // 12
        (1 << 4) | (1 << 3) | (1 << 1) | 1, // 13
        (1 << 5) | (1 << 3) | (1 << 1) | 1, // 14
        (1 << 1) | 1,                       // 15
        (1 << 5) | (1 << 3) | (1 << 2) | 1, // 16
        (1 << 3) | 1,                       // 17
        (1 << 7) | 1,                       // 18
        (1 << 5) | (1 << 2) | (1 << 1) | 1, // 19
        (1 << 3) | 1,                       // 20
        (1 << 2) | 1,                       // 21
        (1 << 1) | 1,                       // 22
        (1 << 5) | 1,                       // 23
        (1 << 4) | (1 << 3) | (1 << 1) | 1, // 24
        (1 << 3) | 1,                       // 25
        (1 << 6) | (1 << 2) | (1 << 1) | 1, // 26
        (1 << 5) | (1 << 2) | (1 << 1) | 1, // 27
        (1 << 3) | 1,                       // 28
        (1 << 2) | 1,                       // 29
        (1 << 6) | (1 << 4) | (1 << 1) | 1, // 30
        (1 << 3) | 1,                       // 31
        (1 << 7) | (1 << 6) | (1 << 2) | 1  // 32
    };

    // The original offsets 10 <= m <= 32 are taken from S. Chen, M. Matsumoto, T. Nishimura,
    // and A. Owen: "New inputs and methods for Markov chain quasi-Monte Carlo".
    // The alternative set of offsets for 3 <= m <= 16 was computed by Leonhard Gruenschloss.
    // They should also yield maximal equidistribution as described in P. L'Ecuyer: "Maximally
    // Equidistributed Combined Tausworthe Generators", but their projections might have better
    // maximized minimum distance properties.
    const unsigned offsets[32 - 3 + 1][2] = {
        // org / good proj.
        {1, 1},       // 3
        {2, 2},       // 4
        {15, 15},     // 5
        {8, 8},       // 6
        {4, 4},       // 7
        {41, 41},     // 8
        {113, 113},   // 9
        {115, 226},   // 10 *
        {291, 520},   // 11 *
        {172, 1583},  // 12 *
        {267, 2242},  // 13 *
        {332, 2312},  // 14 *
        {388, 38},    // 15 *
        {283, 13981}, // 16 *
        {514, 514},   // 17
        {698, 698},   // 18
        {706, 706},   // 19
        {1304, 1304}, // 20
        {920, 920},   // 21
        {1336, 1336}, // 22
        {1236, 1236}, // 23
        {1511, 1511}, // 24
        {1445, 1445}, // 25
        {1906, 1906}, // 26
        {1875, 1875}, // 27
        {2573, 2573}, // 28
        {2633, 2633}, // 29
        {2423, 2423}, // 30
        {3573, 3573}, // 31
        {3632, 3632}  // 32
    };

    // Construct the matrix that corresponds to a single transition.
    unsigned matrix[32];
    matrix[luiPeriod - 1] = 0;
    for (unsigned i = 1, pp = primitive_polynomials[luiPeriod - 3]; i < luiPeriod; ++i, pp >>= 1)
    {
        matrix[luiPeriod - 1] |= (pp & 1) << (luiPeriod - i); // Reverse bits.
        matrix[i - 1] = 1 << (luiPeriod - i - 1);
    }

    // Apply the matrix exponentiation according to the offset.
    unsigned result0[32], result1[32];                               // Storage for temporary results.
    for (unsigned i = 0; i < luiPeriod; ++i) result0[i] = matrix[i]; // Copy over row.
    unsigned *in          = result0;
    unsigned *out         = result1;
    const unsigned offset = offsets[luiPeriod - 3][0];
    for (unsigned i = 1; i < offset; ++i)
    {
        // Perform matrix multiplication: out = in * matrix.
        for (unsigned y = 0; y < luiPeriod; ++y)
        {
            out[y] = 0;
            for (unsigned x = 0; x < luiPeriod; ++x)
                for (unsigned i = 0; i < luiPeriod; ++i)
                    out[y] ^= (((in[y] >> i) & (matrix[luiPeriod - i - 1] >> x)) & 1) << x;
        }

        // Swap input and output.
        unsigned *tmp = in;
        in            = out;
        out           = tmp;
    }

    // Transpose the result for simpler multiplication.
    for (unsigned y = 0; y < luiPeriod; ++y)
    {
        mauiF[y] = 0;
        for (unsigned x = 0; x < luiPeriod; ++x) mauiF[y] |= ((in[x] >> y) & 1) << (luiPeriod - x - 1);
    }
}

SKYSCRAPER_END