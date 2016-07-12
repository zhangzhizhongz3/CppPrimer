//
//  ex7_11.cpp
//  Exercise 7.11
//
//  Created by pezy on 11/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#include "ex7_11.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data item1;
    print(cout, item1) << endl;

    Sales_data item2("0-201-78345-X");
    print(cout, item2) << endl;

    Sales_data item3("0-201-78345-X", 3, 20.00);
    print(cout, item3) << endl;

    Sales_data item4(std::cin);
    print(cout, item4) << endl;

}
