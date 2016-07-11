//
//  ex7_03.cpp
//  Exercise 7.03
//
//  Created by pezy on 14/11/8.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#include "ex7_02.h"
#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    Sales_data total;
    double price;
    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue=total.units_sold*price;
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue=trans.units_sold*price;
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                cout << total.bookNo << " " << total.units_sold << " "
                     << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue
             << endl;
    }
    else {
        cerr << "No data?!" << endl;
        return -1;
    }

    return 0;
}
