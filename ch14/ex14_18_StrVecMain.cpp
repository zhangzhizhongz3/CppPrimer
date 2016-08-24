#include <iostream>
#include <vector>
#include "ex14_18_StrVec.h"
using namespace std;

int main()
{
    StrVec vec;
    vec.reserve(6);
    cout << "capacity(reserve to 6): " << vec.capacity() << endl;

    vec.reserve(4);
    cout << "capacity(reserve to 4): " << vec.capacity() << endl;

    vec.push_back("hello");
    vec.push_back("world");

    vec.resize(4);

    for (auto i = vec.begin(); i != vec.end(); ++i)
        cout << *i << endl;
    cout << "-EOF-" << endl;

    vec.resize(1);

    for (auto i = vec.begin(); i != vec.end(); ++i)
        cout << *i << endl;
    cout << "-EOF-" << endl;

    StrVec vec_list{"hello", "world", "pezy"};

    for (auto i = vec_list.begin(); i != vec_list.end(); ++i)
        cout << *i << " ";
    cout << endl;

    // Test operator==
    const StrVec const_vec_list{"hello", "world", "pezy"};
    if (vec_list == const_vec_list)
        for (const auto& str : const_vec_list)
            cout << str << " ";
    cout << endl;

    // Test operator<
    const StrVec const_vec_list_small{"hello", "pezy", "ok"};
    cout << boolalpha<<(const_vec_list_small < const_vec_list) << endl;
}
