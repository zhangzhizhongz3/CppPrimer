//
//  ex11_12_13.cpp
//  Exercise 11.12 11.13
//
//  Created by pezy on 12/15/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program to read a sequence of strings and ints,
//  storing each into a pair. Store the pairs in a vector.
//
//  There are at least three ways to create the pairs in the program for the
//  previous exercise.
//  Write three versions of that program, creating the pairs in each way.
//  Explain which form you think is easiest to write and understand, and why.

#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int main()
{
    vector<pair<string, int>> v;
    string s;
    int i;
    while(cin>>s>>i)
    {
        v.push_back(make_pair(s, i));
      //v.push_back(pair<string, int>(s, i));
      //v.push_back({s, i});
      //v.emplace_back(s, i);   //!!! easiest way
    }

    for(const auto &e:v)
        cout<<e.first<<" "<<e.second<<endl;
}
