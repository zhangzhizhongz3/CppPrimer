//!
//! @author @Yue Wang @pezy
//! @date   12.10.2014
//!
//! Exercise 10.18:
//! Rewrite biggies to use partition instead of find_if.
//!
//! Exercise 10.19:
//! Rewrite the previous exercise to use stable_partition, which like
//! stable_sort maintains the original element order in the partitioned
//! sequence.
//!

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//! from ex 10.9
void elimdups(vector<string> &svec)
{
    sort(svec.begin(), svec.end());
    auto new_end=unique(svec.begin(), svec.end());
    svec.erase(new_end, svec.end());
}

//! ex10.18
void biggies_partition(vector<string> &words, vector<string>::size_type sz)
{
    elimdups(words);

    auto pivot=partition(words.begin(), words.end(), [sz](const string &s) {return s.size()>=sz;});

    for_each(words.begin(), pivot, [](const string &s) {cout<<s<<" ";});
}

//! ex10.19
void biggies_stable_partition(vector<string> &words, vector<string>::size_type sz)
{
    elimdups(words);

    auto pivot=stable_partition(words.begin(), words.end(), [sz](const string &s) {return s.size()>=sz;});

    for_each(words.begin(), pivot, [](const string &s) {cout<<s<<" ";});
}

int main()
{
    //! ex10.18
    vector<string> svec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    
    cout<<"ex10.18: ";
    vector<string> svec1(svec);
    biggies_partition(svec1, 4);
    cout<<endl;

    //! ex10.19
    cout<<"ex10.19: ";
    vector<string> svec2(svec);
    biggies_stable_partition(svec2, 4);
    cout<<endl;
}

//! output :
//!
// ex10.18: turtle jumps over quick slow
// ex10.19: jumps over quick slow turtle
