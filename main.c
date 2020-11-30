#include <stdio.h>
#include "implementation.h"

int main() {
    double const_array[7][9] = {
            {90,   9,   3.2,  9.2, 32.2,  -6,     20,   99,   35},
            {75.7, 7.7, 2.5,  7.0, 10,    -6.2,   19.8, 48,   29},
            {31,   7,   2,    5.2, 5,     -6.3,   17,   43.3, 21.9},
            {30,   7,   2,    5.1, 5,     -7,     16.3, 41.3, 11},
            {24,   4,   2,    2.3, 2.3,   -8,     10,   12,   1},
            {22.3, 2.3, 1.25, 2,   -1,    -11,    10,   -12,  1},
            {10,   1,   0.5,   0,  -8.08, -11.99, -15,  -22,  -23}
    };

    FIND_THIEVES_IN_CITY(const_array, 7, 9);
    if (result.found)
        printf("A thief %lf has been found at %dx%d (indexing from 1 not 0)", const_array[result.row][result.column], result.row+1, result.column+1);
    else
        printf("All inhabitant are innocent");

    return 0;
}