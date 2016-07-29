//! @Alan
//!
//! Exercise 9.38:
//! Write a program to explore how vectors grow in the library you use.
//!

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> svec;
    string word;
    while(cin>>word)
    {
        svec.push_back(word);
        cout<<svec.capacity()<<endl;
    }
}
