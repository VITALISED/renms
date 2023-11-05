// huge credit to https://github.com/yabadabu/for_each

#ifndef INC_UTILS_FOR_EACH_H_
#define INC_UTILS_FOR_EACH_H_

#define EXPAND(x) x
#define DEF_AUX_NARGS(                                                                                                 \
    x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24,     \
    x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, \
    x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63, x64, VAL, ...)                     \
    VAL
#define NARGS(...)                                                                                                   \
    EXPAND(DEF_AUX_NARGS(                                                                                            \
        __VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, \
        40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14,  \
        13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))

// --------------------------------------------------
#define FE0_1(what, x)      EXPAND(what(x))
#define FE0_2(what, x, ...) EXPAND(what(x) FE0_1(what, __VA_ARGS__))
#define FE0_3(what, x, ...) EXPAND(what(x) FE0_2(what, __VA_ARGS__))
#define FE0_4(what, x, ...) EXPAND(what(x) FE0_3(what, __VA_ARGS__))
#define FE0_5(what, x, ...) EXPAND(what(x) FE0_4(what, __VA_ARGS__))
#define FE0_6(what, x, ...) EXPAND(what(x) FE0_5(what, __VA_ARGS__))
#define FE0_7(what, x, ...) EXPAND(what(x) FE0_6(what, __VA_ARGS__))
#define FE0_8(what, x, ...) EXPAND(what(x) FE0_7(what, __VA_ARGS__))

#define REPEAT0_(...)       EXPAND(DEF_AUX_NARGS(__VA_ARGS__, FE0_8, FE0_7, FE0_6, FE0_5, FE0_4, FE0_3, FE0_2, FE0_1, 0))
#define FOR_EACH(what, ...) EXPAND(REPEAT0_(__VA_ARGS__)(what, __VA_ARGS__))

// --------------------------------------------------
#define FE1_1(what, x, y)      EXPAND(what(x, y))
#define FE1_2(what, x, y, ...) EXPAND(what(x, y) FE1_1(what, x, __VA_ARGS__))
#define FE1_3(what, x, y, ...) EXPAND(what(x, y) FE1_2(what, x, __VA_ARGS__))
#define FE1_4(what, x, y, ...) EXPAND(what(x, y) FE1_3(what, x, __VA_ARGS__))
#define FE1_5(what, x, y, ...) EXPAND(what(x, y) FE1_4(what, x, __VA_ARGS__))
#define FE1_6(what, x, y, ...) EXPAND(what(x, y) FE1_5(what, x, __VA_ARGS__))
#define FE1_7(what, x, y, ...) EXPAND(what(x, y) FE1_6(what, x, __VA_ARGS__))
#define FE1_8(what, x, y, ...) EXPAND(what(x, y) FE1_7(what, x, __VA_ARGS__))

#define REPEAT1_(...)                           EXPAND(DEF_AUX_NARGS(__VA_ARGS__, FE1_8, FE1_7, FE1_6, FE1_5, FE1_4, FE1_3, FE1_2, FE1_1, 0))
#define FOR_EACH_PIVOT_1ST_ARG(what, arg0, ...) EXPAND(REPEAT1_(__VA_ARGS__)(what, arg0, __VA_ARGS__))

