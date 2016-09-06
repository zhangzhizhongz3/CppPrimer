//!
//! Exercise 14.38:
//! Write a class that tests whether the length of a given string matches a
//! given bound. Use that object to write a program to report how many words
//! in an input file are of sizes 1 through 10 inclusive.
//!
//! Exercise 14.39:
//! Revise the previous program to report the count of words that are sizes
//! 1 through 9 and 10 or more.
//!

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class BoundTest {
public:
    BoundTest(size_t l=0, size_t u=0) : lower(l), upper(u) {}
    bool operator()(const string &s)
    {
        return lower<=s.length()&&s.length()<=upper;
    }
private:
    size_t lower;
    size_t upper;
};

int main()
{
    ifstream fin("E:\\zzz.txt");
    size_t quantity9=0, quantity10=0;
    BoundTest test9(1, 9);
    BoundTest test10(1, 10);

    for(string word; fin>>word; )
    {
        if(test9(word))
            ++quantity9;
        if(test10(word))
            ++quantity10;
    }
    cout<<quantity9<<", "<<quantity10<<endl;
}
