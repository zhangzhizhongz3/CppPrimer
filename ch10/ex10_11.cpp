//! @Alan
//! Exercise 10.11:
//! Write a program that uses stable_sort and isShorter to sort a vector passed
//! to your version of elimDups.
//! Print the vector to verify that your program is correct.
//!

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//! print a container like vector, deque, list, etc.
template <typename Sequence>
inline void println(const Sequence &seq)
{
    for(const auto &elem : seq)
        cout<<elem<<" ";
    cout<<endl;
}

inline bool is_shorter(const string &lhs, const string &rhs)
{
    return lhs.size()<rhs.size();
}

void elimdups(vector<string> &svec)
{
    sort(svec.begin(), svec.end());
    auto new_end=unique(svec.begin(), svec.end());
    svec.erase(new_end, svec.end());
}

int main()
{
    vector<string> svec{"1234", "1234", "1234", "Hi", "alan", "wang"};
    elimdups(svec);
    stable_sort(svec.begin(), svec.end(), is_shorter);
    cout<<"ex10.11 :\n";
    println(svec);
}

//! output
// ex10.11 :
// Hi 1234 alan wang
