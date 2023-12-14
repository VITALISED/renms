#!/bin/sh

# @file ratio.sh
# @author VITALISED & Contributors
# @since 2023-12-14
#
# Copyright (C) 2023  VITALISED & Contributors
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.


echo "   _ \          \  |   \  |   ___|  ";
echo "  |   |   _ \    \ |  |\/ | \___ \  ";
echo "  __ <    __/  |\  |  |   |       | ";
echo " _| \_\ \___| _| \_| _|  _| _____/  ";
echo "                                    ";

num_h_files=$(find .. -name "*.h" 2>&1 | tee error.log | wc -l)
num_cpp_files=$(find .. -name "*.cpp" 2>&1 | tee -a error.log | wc -l)

if [ $num_cpp_files -ne 0 ]; then
    ratio=$(echo "scale=2; $num_h_files / $num_cpp_files" | bc -l)
    ratio=$(printf "%.2f\n" $ratio)
else
    ratio="Infinity"
fi

num_cmake_files=$(find .. -name "CMakeLists.txt" 2>&1 | tee -a error.log | wc -l)
num_py_files=$(find .. -name "*.py" 2>&1 | tee -a error.log | wc -l)

echo -e "\033[1;34mHeader to source file ratio: $ratio\033[0m"
echo -e "\033[1;35mAll in all, there are: $num_h_files headers.\033[0m"
echo -e "\033[1;32mFun fact: This project has $num_cmake_files CMake files.\033[0m"
echo -e "\033[1;33mAdditionally, there are $num_py_files python files.\033[0m"


# this is cursed
echo -e "\033[1;36mTop 25 most common words in the codebase:\033[0m"
find .. -name "*.[ch]" -print0 | xargs -0 cat | tr -c '[:alnum:]' '[\n*]' | grep -vwE "(auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|#include|#define|#ifndef|#endif|#ifdef|h|the|include|std|meta|of|License|pair|bool|it|or|program)" | sort | uniq -c | sort -nr | head -25 | while read line; do printf "%s " "$line"; done; echo
