#include "StringCell.h"

StringCell::StringCell(int x, int y, Table *table, std::string data) : Cell(x, y, table), data(data) {}

StringCell::~StringCell() {}

std::string StringCell::stringify()
{
    return data;
}

int StringCell::to_numeric()
{
    return 0;
}
