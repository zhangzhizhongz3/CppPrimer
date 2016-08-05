//!
//! @author @Yue Wang @pezy
//! @date   02.12.2014
//!
//! Exercise 10.16:
//! Write your own version of the biggies function using lambda.
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

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimdups(words);

    //! sort by size, but maintain alphabetical order for same size
    stable_sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) {return lhs.size()<rhs.size();});

    //! get an iterator to the first one whose size() is >= sz
    auto wc=find_if(words.begin(), words.end(), [sz](const string &s) {return s.size()>=sz;});

    //! print the biggies
    for_each(wc, words.end(), [](const string &s) {cout<<s<<" ";});
}

int main()
{
    //! ex10.16
    vector<string> svec{"1234", "1234", "1234", "hi~", "alan","alan", "cp"};
    cout<<"ex10.16: ";
    biggies(svec, 3);
    cout<<endl;
}

//! output :
//!
// ex10.16: hi~ 1234 alan 
