//! @Alan
//!
//! Exercise 11.3:
//! Write your own version of the word counting program.
//!
//! Exercise 11.4:
//! Extend your program to ignore case and punctuation.
//! For example, “example.” “example,” and “Example” should
//! all increment the same counter.
//!

#include <iostream>
#include <map>
#include <string>
#include <cstddef>
#include <cctype>
#include <algorithm>

using namespace std;

//! Exercise 11.3
void word_count()
{
    map<string, size_t> word_count;
    string word;

    cin.clear();
    while(cin>>word)
        ++word_count[word];

    for(const auto &elem:word_count)
        cout<<elem.first<<" : "<<elem.second<<endl;
}

//! Exercise 11.4
void word_count_pro(map<string, size_t> &m)
{
    string word;

    cin.clear();
    while(cin>>word)
    {
        for(auto &ch:word)
            ch=tolower(ch);
        word.erase(remove_if(word.begin(), word.end(), [](const char &ch) {return ispunct(ch);}), word.end());

        ++m[word];
    }

    for(const auto &e:m)
        cout<<e.first<<" : "<<e.second<<endl;
}

int main()
{
    word_count();

    map<string, size_t> m;
    word_count_pro(m);
}
