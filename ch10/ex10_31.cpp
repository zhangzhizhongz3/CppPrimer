//
//  ex10_31.cpp
//  Exercise 10.31
//
//  Created by pezy on 12/13/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Update the program from the previous exercise so that it prints only the
//  unique elements. Your program should use unqiue_copy.

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> ivec;
    copy(in_iter, eof, back_inserter(ivec));
    sort(ivec.begin(), ivec.end());
    unique_copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
}
