//
//  ex10_25.cpp
//  Exercise 10.25
//
//  Created by pezy on 12/11/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  In the exercises for 10.3.2 (p.392) you wrote a version of biggies
//          that uses partition.
//          Rewrite that function to use check_size and bind.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

void elimdups(vector<string> &svec)
{
    sort(svec.begin(), svec.end());
    svec.erase(unique(svec.begin(), svec.end()), svec.end());
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size()>=sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimdups(words);

    auto iter=partition(words.begin(), words.end(), bind(check_size, _1, sz));

    for_each(words.begin(), iter, [](const string &s) {cout<<s<<" ";});
}

int main()
{
    vector<string> svec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    biggies(svec, 4);
    cout<<endl;
}

//  @Out
//  turtle jumps over quick slow
