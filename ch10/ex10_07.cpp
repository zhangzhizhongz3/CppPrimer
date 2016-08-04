//
//  ex10_07.cpp
//  Exercise 10.7
//
//  Created by pezy on 12/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Determine if there are any errors in the following programs and, if
//  so, correct the error(s)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <typename Sequence>
void print(const Sequence &seq)
{
    for(const auto &i:seq)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    // (a)
    vector<int> vec;
    list<int> lst;
    int i;
    while(cin>>i)
        lst.push_back(i);
    vec.resize(lst.size());
    // ^ Fixed: added this statement
    // Cause Algorithms that write to a destination iterator assume the
    // destination is large enough to hold the number of elements being written.
    copy(lst.cbegin(), lst.cend(), vec.begin());
    // another way to fix bug
    //copy(lst.cbegin(), lst.cend(), back_inserter(vec));

    // (b)
    vector<int> vec2;
    vec2.reserve(10);
    fill_n(vec2.begin(), 10, 0);
    // No error, but not any sense. vec2.size() still equals zero.
    // ^ Fixed: 1. use 'vec2.resize(10);'
    //       or 2. use 'fill_n(back_inserter(vec2), 10, 0);'

    print(vec);
    print(vec2);
}
