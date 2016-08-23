#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include "ex13_44_47.h"
using namespace std;

pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
    auto str=alloc.allocate(e-b);
    return {str, uninitialized_copy(b, e, str)};
}

void String::range_initialize(const char *first, const char *last)
{
    auto newstr=alloc_n_copy(first, last);
    elements=newstr.first;
    end=newstr.second;
}

String::String(const char *s)
{
    auto sl=s;
    while(*sl)
        ++sl;
    range_initialize(s, ++sl);
}

String::String(const String &s)
{
    range_initialize(s.elements, s.end);
    cout<<"copy constructor"<<endl;
}


void String::free()
{
    if(elements)
    {
        for_each(elements, end, [this](char &c) {alloc.destroy(&c);});
        alloc.deallocate(elements, end-elements);
    }
}

String::~String()
{
    free();
}

String &String::operator=(const String &rhs)
{
    auto newstr=alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements=newstr.first;
    end=newstr.second;
    cout<<"copy-assignment operator"<<endl;
    return *this;
}
