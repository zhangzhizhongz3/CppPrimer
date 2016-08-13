//
//  ex11_33.cpp
//  Exercise 11.33
//
//  Created by pezy on 12/18/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Implement your own version of the word transformation program.

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    for(string key, value; map_file>>key&&getline(map_file, value); )
        if(value.size()>1)
            trans_map[key]=value.substr(1).substr(0, value.find_last_not_of(' '));
    return trans_map;
}

const string &stransform(const string &s, const map<string, string> &m)
{
    auto map_it=m.find(s);
    return (map_it==m.cend()) ? s : map_it->second;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map=buildMap(map_file);
    for(string text; getline(input, text); )
    {
        istringstream iss(text);
        for(string word; iss>>word; )
            cout<<stransform(word, trans_map)<<" ";
        cout<<endl;
    }
}

int main()
{
    ifstream ifs_map("E:\\1.txt"), ifs_content("E:\\2.txt");
    if(ifs_map&&ifs_content)
        word_transform(ifs_map, ifs_content);
    else
        cerr<<"can't find the documents"<<endl;
}
