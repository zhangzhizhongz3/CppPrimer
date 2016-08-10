//! @Alan @pezy
//!
//! Exercise 10.42:
//! Reimplement the program that eliminated duplicate words that
//! we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.
//!

#include <iostream>
#include <list>
#include <string>

using namespace std;

void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}

int main()
{
    list<string> lst{"aa", "aa", "aa", "aa", "aasss", "aa"};
    elimDups(lst);
    for(const auto &s:lst)
        cout<<s<<" ";
    cout<<endl;
}

//! output
//!
// aa aasss
