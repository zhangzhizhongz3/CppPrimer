//
//  ex10_06.cpp
//  Exercise 10.6
//
//  Created by pezy on 12/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Using fill_n, write a program to set a sequence of int values to 0.

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::fill_n;

int main()
{
    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fill_n(vec.begin(), vec.size(), 0);

    for(const auto &i : vec)
        cout<<i<<" ";
    cout<<endl;
}

//  @Output
//  0 0 0 0 0 0 0 0 0 0
