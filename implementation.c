#include <stdbool.h>
#include "implementation.h"

//
// Created by Andy on 2020-11-29.
//

bool is_wanted(double thief)
{
    return 0 <= thief && thief <= 5;
}

bool less_than_wanted(double thief)
{
    return thief < 0;
}

bool greater_than_wanted(double thief)
{
    return thief > 5;
}

void imprison(struct position* pos, unsigned short row, unsigned short col)
{
    pos->found = true;
    pos->row = row;
    pos->column = col;
}

void binarySearchInLastRow(double *const *city, unsigned short columns, struct position *pos, unsigned short last_row_index);
void binarySearchInFirstColumn(double *const *city, struct position *pos, unsigned short last_row);

struct position find_thieves(double **city, unsigned short rows, unsigned short columns)
{
    struct position pos;
    pos.found = false;
    unsigned short last_row = rows - 1;

    binarySearchInLastRow(city, columns, &pos, last_row);

    if (!pos.found)
        binarySearchInFirstColumn(city, &pos, last_row);

    return pos;
}

void binarySearchInFirstColumn(double *const *city, struct position *pos, unsigned short last_row) {
    unsigned short topPivot = 0;
    unsigned short bottomPivot = last_row;
    unsigned short middle;

    while (topPivot <= bottomPivot)
    {
        middle = (topPivot + bottomPivot) / 2;
        if (is_wanted(city[middle][0]))
        {
            imprison(pos, middle, 0);
            return;
        }
        else if (greater_than_wanted(city[middle][0]))
        {
            topPivot = middle + 1;
        }
        else if (less_than_wanted(city[middle][0]))
        {
            if (middle > 0) bottomPivot = middle - 1;
            else { return; }
        }
    }
}

void binarySearchInLastRow(double *const *city, unsigned short columns, struct position *pos, unsigned short last_row) {
    unsigned short leftPivot = 0;
    unsigned short rightPivot = columns - 1;
    unsigned short middle;

    while (leftPivot <= rightPivot)
    {
        middle = (leftPivot + rightPivot) / 2;
        if (is_wanted(city[last_row][middle]))
        {
            imprison(pos, last_row, middle);
            return;
        }
        else if (greater_than_wanted(city[last_row][middle]))
        {
            leftPivot = middle + 1;
        }
        else if (less_than_wanted(city[last_row][middle]))
        {
            if (middle > 0) rightPivot = middle - 1;
            else return;
        }
    }
}