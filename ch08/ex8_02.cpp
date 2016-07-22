//
//  ex8_02.cpp
//  Exercise 8.2
//
//  Created by pezy on 11/27/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief test your function by calling it, passing cin as an argument

#include <iostream>
#include <string>

std::istream &func(std::istream &is)
{
    std::string s;
    while(is>>s)
    {
        std::cout<<s<<" ";
    }
    is.clear();
    return is;
}

int main()
{
    std::istream &is = func(std::cin);
    std::cout << is.rdstate() << std::endl;
}
