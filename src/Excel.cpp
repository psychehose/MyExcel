#include "Excel.h"
#include "Table/Table.h"
#include "Table/TxtTable.h"

#include "Cell/Cell.h"
#include "Cell/NumberCell.h"
#include "Cell/StringCell.h"
#include "Cell/DateCell.h"
#include "Cell/ExprCell.h"

#include <fstream>
#include <iostream>
#include <string>

Excel::Excel(int max_row, int max_col)
{
    current_table = new TxtTable(max_row, max_col);
}

Excel::~Excel()
{
    current_table = nullptr;
}

int Excel::parse_user_input(std::string s)
{
    int next = 0;
    std::string command = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            command = s.substr(0, i);
            next = i + 1;
            break;
        }
        else if (i == s.length() - 1)
        {
            command = s.substr(0, i + 1);
            next = i + 1;
            break;
        }
    }

    std::string to = "";
    for (int i = next; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            to = s.substr(next, i - next);
            next = i + 1;
            break;
        }
        else if (i == s.length() - 1)
        {
            to = s.substr(0, i + 1);
            next = i + 1;
            break;
        }
    }

    // Cell 이름으로 받는다.
    int col = to[0] - 'A';
    int row = atoi(to.c_str() + 1) - 1;

    std::string rest = s.substr(next);

    if (command == "sets")
    {
        current_table->reg_cell(new StringCell(row, col, current_table, rest), row, col);
    }
    else if (command == "setn")
    {
        current_table->reg_cell(new NumberCell(row, col, current_table, atoi(rest.c_str())), row, col);
    }
    else if (command == "setd")
    {
        current_table->reg_cell(new DateCell(row, col, current_table, rest), row, col);
    }
    else if (command == "sete")
    {
        current_table->reg_cell(new ExprCell(row, col, current_table, rest), row, col);
    }
    else if (command == "out")
    {
        std::ofstream out(to);
        out << *current_table;
    }
    else if (command == "exit")
    {
        return 0;
    }

    return 1;
}

void Excel::command_line()
{
    std::cout << "Excel 프로그램을 시작합니다. 종료하려면 'exit'를 입력하세요." << std::endl;
    std::cout << *current_table << std::endl;
    std::cout << ">> ";

    std::string input;
    while (std::getline(std::cin, input))
    {
        if (input == "exit")
        {
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        }

        if (!parse_user_input(input))
        {
            std::cout << "잘못된 입력입니다. 다시 시도해주세요." << std::endl;
        }

        std::cout << *current_table << std::endl;
        std::cout << ">> ";
    }
}
