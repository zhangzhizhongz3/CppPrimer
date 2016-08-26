#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include "ex14_24.h"

//! constructor taking size_t as days
//! the argument must be within (0, 2^32)
Date::Date(size_t days)
{
    //! calculate the year
    size_t y400 = days / YtoD_400;
    size_t y100 = (days - y400 * YtoD_400) / YtoD_100;
    size_t y4 = (days - y400 * YtoD_400 - y100 * YtoD_100) / YtoD_4;
    size_t y = (days - y400 * YtoD_400 - y100 * YtoD_100 - y4 * YtoD_4) / 365;
    size_t d = days - y400 * YtoD_400 - y100 * YtoD_100 - y4 * YtoD_4 - y * 365;
    year = y400 * 400 + y100 * 100 + y4 * 4 + y;

    //! check if leap and choose the months vector accordingly
    vector<size_t> currYear = isLeapYear(year) ? monthsVec_l : monthsVec_n;

    //! calculate day and month using find_if + lambda
    size_t D_accumu = 0, M_accumu = 0;
    //! @bug    fixed:  the variables above had been declared inside the find_if as static
    //!                 which caused the bug. It works fine now after being move outside.

    find_if(currYear.cbegin(), currYear.cend(), [&](size_t m) {

        D_accumu += m;
        M_accumu++;

        if (d < D_accumu)
        {
            month = M_accumu;
            day = d + m - D_accumu;

            return true;
        }
        else
            return false;
    });
}

//! constructor taking iostream
Date::Date(istream& is, ostream& os)
{
    is >> day >> month >> year;

    if (is)
    {
        if (check(*this))
            return;
        else
        {
            os << "Invalid input! Object is default initialized.";
            *this = Date();
        }
    }
    else
    {
        os << "Invalid input! Object is default initialized.";
        *this = Date();
    }
}

//! copy constructor
Date::Date(const Date& d) : day(d.day), month(d.month), year(d.year) {}

//! copy-assignment operator=
Date& Date::operator=(const Date& d)
{
    day = d.day;
    month = d.month;
    year = d.year;

    return *this;
}

//! move constructor
Date::Date(Date&& d) noexcept : day(d.day), month(d.month), year(d.year)
{
    cout << "copy moving";
}

//! move-assignment operator=
Date& Date::operator=(Date&& rhs) noexcept
{
    if (this != &rhs)
    {
        day = rhs.day;
        month = rhs.month;
        year = rhs.year;
    }
    cout << "moving =";

    return *this;
}

//! convert to days
size_t Date::toDays() const
{
    size_t result = day;

    //! check if leap and choose the months vector accordingly
    vector<size_t> currYear = isLeapYear(year) ? monthsVec_l : monthsVec_n;

    //! calculate result + days by months
    for (auto it = currYear.cbegin(); it != currYear.cbegin() + month - 1; ++it)
        result += *it;

    //! calculate result + days by years
    result += (year / 400) * YtoD_400;
    result += (year % 400 / 100) * YtoD_100;
    result += (year % 100 / 4) * YtoD_4;
    result += (year % 4) * YtoD_1;

    return result;
}

//! member operators:   +=  -=
Date& Date::operator+=(size_t offset)
{
    *this = Date(toDays() + offset);
    return *this;
}

Date& Date::operator-=(size_t offset)
{
    if (toDays() > offset)
        *this = Date(toDays() - offset);
    else
        *this = Date();

    return *this;
}

//! non-member operators:  >>  <<  ==  !=  <   >  <=   >=  -  -  +
istream& operator>>(istream& is, Date& d)
{
    if (is)
    {
        Date input = Date(is, cout);
        if (check(input)) d = input;
    }
    return is;
}

ostream& operator<<(ostream& os, const Date& d)
{
    os << d.day << " " << d.month << " " << d.year;
    return os;
}

bool operator==(const Date& lhs, const Date& rhs)
{
    return (lhs.day == rhs.day) && (lhs.month == rhs.month) && (lhs.year == rhs.year);
}

bool operator!=(const Date& lhs, const Date& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Date& lhs, const Date& rhs)
{
    return lhs.toDays() < rhs.toDays();
}

bool operator>(const Date& lhs, const Date& rhs)
{
    return !(lhs <= rhs);
}

bool operator<=(const Date& lhs, const Date& rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}

bool operator>=(const Date& lhs, const Date& rhs)
{
    return !(lhs < rhs);
}

int operator-(const Date& lhs, const Date& rhs)
{
    return lhs.toDays() - rhs.toDays();
}

Date operator-(const Date& lhs, size_t rhs)
{ //!  ^^^ rhs must not be larger than 2^32-1
    //! copy lhs
    Date result(lhs);
    result -= rhs;

    return result;
}

Date operator+(const Date& lhs, size_t rhs)
{ //!  ^^^ rhs must not be larger than 2^32-1
    //! copy lhs
    Date result(lhs);
    result += rhs;

    return result;
}
