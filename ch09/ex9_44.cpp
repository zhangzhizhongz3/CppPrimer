//
//  ex9_44.cpp
//  Exercise 9.44
//
//  Created by pezy on 12/4/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the previous function using an index and replace.
//  @See    9.43

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void Replace(string &s, const string &oldVal, const string &newVal)
{
   for(string::size_type ix=0; ix!=s.size(); ++ix)
   {
       if(s.substr(ix, oldVal.size())==oldVal)
       {
           s.replace(ix, oldVal.size(), newVal);
           ix+=newVal.size()-1;
       }
   }
}

int main()
{
    string str("To drive straight thru is a foolish, tho courageous act.");
    Replace(str, "tho", "though");
    Replace(str, "thru", "through");
    cout << str << endl;
}
