#include "Cell.h"

Cell::Cell(std::string data, int x, int y, Table *table) : data(data), x(x), y(y), table(table)
{
}

std::string Cell::stringify()
{
    return data;
}

int Cell::to_numeric()
{
    return 0;
}

Cell::~Cell()
{
    // Default destructor, can be empty or add cleanup if needed
}
