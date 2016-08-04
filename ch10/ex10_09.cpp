//!
//! @author @Yue Wang @shbling @pezy @zzzkl @Yue Wang
//! @date   01.12.2014  Jun 2015
//!
//! Exercise 10.9:
//! Implement your own version of elimDups. Test your program by printing
//! the vector after you read the input, after the call to unique, and after
//! the call to erase.
//!

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//print containers like vector, deque, list, etc.
template <typename Sequence>
auto println(const Sequence &seq) -> ostream&
{
    for(const auto &elem : seq)
        cout<<elem<<" ";
    return cout<<endl;
}

auto eliminate_duplicates(vector<string> &svec) -> vector<string>&
{
    sort(svec.begin(), svec.end());
    println(svec);

    auto new_end=unique(svec.begin(), svec.end());
    println(svec);

    svec.erase(new_end, svec.end());
    return svec;
}

int main()
{
    vector<string> svec{"a", "v", "a", "s", "v", "a", "a"};
    println(svec);
    println(eliminate_duplicates(svec));
}
