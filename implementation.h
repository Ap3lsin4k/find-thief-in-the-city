//
// Created by Andrew on 2020-11-29.
//
#include <stdbool.h>
#include <stdlib.h>

#ifndef L2_1_THIRD_IMPLEMENTATION_H
#define L2_1_THIRD_IMPLEMENTATION_H

#define CREATE_ARRAY(name, rows, columns) \
    double **name; \
    name = malloc(rows * sizeof *name);            \
    for (int i=0; i<rows; i++)                 \
        name[i] = malloc(columns * sizeof *name[i]);

#define FILL_ARRAY(out_array, const_expression, rows, columns) \
    double const_array[rows][columns] = const_expression;            \
    for (unsigned short i=0; i < rows; ++i)   \
        for (unsigned short j=0; j<columns; ++j)   \
            out_array[i][j] = const_array[i][j];

#define DEALLOCATE_ARRAY(name, rows, columns) \
    for (unsigned short i=0; i<rows; i++)              \
        free(name[i]);                     \
    free(name);

#define CONTROLLER_FIND_THIEVES(matrix_brackets, rows, columns) \
    CREATE_ARRAY(city, rows, columns);              \
    FILL_ARRAY(city, matrix_brackets, rows, columns);   \
                                                 \
    struct position result = find_thieves(city, rows, columns);          \
    DEALLOCATE_ARRAY(city, rows, columns);                      \


#define FILL_MATRIX_FROM_CONSTANT_MATRIX(out_matrix, const_matrix, rows, columns) \
    for (unsigned short i=0; i < rows; ++i) \
        for (unsigned short j=0; j<columns; ++j)\
            out_matrix[i][j] = const_matrix[i][j];

#define FIND_THIEVES_IN_CITY(my_city, rows, columns) \
    CREATE_ARRAY(dynamic_matrix_city, rows, columns);              \
    FILL_MATRIX_FROM_CONSTANT_MATRIX(dynamic_matrix_city, my_city, rows, columns);   \
    struct position result = find_thieves(dynamic_matrix_city, rows, columns);          \
    DEALLOCATE_ARRAY(dynamic_matrix_city, rows, columns);

struct position
{
    bool found;
    unsigned short row, column;
};

struct position find_thieves(double **city, unsigned short rows, unsigned short cols);






#endif //L2_1_THIRD_IMPLEMENTATION_H
