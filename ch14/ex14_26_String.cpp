#include <iostream>
#include <memory>
#include <utility>
#include <cstddef>
#include <algorithm>
#include "ex14_26_String.h"
using namespace std;

//===========================================================================
//
//		friend
//
//===========================================================================

istream& operator>>(istream& is, String& s)
{
    char c;
    while((c=is.get())!='\n')
        s.push_back(c);
    return is;
}

ostream& operator<<(ostream& os, const String& s)
{
    os<<s.c_str();
    return os;
}

bool operator==(const String& lhs, const String& rhs)
{
    return ((lhs.size()==rhs.size())&&equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const String& lhs, const String& rhs)
{
    return !(lhs==rhs);
}

bool operator<(const String& lhs, const String& rhs)
{
    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String& lhs, const String& rhs)
{
    return rhs<lhs;
}

bool operator<=(const String& lhs, const String& rhs)
{
    return !(rhs<lhs);
}

bool operator>=(const String& lhs, const String& rhs)
{
    return !(lhs<rhs);
}

//===========================================================================
//
//		constructor
//
//===========================================================================

String::String(const char* c)
{
    auto cl=c;
    while(*cl)
        ++cl;
    range_initialize(c, ++cl);
}

//===========================================================================
//
//		copy control
//
//===========================================================================

String::String(const String& s)
{
    range_initialize(s.elements, s.first_free);
}

String& String::operator=(const String& rhs)
{
    auto newstr=alloc_n_copy(rhs.elements, rhs.first_free);
    free();
    elements=newstr.first;
    first_free=cap=newstr.second;
    last_elem=first_free-1;
    return *this;
}

String::String(String&& s) noexcept : elements(s.elements), last_elem(s.last_elem), first_free(s.first_free), cap(s.cap)
{
    s.elements=s.last_elem=s.first_free=s.cap=nullptr;
}

String& String::operator=(String&& rhs) noexcept
{
    if(this!=&rhs)
    {
        free();
        elements=rhs.elements;
        last_elem=rhs.last_elem;
        first_free=rhs.first_free;
        cap=rhs.cap;
        rhs.elements=rhs.last_elem=rhs.first_free=rhs.cap=nullptr;
    }
    return *this;
}

String::~String()
{
    free();
}

//===========================================================================
//
//		member
//
//===========================================================================

void String::push_back(const char& c)
{
    chk_n_alloc();
    *last_elem=c;
    last_elem=first_free;
    alloc.construct(first_free++, '\0');
}

void String::reserve(size_t new_cap)
{
    if(new_cap<=capacity())
        return;
    alloc_n_move(new_cap);
}

void String::resize(size_t count)
{
    resize(count, ' ');
}

void String::resize(size_t count, const char& c)
{
    if(count>size())
    {
        if(count>capacity())
            reserve(2*count);
        for(size_t i=size(); i!=count; ++i)
        {
            *last_elem++=c;
            alloc.construct(first_free++, '\0');
        }
    }
    else if(count<size())
    {
        while(last_elem!=elements+count)
        {
            --last_elem;
            alloc.destroy(--first_free);
        }
        *last_elem='\0';
    }
}

pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
    auto str=alloc.allocate(e-b);
    return {str, uninitialized_copy(b, e, str)};
}

void String::range_initialize(const char* first, const char* last)
{
    auto newstr=alloc_n_copy(first, last);
    elements=newstr.first;
    first_free=cap=newstr.second;
    last_elem=first_free-1;
}

void String::free()
{
    if(elements)
    {
        for_each(elements, first_free, [this](char& c) {alloc.destroy(&c);});
        alloc.deallocate(elements, cap-elements);
    }
}

void String::reallocate()
{
    auto newcapacity=size() ? 2*(size()+1) : 2;
    alloc_n_move(newcapacity);
}

void String::alloc_n_move(size_t new_cap)
{
    auto newdata=alloc.allocate(new_cap);
    auto dest=newdata;
    auto elem=elements;
    for(size_t i=0; i!=size()+1; ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements=newdata;
    last_elem=dest-1;
    first_free=dest;
    cap=elements+new_cap;
}
