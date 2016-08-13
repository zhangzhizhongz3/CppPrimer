//
//  ex11_38.cpp
//  Exercise 11.38
//
//  Created by pezy on 12/18/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Rewrite the word counting (11.1, p. 421) and word transformation (11.3.6, p. 440) programs to use an unordered_map.

#include <iostream>
#include <string>
#include <cstddef>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

void wordCounting()
{
    unordered_map<string, size_t> word_count;
    for(string word; cin>>word; ++word_count[word])
        ;
    for(const auto &w:word_count)
        cout<<w.first<<" occurs "<<w.second<<((w.second>1)?" times":" time")<<endl;
}

void wordTransformation()
{
    ifstream ifs_map("E:\\1.txt"), ifs_content("E:\\2.txt");
    if(!ifs_map||!ifs_content)
    {
        cerr<<"can't find the documents"<<endl;
        return;
    }

    unordered_map<string, string> trans_map;
    for(string key, value; ifs_map>>key&&getline(ifs_map, value); )
        if(value.size()>1)
            trans_map[key]=value.substr(1).substr(0, value.find_last_not_of(' '));

    for(string text, word; getline(ifs_content, text); cout<<endl)
        for(istringstream iss(text); iss>>word; )
        {
            auto map_it=trans_map.find(word);
            cout<<((map_it==trans_map.cend()) ? word : map_it->second)<<" ";
        }
}

int main()
{
    //wordCounting();
    wordTransformation();
}
