#include "DateCell.h"

#include <string>
#include <ctime>

DateCell::DateCell(int x, int y, Table *table, std::string s) : Cell(x, y, table)
{
    int year = atoi(s.c_str());
    int month = atoi(s.c_str() + 5);
    int day = atoi(s.c_str() + 8);

    tm timeinfo;
    // Unix 기준년도 1900
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;

    data = mktime(&timeinfo);
}

DateCell::~DateCell() {}

std::string DateCell::stringify()
{
    char buffer[50];
    tm temp;

#ifdef _WIN32
    localtime_s(&temp, &data);
#else
    localtime_r(&data, &temp);
#endif

    //%F 형식 지정자는 "YYYY-MM-DD" 형식을 의미(예: "2023-12-25")
    strftime(buffer, 50, "%F", &temp);

    return std::string(buffer);
}

int DateCell::to_numeric()
{
    return static_cast<int>(data);
}
