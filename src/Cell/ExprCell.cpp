#include "ExprCell.h"
#include "Table.h"

ExprCell::ExprCell(int x, int y, Table *table, std::string data) : Cell(x, y, table), data(data) {}

ExprCell::~ExprCell() {}

std::string ExprCell::stringify()
{
    return std::string();
}

int ExprCell::to_numeric()
{
    // 후위 표기법으로 된 수식을 계산

    double result = 0.0;
    MyExcel::NumStack stack;

    for (int i = 0; i < exp_vec.size(); ++i)
    {
        std::string s = exp_vec[i];

        // 셀인 경우
        if (isalpha(s[0]))
        {
            stack.push(table->to_numeric(s));
        }
        else if (isdigit(s[0])) // 숫자 한자리 가정
        {
            stack.push(atoi(s.c_str()));
        }
        else
        {
            double y = stack.pop();
            double x = stack.pop();

            switch (s[0])
            {
            case '+':
                stack.push(x + y);
                break;
            case '-':
                stack.push(x - y);
                break;
            case '*':
                stack.push(x * y);
                break;
            case '/':
                stack.push(x / y);
                break;
            }
        }
    }
    return stack.pop();
}

int ExprCell::precedence(char c)
{
    return 0;
}

void ExprCell::parse_expression()
{
}
