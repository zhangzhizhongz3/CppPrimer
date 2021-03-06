//
//  ex8_11.cpp
//  Exercise 8.11
//
//  Created by pezy on 11/29/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  The program in this section defined its istringstream object inside
//          the outer while loop.
//          What changes would you need to make if record were defined outside
//          that loop?
//          Rewrite the program, moving the definition of record outside the
//          while, and see whether you thought of all the changes that are
//          needed.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while(getline(cin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record>>info.name;
        while(record>>word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for(const auto &p:people)
    {
        cout<<p.name<<" ";
        for(const auto &s:p.phones)
            cout<<s<<" ";
        cout<<endl;
    }
}
