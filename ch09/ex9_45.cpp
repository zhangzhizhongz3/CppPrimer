//! @author @TungWah @Alan
//! @date   4 Oct,2014.
//!
//! Exercise 9.45:
//! Write a funtion that takes a string representing a name and two other
//! strings representing a prefix, such as “Mr.” or “Ms.” and a suffix,
//! such as “Jr.” or “III”. Using iterators and the insert and append functions,
//! generate and return a new string with the suffix and prefix added to the
//! given name.
//!

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

string &pre_suffix(string &name, const string &pre, const string &suf)
{
    name.insert(name.begin(), pre.begin(), pre.end());
    name.append(suf);
    return name;
}

int main()
{
    string name("zhang");
    cout << pre_suffix(name, "Mr.", "Jr.") << endl;
}
