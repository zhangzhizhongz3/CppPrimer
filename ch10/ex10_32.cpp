//
//  ex10_32.cpp
//  Exercise 10.32
//
//  Created by pezy on 12/13/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Rewrite the bookstore program from 1.6 (p. 24) using a vector to hold the
//  transactions and various algorithms to do the processing.
//  Use sort with your compareIsbn function from 10.3.1 (p. 387) to arrange the
//  transactions in order, and then use find and accumulate to do the sum.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "Sales_item.h"
#include "Version_test.h"
using namespace std;

int main()
{
    istream_iterator<Sales_item> in_iter(cin), in_eof;
    vector<Sales_item> vec;
    while(in_iter!=in_eof)
        vec.push_back(*in_iter++);

    sort(vec.begin(), vec.end(), [](const Sales_item &lhs, const Sales_item &rhs) {return lhs.isbn()<rhs.isbn();});

    for(auto beg=vec.cbegin(), end=beg; beg!=vec.cend(); beg=end)
    {
        end=find_if(beg, vec.cend(), [beg](const Sales_item &item) {return item.isbn()!=beg->isbn();});
        cout<<accumulate(beg, end, Sales_item(beg->isbn()))<<endl;
    }
}
