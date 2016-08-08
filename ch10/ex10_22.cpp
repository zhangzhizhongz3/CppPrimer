//
//  ex10_22.cpp
//  Exercise 10.22
//
//  Created by pezy on 12/11/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the program to count words of size 6 or less using
//          functions in place of the lambdas.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool isSmallerThan6(const string &s, string::size_type sz)
{
    return s.size()<=sz;
}

int main()
{
    vector<string> v{"zhang", "zhizhong", "shiling", "jiang", "shuyi"};
    cout<<count_if(v.cbegin(), v.cend(), bind(isSmallerThan6, _1, 6))<<endl;
}

//  @Out
//  3
