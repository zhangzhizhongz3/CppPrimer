//
//  ex7_07.cpp
//  Exercise 7.7
//
//  Created by pezy on 11/8/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#include "ex7_06.h"
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }

    return 0;
}
