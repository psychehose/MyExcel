#include "ExprCell.h"

ExprCell::ExprCell(int x, int y, Table *table, std::string data) : Cell(x, y, table), data(data) {}

ExprCell::~ExprCell() {}

std::string ExprCell::stringify()
{
    return std::string();
}

int ExprCell::to_numeric()
{
    return 0;
}

int ExprCell::precedence(char c)
{
    return 0;
}

void ExprCell::parse_expression()
{
}
