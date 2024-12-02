#include "Cell.h"

Cell::Cell(int x, int y, Table *table) : x(x), y(y), table(table)
{
}
Cell::~Cell()
{
    // Default destructor, can be empty or add cleanup if needed
}
