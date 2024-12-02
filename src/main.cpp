#include <iostream>
#include <fstream>

#include "TxtTable.h"
#include "Cell/Cell.h"

#include "Cell/NumberCell.h"
#include "Cell/StringCell.h"
#include "Cell/DateCell.h"
#include "Cell/ExprCell.h"

int main(int argc, char *argv[])
{
    TxtTable table(5, 5);

    std::ofstream out("test.txt");

    table.reg_cell(new NumberCell(1, 1, &table, 2), 1, 1);
    table.reg_cell(new NumberCell(1, 2, &table, 3), 1, 2);
    table.reg_cell(new NumberCell(2, 1, &table, 4), 2, 1);
    table.reg_cell(new NumberCell(2, 2, &table, 5), 2, 2);

    table.reg_cell(new ExprCell(3, 2, &table, "B2+B3*(C2+C3-2)"), 3, 2);
    table.reg_cell(new StringCell(3, 1, &table, "B2 + B3 * ( C2 + C3 - 2 ) = "), 3, 1);

    std::cout << std::endl
              << table;

    out << table;

    return 0;
}