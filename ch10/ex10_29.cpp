//
//  ex10_29.cpp
//  Exercise 10.29
//
//  Created by pezy on 12/13/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program using stream iterators to read a text file into a vector of
//  strings.

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("E:\\zzz.txt");
    istream_iterator<string> in_iter(in), eof;
    vector<string> svec;
    copy(in_iter, eof, back_inserter(svec));

    // output
    copy(svec.cbegin(), svec.cend(), ostream_iterator<string>(cout, "\n"));
}

