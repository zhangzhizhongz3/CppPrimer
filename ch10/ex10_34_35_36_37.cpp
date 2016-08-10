//!
//! Exercise 10.34:
//! User reverse_iterator to print a vector in reverse order.
//!
//! Exercise 10.35:
//! Now print the elements in reverse order using ordinary iterator.
//!
//! Exercise 10.36:
//! Use find to find the last element in a list of ints with value 0.
//!
//! Exercise 10.37:
//! Given a vector that has ten elements, copy the elements from position
//! 3 through 7 in reverse order to a list.
//!

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

//! Exercise 10.34
void r_print(const vector<string> &v);

//! Exercise 10.35
void r_withOrdinary_print(const vector<string> &v);

//! Exercise 10.36
list<int>::iterator find_last_0(list<int> &l);

//! Exercise 10.37
void vec2list_3_7_reverse(const vector<int> &v, list<int> &l);

int main()
{
    vector<string> v={"aa", "bb", "cc"};

    //! test for 10.34
    r_print(v);
    cout<<endl;

    //! test for 10.35
    r_withOrdinary_print(v);
    cout<<endl;

    //! test for 10.36
    list<int> l={1,2,3,4,0,5,6};
    auto it=find_last_0(l);
    cout<<*it<<endl;

    //! test for 10.37
    vector<int> vi={1,2,3,4,5,6,7,8,9,10};
    list<int> lst;
    vec2list_3_7_reverse(vi, lst);
    for(const auto &e : lst)
        cout<<e<<" ";
    cout<<endl;
}

//! Exercise 10.34
inline void r_print(const vector<string> &v)
{
    for_each(v.crbegin(), v.crend(), [](const string &s) {cout<<s<<" ";});
}

//! Exercise 10.35
inline void r_withOrdinary_print(const vector<string> &v)
{
    for(auto it=prev(v.cend()); it!=prev(v.cbegin()); --it)
        cout<<*it<<" ";
}

//! Exercise 10.36
//! @note   reverse iterator can not convert to ordinary directly
//!         it may be done via the member base().
//!         不能用const list<int> &l，也不能用l.crbegin()，l.crend()，
//!         因为prev(it)相当于--it要改变it，所以不能
inline list<int>::iterator find_last_0(list<int> &l)
{
    //! assuming: 1 2 3 4 0 5 6

    //! 1 2 3 4 0 5 6
    //!         ^
    //! to which r_it refer.
    auto r_it=find(l.rbegin(), l.rend(), 0);

    //! 1 2 3 4 0 5 6
    //!           ^
    //! to which it refer.
    auto it=r_it.base();

    //! 1 2 3 4 0 5 6
    //!         ^
    //! to which --it refer.
    return prev(it);
}

//! Exercise 10.37:
//! Given a vector that has ten elements, copy the elements from position
//! 3 through 7 in reverse order to a list.
inline void vec2list_3_7_reverse(const vector<int> &v, list<int> &l)
{
    //!     1 2 3 4 5 6 7 8 9 10
    //!    ^                  ^^
    //! crend                 crbegin
    copy(v.crbegin()+3, v.crbegin()+8, back_inserter(l));
    //!                       ^
    //! @note: copy copies the range [first, last) into result.
    //!        hence, the arguments here denote:
    //!        [7 6 5 4 3 2)
    //!                   ^ this one is specified but not included.
}
