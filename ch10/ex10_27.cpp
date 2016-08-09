//
//  ex10_27.cpp
//  Exercise 10.27
//
//  Created by pezy on 12/13/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  In addition to unique, the library defines function named unique_copy that
//  takes a third iterator denoting a destination into which to copy the unique
//  elements.
//  Write a program that uses unique_copy to copy the unique elements from
//  a vector into an initially empty list.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> ivec{1, 1, 3, 3, 5, 5, 7, 7, 9};
    list<int> ilst;
    
    unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));
    for(const auto &i : ilst)
        cout<<i<<" ";
    cout<<endl;
}
