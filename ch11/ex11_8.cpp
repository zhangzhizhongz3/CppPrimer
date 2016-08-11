//! @Alan
//!
//! Exercise 11.8:
//! Write a program that stores the excluded words in a vector
//! instead of in a set. What are the advantages to using a set?
//!

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> exclude={"aa", "bb", "cc"};
    for(string word; cin>>word; )
    {
        if(find(exclude.begin(), exclude.end(), word)!=exclude.end())
            cout<<"excluded!"<<endl;
        else
            exclude.push_back(word);
    }

    for(const auto &s:exclude)
        cout<<s<<" ";
    cout<<endl;
}
