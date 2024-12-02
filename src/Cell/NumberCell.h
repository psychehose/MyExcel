#ifndef NUMBERCELL_H
#define NUMBERCELL_H

#include "Cell.h"

class NumberCell : public Cell
{
protected:
    int data;

public:
    NumberCell(int x, int y, Table *table, int data);
    virtual ~NumberCell();
    std::string stringify() override;
    int to_numeric() override;
};

#endif // NUMBERCELL_H