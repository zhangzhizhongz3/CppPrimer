//
//  ex7_13.cpp
//  Exercise 7.13
//
//  Created by pezy on 11/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#include "ex7_12.h"
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    Sales_data total(cin);
    if (!total.isbn().empty()) {
        while (cin) {
            Sales_data trans(cin);
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }

    return 0;
}
