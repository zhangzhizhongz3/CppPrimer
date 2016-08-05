//! @pezy
//!
//! Exercise 10.17
//! Rewrite exercise 10.12 from § 10.3.1 (p. 387)
//! to use a lambda in the call to sort instead of the compareIsbn function.
//!
//! @See 7.26, 10.12

#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data d1{"aa"}, d2{"aaaa"}, d3{"aaa"}, d4{"z"}, d5{"aaaaz"};
    vector<Sales_data> svec{d1, d2, d3, d4, d5};

    sort(svec.begin(), svec.end(), [](const Sales_data &lhs, const Sales_data &rhs) {return lhs.isbn().size()<rhs.isbn().size();});

    for(const auto &element : svec)
        cout<<element.isbn()<<" ";
    cout<<endl;
}
