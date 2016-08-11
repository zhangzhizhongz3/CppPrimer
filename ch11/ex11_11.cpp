//
//  ex11_11.cpp
//  Exercise 11.11
//
//  Created by pezy on 12/15/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Redefine bookstore without using decltype.

#include <set>
#include "Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn()<rhs.isbn();
}

int main()
{
    using compareType= bool (*)(const Sales_data&, const Sales_data&);
    //typedef bool (*compareType)(const Sales_data&, const Sales_data&);
    multiset<Sales_data, compareType> bookstore(compareIsbn);
}
