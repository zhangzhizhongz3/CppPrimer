//
//  ex9_46.cpp
//  Exercise 9.46
//
//  Created by pezy on 12/5/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the previous exercise using a position and length to manage
//  the strings. This time use only the insert function.
//  @See    9.45

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

string &pre_suffix(string &name, const string &pre, const string &suf)
{
    name.insert(0, pre);
    name.insert(name.size(), suf);
    return name;
}

int main()
{
    string name("zhang");
    cout << pre_suffix(name, "Mr.", "Jr.") << endl;
}
