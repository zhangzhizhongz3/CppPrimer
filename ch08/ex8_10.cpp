//
//  ex8_10.cpp
//  Exercise 8.10
//
//  Created by pezy on 11/29/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a program to store each line from a file in a vector<string>.
//          Now use an istringstream to read each element from the vector a word
//          at a time.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

int main()
{
    string line, word;
    vector<string>  svec;
    ifstream input("E:\\zzz.txt");
    if(input)
    {
        while(getline(input, line))
            svec.push_back(line);
        for(const auto &s : svec)
        {
            istringstream is(s);
            while(is>>word)
                cout<<word<<" ";
            cout<<endl;
        }
    }
    else
    {
        cerr<<"No data?!"<<endl;
        return -1;
    }
}
