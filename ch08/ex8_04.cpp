//
//  ex8_04.cpp
//  Exercise 8.4
//
//  Created by pezy on 11/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Write a function to open a file for input and read its contents into
//  a vector of strings, storing each line as a separate element in the vector.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::string;

void ReadFileToVec(const string &fileName, vector<string> &vec)
{
    ifstream input(fileName);
    if(input)
    {
        string s;
        while(getline(input, s))
            vec.push_back(s);
    }
}

int main()
{
    vector<string> vec;
    ReadFileToVec("E:\\zzz.txt", vec);
    for(const auto &str:vec)
        cout<<str<<endl;
}
