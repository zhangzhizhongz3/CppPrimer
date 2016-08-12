//
//  ex11_23.cpp
//  Exercise 11.23
//
//  Created by pezy on 12/16/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Rewrite the map that stored vector of children’s names with a key that is
//  the family last name for the exercises in 11.2.1 (p. 424) to use a multimap.

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    multimap<string, string> families;
    for(string lastName, childName; cin>>childName>>lastName; families.emplace(lastName, childName))
        ;

    for(const auto &e:families)
        cout<<e.second<<" "<<e.first<<endl;
}
