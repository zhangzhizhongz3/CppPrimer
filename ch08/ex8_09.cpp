//
//  ex8_09.cpp
//  Exercise 8.9
//
//  Created by pezy on 11/29/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Use the function you wrote for the first exercise in § 8.1.2 (p.314)
//          to print the contents of an istringstream object.
//  @See    Exercise 8.1

#include <iostream>
#include <string>
#include <sstream>

std::istream &func(std::istream &is)
{
    std::string word;
    while(is>>word)
    {
        std::cout<<word<<" ";
    }
    is.clear();
    return is;
}

int main()
{
   std::istringstream line("zhang zhi zhong");
   func(line);
}