// --------------------------------------------------
#define APPLY1(FN, x, y)       EXPAND(FN(x, y))
#define APPLY2(FN, x, y, ...)  EXPAND(FN(x, y) APPLY1(FN, __VA_ARGS__))
#define APPLY3(FN, x, y, ...)  EXPAND(FN(x, y) APPLY2(FN, __VA_ARGS__))
#define APPLY4(FN, x, y, ...)  EXPAND(FN(x, y) APPLY3(FN, __VA_ARGS__))
#define APPLY5(FN, x, y, ...)  EXPAND(FN(x, y) APPLY4(FN, __VA_ARGS__))
#define APPLY6(FN, x, y, ...)  EXPAND(FN(x, y) APPLY5(FN, __VA_ARGS__))
#define APPLY7(FN, x, y, ...)  EXPAND(FN(x, y) APPLY6(FN, __VA_ARGS__))
#define APPLY8(FN, x, y, ...)  EXPAND(FN(x, y) APPLY7(FN, __VA_ARGS__))
#define APPLY9(FN, x, y, ...)  EXPAND(FN(x, y) APPLY8(FN, __VA_ARGS__))
#define APPLY10(FN, x, y, ...) EXPAND(FN(x, y) APPLY9(FN, __VA_ARGS__))
#define APPLY11(FN, x, y, ...) EXPAND(FN(x, y) APPLY10(FN, __VA_ARGS__))
#define APPLY12(FN, x, y, ...) EXPAND(FN(x, y) APPLY11(FN, __VA_ARGS__))
#define APPLY13(FN, x, y, ...) EXPAND(FN(x, y) APPLY12(FN, __VA_ARGS__))
#define APPLY14(FN, x, y, ...) EXPAND(FN(x, y) APPLY13(FN, __VA_ARGS__))
#define APPLY15(FN, x, y, ...) EXPAND(FN(x, y) APPLY14(FN, __VA_ARGS__))
#define APPLY16(FN, x, y, ...) EXPAND(FN(x, y) APPLY15(FN, __VA_ARGS__))
#define APPLY17(FN, x, y, ...) EXPAND(FN(x, y) APPLY16(FN, __VA_ARGS__))
#define APPLY18(FN, x, y, ...) EXPAND(FN(x, y) APPLY17(FN, __VA_ARGS__))
#define APPLY19(FN, x, y, ...) EXPAND(FN(x, y) APPLY18(FN, __VA_ARGS__))
#define APPLY20(FN, x, y, ...) EXPAND(FN(x, y) APPLY19(FN, __VA_ARGS__))
#define APPLY21(FN, x, y, ...) EXPAND(FN(x, y) APPLY20(FN, __VA_ARGS__))
#define APPLY22(FN, x, y, ...) EXPAND(FN(x, y) APPLY21(FN, __VA_ARGS__))
#define APPLY23(FN, x, y, ...) EXPAND(FN(x, y) APPLY22(FN, __VA_ARGS__))
#define APPLY24(FN, x, y, ...) EXPAND(FN(x, y) APPLY23(FN, __VA_ARGS__))
#define APPLY25(FN, x, y, ...) EXPAND(FN(x, y) APPLY24(FN, __VA_ARGS__))
#define APPLY26(FN, x, y, ...) EXPAND(FN(x, y) APPLY25(FN, __VA_ARGS__))
#define APPLY27(FN, x, y, ...) EXPAND(FN(x, y) APPLY26(FN, __VA_ARGS__))
#define APPLY28(FN, x, y, ...) EXPAND(FN(x, y) APPLY27(FN, __VA_ARGS__))
#define APPLY29(FN, x, y, ...) EXPAND(FN(x, y) APPLY28(FN, __VA_ARGS__))
#define APPLY30(FN, x, y, ...) EXPAND(FN(x, y) APPLY29(FN, __VA_ARGS__))
#define APPLY31(FN, x, y, ...) EXPAND(FN(x, y) APPLY30(FN, __VA_ARGS__))
#define APPLY32(FN, x, y, ...) EXPAND(FN(x, y) APPLY31(FN, __VA_ARGS__))

#define NPAIRARGS(...)                                                                                               \
    EXPAND(DEF_AUX_NARGS(                                                                                            \
        __VA_ARGS__, 32, 32, 31, 31, 30, 30, 29, 29, 28, 28, 27, 27, 26, 26, 25, 25, 24, 24, 23, 23, 22, 22, 21, 21, \
        20, 20, 19, 19, 18, 18, 17, 17, 16, 16, 15, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 9, 9, 8, 8, 7, 7, 6, \
        6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1))
#define APPLYNPAIRARGS(...)                                                                                         \
    EXPAND(DEF_AUX_NARGS(                                                                                           \
        __VA_ARGS__, APPLY32, APPLY32, APPLY31, APPLY31, APPLY30, APPLY30, APPLY29, APPLY29, APPLY28, APPLY28,      \
        APPLY27, APPLY27, APPLY26, APPLY26, APPLY25, APPLY25, APPLY24, APPLY24, APPLY23, APPLY23, APPLY22, APPLY22, \
        APPLY21, APPLY21, APPLY20, APPLY20, APPLY19, APPLY19, APPLY18, APPLY18, APPLY17, APPLY17, APPLY16, APPLY16, \
        APPLY15, APPLY15, APPLY14, APPLY14, APPLY13, APPLY13, APPLY12, APPLY12, APPLY11, APPLY11, APPLY10, APPLY10, \
        APPLY9, APPLY9, APPLY8, APPLY8, APPLY7, APPLY7, APPLY6, APPLY6, APPLY5, APPLY5, APPLY4, APPLY4, APPLY3,     \
        APPLY3, APPLY2, APPLY2, APPLY1, APPLY1))
#define FOR_EACH_PAIR(FN, ...) EXPAND(APPLYNPAIRARGS(__VA_ARGS__)(FN, __VA_ARGS__))

// --------------------------------------------------

#endif