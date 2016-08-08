//!
//! @author @Yue Wang @shbling
//!
//! Exercise 10.24:
//! Use bind and check_size to find the first element in a vector of ints that
//! has a value greater than the length of a specified string value.
//!

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size()<sz;
}

vector<int>::const_iterator find_first_bigger(const vector<int> &v, const string &s)
{
    return find_if(v.cbegin(), v.cend(), bind(check_size, s, _1));
}

int main()
{
    vector<int> v{3,2,5,0,6,5,3,9,5};
    string s("test");
    cout<<*find_first_bigger(v, s)<<endl;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, int i)
{
    return s.size()<i;
}

int main()
{
    vector<int> v{3,2,5,0,3,5,3,9,5};
    cout<<*find_if(v.cbegin(), v.cend(), bind(check_size, "test", _1))<<endl;
}
