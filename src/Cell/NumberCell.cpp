#include "NumberCell.h"

NumberCell::NumberCell(int x, int y, Table *table, int data) : Cell(x, y, table), data(data) {}

NumberCell::~NumberCell() {}

std::string NumberCell::stringify()
{
    return std::to_string(data);
}

int NumberCell::to_numeric()
{
    return data;
}
