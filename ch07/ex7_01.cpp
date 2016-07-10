//
//  ex7_01.cpp
//  Exercise 7.1
//
//  Created by pezy on 14/10/30.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total;
    double price;
    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue=total.units_sold*price;
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue=trans.units_sold*price;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else {
                cout << total.bookNo << " " << total.units_sold << " "
                     << total.revenue << endl;
                total.bookNo=trans.bookNo;
                total.units_sold=trans.units_sold;
                total.revenue=trans.revenue;
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
