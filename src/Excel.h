#ifndef EXCEL_H
#define EXCEL_H

class Table;

#include <string>

class Excel
{
protected:
    Table *current_table;

public:
    Excel(int max_row, int max_col);
    ~Excel();

    int parse_user_input(std::string s);
    void command_line();
};

#endif // EXCEL_H