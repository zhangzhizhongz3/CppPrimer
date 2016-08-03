//
//  ex10_05.cpp
//  Exercise 10.5
//
//  Created by pezy on 11/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  In the call to equal on rosters, what would happen if both rosters
//          held C-style strings, rather than library strings?
//  @Answer It's not quite the same as `std::string`
//          Maybe the function 'equal' return true when you make a comparison between 
//          two C-style strings containers. Nonetheless, we need to keep in mind that 
//          when it comes to comparison of C-style strings, we need to use 'strcmp' but 
//          not simply relational operators, for using relational operators is just 
//          comparison between the address of two C-style strings but not their values.


#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
    char c1[10]="zhang";
    char c2[10]="zhang";
    vector<char*> roster1{c1};
    list<char*> roster2{c2};
    cout<<equal(roster1.cbegin(), roster1.cend(), roster2.cbegin())<<endl;
}

// clang 3.5.0
// out
// 0
