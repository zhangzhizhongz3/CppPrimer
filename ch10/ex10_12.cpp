//! @Yue Wang
//! Exercise 10.12:
//! Write a function named compareIsbn that compares the isbn members of two
//! Sales_data objects.
//! Use that function to sort a vector that holds Sales_data objects.
//!

#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_data.h" //Sales_data class

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn().size()<rhs.isbn().size();
}

int main()
{
    Sales_data d1{"aa"}, d2{"aaaa"}, d3{"aaa"}, d4{"z"}, d5{"aaaaz"};
    vector<Sales_data> svec{d1, d2, d3, d4, d5};

    // @note the elements the iterators pointing to
    //       must match the parameters of the predicate
    sort(svec.begin(), svec.end(), compareIsbn);

    for(const auto &element : svec)
        cout<<element.isbn()<<" ";
    cout<<endl;
}
