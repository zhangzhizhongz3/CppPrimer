//! @Alan
//!
//! Exercise 11.24:
//! What does the following program do?
//!     map<int, int> m;
//!     m[0] = 1;
//  add a key-value pair {0,1} into the map
//!
//! Exercise 11.25:
//! Contrast the following program with the one in the previous exercise
//!     vector<int> v;
//!     v[0] = 1;
//  Since the vector v is empty, the subsript operator [0] can not access v[0].
//  Thus, the statement v[0] = 1; is meaningless.
//!
//! Exercise 11.26:
//! What type can be used to subscript a map? What type does the subscript
//! operator return? Give a concrete example—that is, define a map and then
//! write the types that can be used to subscript the map and the type that
//! would be returned from the subscript operator.
//!

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //! ex11.24
    map<int, int> m;
    m[0]=1;

    for(const auto &e:m)
        cout<<e.first<<" "<<e.second<<endl;

    //! ex11.25
    vector<int> v;
    v[0]=1;

    for(const auto &e:v)
        cout<<e<<endl;

    //! ex11.26
    map<int, string> imap={{1, "ss"}, {2, "sz"}};

    map<int, string>::key_type type_to_subscript=1;
    //! that is, int

    map<int, string>::mapped_type type_to_return=imap[type_to_subscript];
    //! that is, string
}
