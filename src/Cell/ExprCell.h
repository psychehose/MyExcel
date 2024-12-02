#ifndef EXPRCELL_H
#define EXPRCELL_H

#include "Cell.h"
#include "util/utils.h"

class ExprCell : public Cell
{
protected:
    std::string data;
    std::string *parsed_expr;

    MyExcel::Vector exp_vec;

    // 연산자 우선 순위 반환
    int precedence(char c);
    // 수식 분석
    void parse_expression();

public:
    ExprCell(int x, int y, Table *table, std::string data);
    ~ExprCell();
    std::string stringify() override;
    int to_numeric() override;
};

#endif // EXPRCELL_H