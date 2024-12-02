#ifndef TXTTABLE_H
#define TXTTABLE_H

#include "Table.h"
#include <string>

class TxtTable : public Table
{

public:
    TxtTable(int row, int col);
    virtual ~TxtTable();

    std::string repeat_char(int n, char c);
    std::string col_num_to_str(int n);

    std::string print_table() override;
};

#endif // TXTTABLE_H