//! @Yue Wang
//!
//! Exercise 10.13:
//! The library defines an algorithm named partition that takes a predicate
//! and partitions the container so that values for which the predicate is
//! true appear in the first part and those for which the predicate is false
//! appear in the second part. The algorithm returns an iterator just past
//! the last element for which the predicate returned true. Write a function
//! that takes a string and returns a bool indicating whether the string has
//! five characters or more. Use that function to partition words. Print the
//! elements that have five or more characters.
//!

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool predicate(const string &s)
{
    return s.size()>=5;
}

int main()
{
    auto svec=vector<string>{"a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa"};
    auto pivot=partition(svec.begin(), svec.end(), predicate);

    for(auto it=svec.cbegin(); it!=pivot; ++it)
        cout<<*it<<" ";
    cout<<endl;
}
