#include <iostream>
#include <fstream>

#include "Excel.h"

int main(int argc, char *argv[])
{
    // TxtTable table(5, 5);

    // std::ofstream out("test.txt");

    // table.reg_cell(new NumberCell(1, 1, &table, 2), 1, 1);
    // table.reg_cell(new NumberCell(1, 2, &table, 3), 1, 2);
    // table.reg_cell(new NumberCell(2, 1, &table, 4), 2, 1);
    // table.reg_cell(new NumberCell(2, 2, &table, 5), 2, 2);

    // table.reg_cell(new ExprCell(3, 2, &table, "B2+B3*(C2+C3-2)"), 3, 2);
    // table.reg_cell(new StringCell(3, 1, &table, "B2 + B3 * ( C2 + C3 - 2 ) = "), 3, 1);

    // std::cout << std::endl
    //           << table;

    // out << table;

    std::cout << "(최대 행 크기) (최대 열 크기) 를 순서대로 입력해주세요" << std::endl;

    int max_row, max_col;
    std::cin >> max_row >> max_col;

    Excel m(max_row, max_col);
    m.command_line();

    return 0;
}