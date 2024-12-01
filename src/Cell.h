#ifndef CELL_H
#define CELL_H

#include <string>

// Forward declaration
class Table;

class Cell {

protected:
    int x, y;
    Table* table;

    std::string data;

public:
    virtual std::string stringify();
    virtual int to_numeric();

    Cell(std::string data, int x, int y, Table* table);
};



#endif // CELL_H