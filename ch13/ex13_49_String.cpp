#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include "String.h"
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
    char *sl=const_cast<char*>(s);
    while(*sl)
        ++sl;
    range_initialize(s, ++sl);
}

String::String(const String &s)
{
    range_initialize(s.elements, s.end);
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
    return *this;
}

String::String(String &&s) noexcept : elements(s.elements), end(s.end)
{
    s.elements=s.end=nullptr;
}

String &String::operator=(String &&rhs) noexcept
{
    if(this!=&rhs)
    {
        free();
        elements=rhs.elements;
        end=rhs.end;
        rhs.elements=rhs.end=nullptr;
    }
    return *this;
}
