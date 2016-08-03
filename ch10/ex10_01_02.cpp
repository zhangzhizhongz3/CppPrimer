//!
//! @author Yue Wang
//! @date   01.12.2014
//!
//! Exercise 10.1:
//! The algorithm header defines a function named count that, like find,
//! takes a pair of iterators and a value.count returns a count of how
//! often that value appears.
//! Read a sequence of ints into a vector and print the count of how many
//! elements have a given value.
//!
//! Exercise 10.2:
//! Repeat the previous program, but read values into a list of strings.
//!

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
    //! 10.1
    vector<int> ivec{1, 2, 3, 4, 5, 6, 6, 6, 2};
    cout<<"ex 10.01: "<<count(ivec.cbegin(), ivec.cend(), 6)<<endl;

    //! 10.2
    list<string> slst{"aa", "aaa", "aa", "cc"};
    cout<<"ex 10.02: "<<count(slst.cbegin(), slst.cend(), "aa")<<endl;
}

//! output:
//!
// ex 10.01: 3
// ex 10.02: 2
