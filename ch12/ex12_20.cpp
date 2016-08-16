//
//  ex12_20.cpp
//  Exercise 12.20
//
//  Created by pezy on 12/26/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program that reads an input file a line at a time into
//  a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.

#include <iostream>
#include <fstream>
#include "ex12_19.h"

using namespace std;

int main()
{
    ifstream ifs("E:\\zzz.txt");
    StrBlob sb;
    string s;
    while(getline(ifs, s))
        sb.push_back(s);
    for(StrBlobPtr sbp=sb.begin(); sbp!=sb.end(); sbp.incr())
        cout<<sbp.deref()<<endl;
}
