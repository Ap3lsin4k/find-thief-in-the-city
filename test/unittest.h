//
// Created by Andrew on 2020-11-01.
//

#ifndef L2_1_UNITTEST_H
#define L2_1_UNITTEST_H


#define assert_true(condition) \
{                                       \
    if(condition)              \
        printf("Success. The statement is true.");\
    else                  \
        printf("Failed. The statement is false.\n");\
    \
}

#define assert_true_w_msg(message, condition) \
{                                       \
    if(condition)              \
        printf("Success. %s\n", message);\
    else                  \
        printf("Failed. %s is false.\n", message);\
    \
}

#define assert_equal(result, expected) \
{                                       \
    if(result == expected)              \
        printf("Success. Result: %lf\n", result);\
    else                  \
        printf("Failed. %lf != %lf\n", result, expected);\
    \
}

#define assert_equal_int(result, expected) \
{                                       \
    if(result == expected)              \
        printf("Success. Result: %d\n", result);\
    else                  \
        printf("Failed. %d != %d\n", result, expected);\
    \
}

#define assert_equal_llu(result, expected) \
{                                       \
    if (result == expected)              \
        printf("Success. Result: %llu\n", result);\
    else                  \
        printf("Failed. %llu != %llu\n", result, expected);\
    \
}

#endif //L2_1_UNITTEST_H
