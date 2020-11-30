#include "unittest.h"
#include "stdio.h"
#include "../implementation.h"
//#include "../dynamic_programming_implementation.h"
#include <stdbool.h>
#include <stdlib.h>





int main(void) {
    // essential tests for laboratory work

    double matrix[3][4] = {
            {5, 11, 12, 13},
            {4, 15, 15, 17},
            {3, -2, -5, -6}
    };
    double matrix2[1][1] = {{-1}};

    {
        CONTROLLER_FIND_THIEVES({{ -1 }}, 1, 1)
        assert_true_w_msg("Should not find a thief in city: {{-1}}", !result.found);
    }
    {
        CONTROLLER_FIND_THIEVES({{ 0 }}, 1, 1)
        assert_true_w_msg("Should find a thief in city: {{0}}", result.found);
        assert_equal_int(result.row, 0);
        assert_equal_int(result.column, 0);
    }
    {
        CONTROLLER_FIND_THIEVES({{ 5 }}, 1, 1)
        assert_true_w_msg("Should imprison a thief in city: {{5}}", result.found);
    }
    {
        CONTROLLER_FIND_THIEVES({{ 5.1 }}, 1, 1)
        assert_true_w_msg("Should not imprison an innocent : {{5.1}}", !result.found);
    }
    {
        CONTROLLER_FIND_THIEVES({{ -0.1 }}, 1, 1)
        assert_true_w_msg("Should not imprison an innocent : {{-0.1}}", !result.found);
    }
    {
        double const_array[1][2] = {{10.0, 9.0}};
        FIND_THIEVES_IN_CITY(const_array, 1, 2);
        assert_true_w_msg("Should not imprison an innocent : {{10}, {9}}", !result.found);
    }
    {
        double const_array[1][3] = {{10.0, 9.6, 5.0}};
        FIND_THIEVES_IN_CITY(const_array, 1, 3);
        assert_true_w_msg("Should imprison a thief : {{10.0, 9.6, 5.0}}", result.found);
        assert_equal_int(result.row, 0);
        assert_equal_int(result.column, 2);
    }
    {
        double const_array[3][3] = {
                {10.0, 9.6, 5.0},
                {9.9,  9.6, 5.0},
                {9.9,  9.6, 5.5}
        };
        FIND_THIEVES_IN_CITY(const_array, 3, 3);
        assert_true_w_msg("City dimensions: 3x3. Should not imprison anyone.", !result.found);
    }

    {
        double const_array[2][7] = {
                {10.0, 9.6, -3,  -3, 10, 5,   60},
                {9.9,  9.6, 5.5, 4,  -2, -10, -20}
        };
        FIND_THIEVES_IN_CITY(const_array, 2, 8);
        assert_true_w_msg("City dimensions: 2x8. Should imprison  a thief", result.found);
        assert_equal_int(result.row, 1);
        assert_equal_int(result.column, 3);
    }
    {
        double const_array[3][3] = {
                {10.0, 9.6, 10.0},
                {4,    9.6, -42.0},
                {-10,  9.6, 5.5}
        };
        FIND_THIEVES_IN_CITY(const_array, 3, 3);
        assert_true_w_msg("City dimensions: 3x3. Should find a thief in the first column.", result.found);
        assert_equal_int(result.row, 1);
        assert_equal_int(result.column, 0);
    }
    {
        double const_array[7][9] = {
                {90,   9,   3.2,  9.2, 32.2,  -6,     20,   99,   35},
                {75.7, 7.7, 2.5,  7.0, 10,    -6.2,   19.8, 48,   29},
                {31,   7,   2,    5.2, 5,     -6.3,   17,   43.3, 21.9},
                {30,   7,   2,    5.1, 5,     -7,     16.3, 41.3, 11},
                {24,   4,   2,    2.3, 2.3,   -8,     10,   12,   1},
                {22.3, 2.3, 1.25, 2,   -1,    -11,    10,   -12,  1},
                {10,   1,   -2,   -5,  -8.08, -11.99, -15,  -22,  -23}
        };
        FIND_THIEVES_IN_CITY(const_array, 7, 9);
        assert_true_w_msg("City dimensions: 7x9. Should find a thief in the last row.", result.found);
        assert_equal_int(result.row, 6);
        assert_equal_int(result.column, 1);
    }

    printf("\n");

    return 0;
}


