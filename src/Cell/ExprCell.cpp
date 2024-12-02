#include "ExprCell.h"
#include "Table.h"

ExprCell::ExprCell(int x, int y, Table *table, std::string data) : Cell(x, y, table), data(data)
{
    parse_expression();
}
ExprCell::~ExprCell() {}

std::string ExprCell::stringify()
{
    return std::to_string(to_numeric());
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
    // 연산자 우선 순위

    switch (c)
    {
    case '(':
    case '{':
    case '[':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }

    return 0;
}

void ExprCell::parse_expression()
{
    // 중위 표기법 -> 후위 표기법 변환
    // 3 + 4 * 5 + 4 * (7 - 2) -> 3 4 5 * + 4 7 2 - * +
    MyExcel::Stack stack;

    // 수식 전체를 () 로 둘러 사서 exp_vec 에 남아있는 연산자들이 push 되게
    data.insert(0, "(");
    data.push_back(')');

    for (int i = 0; i < data.length(); ++i)
    {
        if (isalpha(data[i])) // cell인 경우
        {
            exp_vec.push_back(data.substr(i, 2));
            ++i;
        }
        else if (isdigit(data[i])) // 숫자 한자리 가정
        {
            exp_vec.push_back(data.substr(i, 1));
        }
        else if (data[i] == '(' || data[i] == '[' || data[i] == '{')
        {
            stack.push(data.substr(i, 1));
        }
        else if (data[i] == ')' || data[i] == ']' || data[i] == '}')
        {
            std::string s = stack.pop();

            while (s != "(" && s != "[" && s != "{")
            {
                exp_vec.push_back(s);
                s = stack.pop();
            }
        }
        else if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/')
        {
            while (!stack.is_empty() && precedence(data[i]) <= precedence(stack.peek()[0]))
            {
                exp_vec.push_back(stack.pop());
            }
            stack.push(data.substr(i, 1));
        }
    }
}
