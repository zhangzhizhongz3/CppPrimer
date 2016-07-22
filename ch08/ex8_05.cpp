//
//  ex8_05.cpp
//  Exercise 8.5
//
//  Created by pezy on 11/9/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the previous program to store each word in a separate element.
//  @See    ex8_04.cpp

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
        while(input>>s)
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
