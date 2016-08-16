//
//  ex12_24.cpp
//  Exercise 12.24
//
//  Created by pezy on 12/30/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program that reads a string from the standard input into a
//  dynamically allocated character array.
//  Describe how your program handles varying size inputs.
//  Test your program by giving it a string of data that is longer than the
//  array size you've allocated.

#include <iostream>

using namespace std;

int main()
{
    //need to tell the size
    cout<<"How long do you want the string? ";
    int size{0};
    cin>>size;
    char *input=new char[size+1]();
    cin.ignore();
    cout<<"input the string: ";
    cin.get(input, size+1);
    cout<<input ;
    delete [] input;
    //Test: if longer than the array size, we will lost
    //      the characters which are out of range
}
