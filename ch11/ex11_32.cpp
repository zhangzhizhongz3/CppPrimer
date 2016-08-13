//
//  ex11_32.cpp
//  Exercise 11.32
//
//  Created by pezy on 12/17/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Using the multimap from the previous exercise, write a program to print the
//  list of **authors and their works** alphabetically.

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    multimap<string, string> authors={{"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"}, {"wang", "FTP"}, {"pezy", "CP5"}, {"wang", "CPP-Concurrency"}};
    map<string, multiset<string>> order_authors;
    for(const auto &author:authors)
        order_authors[author.first].insert(author.second);
    for(const auto &author:order_authors)
    {
        cout<<author.first<<": ";
        for(const auto &work:author.second)
            cout<<work<<" ";
        cout<<endl;
    }
}
