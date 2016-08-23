//
//  ex14_02.cpp
//  Exercise 14.2
//
//  Created by pezy on 3/9/15.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief implementation of class Sales_data
//  @See ex7_41.cpp
//

#include "ex14_02.h"

Sales_data::Sales_data(std::istream& is) : Sales_data()
{
    is>>*this;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream& operator>>(std::istream& is, Sales_data& item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue<<" "<<item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum+=rhs;
    return sum;
}
