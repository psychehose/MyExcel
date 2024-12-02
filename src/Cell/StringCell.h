#ifndef STRINGCELL_H
#define STRINGCELL_H

#include "Cell.h"

class StringCell : public Cell
{

protected:
    std::string data;

public:
    StringCell(int x, int y, Table *table, std::string data);
    virtual ~StringCell();

    std::string stringify() override;
    int to_numeric() override;
};

#endif // STRINGCELL_H