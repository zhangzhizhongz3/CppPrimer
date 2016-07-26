//! @Alan @pezy
//!
//! Exercise 9.14:
//! Write a program to assign the elements from a list of char* (pointer
//! to C-style character strings) to a vector of string.
//!
//! @Notice C-style character strings should use const char*, otherwise warning.
//!

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
    list<const char*> lst{"zhang", "zhi", "zhong"};
    vector<string> svec;
    svec.assign(lst.cbegin(), lst.cend());
    for(const auto &s : svec)
        cout<<s<<" ";
    cout<<endl;
}

