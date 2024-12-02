#ifndef CELL_H
#define CELL_H

#include <string>

// Forward declaration
class Table;

class Cell
{
protected:
    int x, y;
    Table *table;

public:
    virtual std::string stringify() = 0;
    virtual int to_numeric() = 0;

    Cell(int x, int y, Table *table);
    virtual ~Cell();
};

#endif // CELL_H