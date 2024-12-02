#ifndef DATECELL_H
#define DATECELL_H

#include "Cell.h"

class DateCell : public Cell
{
protected:
    time_t data;

public:
    DateCell(int x, int y, Table *table, std::string s);
    virtual ~DateCell();
    std::string stringify() override;
    int to_numeric() override;
};

#endif // DATECELL_H