//
//  ex9_41.cpp
//  Exercise 9.41
//
//  Created by pezy on 12/4/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a program that initializes a string from a vector<char>.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<char> cvec{'z','h','i'};
    string s(cvec.begin(), cvec.end());
    
    cout<<s<<endl;
}
