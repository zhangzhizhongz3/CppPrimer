//
//  ex8_13.cpp
//  Exercise 8.13
//
//  Created by pezy on 11/29/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the phone number program from this section to read from
//          a named file rather than from cin.
//  @See    ex8_11.cpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::isdigit;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string &str)
{
    return isdigit(str[0]);
}

string format(const string &str)
{
    return str.substr(0,3)+"-"+str.substr(3,3)+"-"+str.substr(6);
}

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    ifstream input("E:\\zzz.txt");
    if(input)
    {
        while(getline(input, line))
        {
            PersonInfo info;
            record.clear();
            record.str(line);
            record>>info.name;
            while(record>>word)
                info.phones.push_back(word);
            people.push_back(info);
        }
    }
    else
    {
        cerr<<"no phone numbers?"<<endl;
        return -1;
    }

    for(const auto &entry:people)
    {
        ostringstream formatted, badNums;
        for(const auto &nums:entry.phones)
        {
            if(!valid(nums))
            {
                badNums<<" "<<nums;
            }
            else
                formatted<<" "<<format(nums);
        }
        if(badNums.str().empty())
            cout<<entry.name<<" "<<formatted.str()<<endl;
        else
            cerr<<"input error: "<<entry.name<<" invalid number(s) "<<badNums.str()<<endl;
    }

}
