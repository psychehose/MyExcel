#ifndef CELL_H
#define CELL_H

#include <string>

// Forward declaration
class Table;

class Cell
{
protected:
    std::string data;
    int x, y;
    Table *table;

public:
    virtual std::string stringify();
    virtual int to_numeric();

    Cell(std::string data, int x, int y, Table *table);
    virtual ~Cell();

};

#endif // CELL_H