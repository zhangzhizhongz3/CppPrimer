//
//  ex12_23.cpp
//  Exercise 12.23
//
//  Created by pezy on 12/30/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program to concatenate two string literals, putting the result in a
//  dynamically allocated array of char.
//  Write a program to concatenate two library strings that have the same value
//  as the literals used in the first program.

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    //dynamically allocated array of char
    char *concatenate_string=new char[255]();
    strcat(concatenate_string, "hello");
    strcat(concatenate_string, "world");
    cout<<concatenate_string<<endl;
    delete [] concatenate_string;

    //string
    string str1{"hello"}, str2{"world"};
    cout<<str1+str2<<endl;
}
