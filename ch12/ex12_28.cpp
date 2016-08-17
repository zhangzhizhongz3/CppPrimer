//
//  ex12_28.cpp
//  Exercise 12.28
//
//  Created by pezy on 1/1/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Write a program to implement text query without defining classes to manage
//  the data.
//  Your program should take a file and interact with a user to query for words
//  in that file.
//  Use vector, map, and set containers to hold the data for the file and
//  to generate the results for the query.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

int main()
{
    ifstream infile("E:\\zzz.txt");
    vector<string> file;
    map<string, set<decltype(file.size())>> wm;
    string line;
    while(getline(infile, line))
    {
        file.push_back(line);
        int n=file.size()-1;
        istringstream in(line);
        string text, word;
        while(in>>text)
        {
            remove_copy_if(text.begin(), text.end(), back_inserter(word), [](const char &ch) {return ispunct(ch);});
            wm[word].insert(n);
            word.clear();
        }
    }

    while(true)
    {
        cout<<"enter word to look for, or q to quit: ";
        string s;
        if(!(cin>>s)||s=="q")
            break;
        auto loc=wm.find(s);
        if(loc!=wm.end())
        {
            cout<<s<<" ocurrs "<<loc->second.size()<<(loc->second.size()>1?" times":" time")<<endl;
            for(auto num:loc->second)
                cout<<"\t(line "<<num+1<<")"<<file.at(num)<<endl;
        }
        else
            cout<<s<<" ocurrs 0 time"<<endl;
    }
}
