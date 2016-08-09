//
//  ex10_28.cpp
//  Exercise 10.28
//
//  Created by pezy on 12/13/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Copy a vector that holds the values from 1 to 9 inclusive, into three other
//  containers.
//  Use an inserter, a back_inserter, and a front_inserter, respectivly to add
//  elements to these containers.
//  Predict how the output sequence varies by the kind of inserter and verify
//  your predictions by running your programs.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template <typename Sequence>
void print(const Sequence &seq)
{
    for(const auto &i : seq)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // uses inserter
    list<int> ilst1;
    copy(ivec.cbegin(), ivec.cend(), inserter(ilst1, ilst1.begin()));
    print(ilst1);

    // uses back_inserter
    list<int> ilst2;
    copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst2));
    print(ilst2);

    // uses front_inserter
    list<int> ilst3;
    copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst3));
    print(ilst3);
}
