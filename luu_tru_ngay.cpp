#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
    unsigned day, month, year;

public:
    Date(unsigned d, unsigned m, unsigned y) : day(d), month(m), year(y) {}
    bool validDate(unsigned day, unsigned month, unsigned year);
    bool isLeapYear(unsigned year);
    unsigned daysInMonth(unsigned month, unsigned year);
    void printDate();
};
unsigned Date::daysInMonth(unsigned month, unsigned year)
{
    switch (month)
    {
    case 2:
        return isLeapYear(year) ? 29 : 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    default:
        return 30;
    }
}
bool Date::isLeapYear(unsigned year)
{
    return (!(year & 3));
}
bool Date::validDate(unsigned day, unsigned month, unsigned year)
{
    if ((31 < day) || (day < 1) || (month < 1) || (12 < month) || (year <= 0))
        return 0;
    return 1;
}
void Date::printDate()
{
    if (validDate(day, month, year))
        cout << setfill('0') << setw(2) << day << '/' << setw(2) << month << '/' << year << endl;
    else
        cout << "Invalid date" << endl;
}
int main()
{
    Date x(30, 5, 2006);
    x.printDate();
    return 0;
}