//! @author @shbling @Alan
//!
//! Exercise 9.13:
//! How would you initialize a vector<double> from a list<int>?
//! From a vector<int>?
//! Write code to check your answers.
//!

#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

int main()
{
    list<int> ilst(5,4);
    vector<int> ivec(5,5);

    //!from list<int> to vector<double>
    vector<double> dvec(ilst.begin(), ilst.end());
    for(auto i:ilst)
        cout<<i<<" ";
    cout<<endl;
    for(auto d:dvec)
        cout<<d<<" ";
    cout<<endl;

    //!from vector<int> to vector<double>
    vector<double> dvec2(ivec.begin(), ivec.end());
    for(auto i:ivec)
        cout<<i<<" ";
    cout<<endl;
    for(auto d:dvec2)
        cout<<d<<" ";
    cout<<endl;
}
