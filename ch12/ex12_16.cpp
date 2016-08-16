//
//  ex12_15.cpp
//  Exercise 12.15
//
//  Created by pezy on 12/22/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Compilers don’t always give easy-to-understand error messages if we attempt
//  to copy or assign a unique_ptr. Write a program that contains these errors 
//  to see how your compiler diagnoses them.

#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<string> p1(new string("pezy"));
    // unique_ptr<string> p2(p1);   //copy
    //                      ^
    // Error: Call to implicitly-deleted copy constructor of 'unique_ptr<string>'
    //
    // unique_ptr<string> p3;
    // p3=p1;                       //assign
    //   ^
    // Error: Call to implicitly-deleted copy constructor of 'unique_ptr<string>'
    cout<<*p1<<endl;
    p1.reset(nullptr);
}
