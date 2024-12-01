#include "Table.h"
#include "Cell.h"

Table::Table(int max_row_size, int max_col_size) : max_row_size(max_row_size), max_col_size(max_col_size)
{
    data_table = new Cell **[max_row_size];

    for (int i = 0; i < max_row_size; ++i)
    {
        data_table[i] = new Cell *[max_col_size];
        for (int j = 0; j < max_col_size; ++j)
        {
            data_table[i][j] = nullptr;
        }
    }
}
Table::~Table()
{
    for (int i = 0; i < max_row_size; ++i)
    {
        for (int j = 0; j < max_col_size; ++j)
        {
            if (data_table[i][j] != nullptr)
            {
                delete data_table[i][j];
            }
        }
    }
    for (int i = 0; i < max_row_size; ++i)
    {
        delete[] data_table[i];
    }
    delete[] data_table;
}
void Table::reg_cell(Cell *cell, int row, int col)
{
    if (!(row < max_row_size && col < max_col_size))
        return;

    if (data_table[row][col] != nullptr)
    {
        delete data_table[row][col];
    }

    data_table[row][col] = cell;
}

int Table::to_numeric(const std::string &s)
{
    int col = s[0] - 'A';
    int row = atoi(s.c_str() + 1) - 1;

    if (row < max_row_size && col < max_col_size)
    {
        if (data_table[row][col] != nullptr)
        {
            return data_table[row][col]->to_numeric();
        }
    }

    return 0;
}

int Table::to_numeric(int row, int col)
{
    if (row < max_row_size && col < max_col_size && data_table[row][col])
    {
        return data_table[row][col]->to_numeric();
    }
    return 0;
}

std::string Table::stringify(const std::string &s)
{
    int col = s[0] - 'A';
    int row = atoi(s.c_str() + 1) - 1;

    if (row < max_row_size && col < max_col_size)
    {
        if (data_table[row][col] != nullptr)
        {
            return data_table[row][col]->stringify();
        }
    }

    return std::string();
}

std::string Table::stringify(int row, int col)
{
    if (row < max_row_size && col < max_col_size && data_table[row][col])
    {
        return data_table[row][col]->stringify();
    }
    return std::string();
}

std::ostream &operator<<(std::ostream &os, Table &table)
{
    os << table.print_table();
    return os;
}