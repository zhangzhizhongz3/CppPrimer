//!
//! @author @Yue Wang @shbling @pezy @zzzkl
//! @date   02.12.2014
//!
//! Exercise 10.20:
//! The library defines an algorithm named count_if. Like find_if, this function
//! takes a pair of iterators denoting an input range and a predicate that it applies
//! to each element in the given range. count_if returns a count of how often the
//! predicate is true. 
//! Use count_if to rewrite the portion of our program that counted how
//! many words are greater than length 6.
//!
//! Exercise 10.21:
//! Write a lambda that captures a local int variable and decrements that
//! variable until it reaches 0. Once the variable is 0 additional calls should 
//! no longer decrement the variable. The lambda should return a bool that indicates 
//! whether the captured variable is 0.
//!

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//! Exercise 10.20
size_t bigerThan6(const vector<string> &svec)
{
    return count_if(svec.cbegin(), svec.cend(), [](const string &s) {return s.size()>6;});
}

int main()
{
    //! ex10.20
    vector<string> v{"alan", "moophy", "1234567", "1234567","1234567", "1234567"};
    cout<<"ex10.20: "<<bigerThan6(v)<<endl;

    //! ex10.21
    int i=7;
    auto check_and_decrement=[&i] {return --i ? false : true;};
    cout<<"ex10.21: ";
    while(!check_and_decrement())
        cout<<i<<" "    ;
    cout<<i<<endl;
}

//! output:
//!
// ex10.20: 4
// ex10.21: 6 5 4 3 2 1 0
