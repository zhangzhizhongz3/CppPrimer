//! @Yue Wang
//!
//! Exercise 9.50:
//! Write a program to process a vector<string> whose elements represent integral values.
//! Produce the sum of all the elements in that vector.
//! Change the program so that it sums of strings that represent floating-point values.
//!

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum_for_int(const vector<string> &svec)
{
    int sum=0;
    for(const auto &s : svec)
        sum+=stoi(s);
    return sum;

}

float sum_for_float(const vector<string> &svec)
{
    float sum=0.0;
    for(const auto &s:svec)
        sum+=stof(s);
    return sum;
}

int main()
{
    vector<string> svec{"1", "2", "3", "4.5"};
    cout<<sum_for_int(svec)<<endl;
    cout<<sum_for_float(svec)<<endl;
}
