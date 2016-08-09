//
//  ex10_30.cpp
//  Exercise 10.30
//
//  Created by pezy on 12/13/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Use stream iterators, sort, and copy to read a sequence of integers from the
//  standard input, sort them, and then write them back to the standard output.

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
    copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
}
