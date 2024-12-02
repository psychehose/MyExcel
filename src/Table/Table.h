#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <ostream>

// Forward declaration
class Cell;

class Table
{

protected:
    int max_row_size;
    int max_col_size;

    Cell ***data_table;

public:
    Table(int max_row_size, int max_col_size);
    virtual ~Table();

    void reg_cell(Cell *cell, int row, int col);

    // parameter s: cell name - ex) A1, B6
    int to_numeric(const std::string &s);
    int to_numeric(int row, int col);

    std::string stringify(const std::string &s);
    std::string stringify(int row, int col);

    virtual std::string print_table() = 0;

    friend std::ostream &operator<<(std::ostream &os, Table &table);
};

#endif // TABLE_H
