#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include "ex13_40.h"
using namespace std;

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data=alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if(elements)
    {
        for(auto p=first_free; p!=elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap-elements);
    }
}

void StrVec::range_initialize(const string *first, const string *last)
{
    auto newdata=alloc_n_copy(first, last);
    elements=newdata.first;
    first_free=cap=newdata.second;
}

StrVec::StrVec(const StrVec &s)
{
    range_initialize(s.begin(), s.end());
}

StrVec::StrVec(initializer_list<string> il)
{
    range_initialize(il.begin(), il.end());
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data=alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}

void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata=alloc.allocate(new_cap);
    auto dest=newdata;
    auto elem=elements;
    for(size_t i=0; i!=size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements=newdata;
    first_free=dest;
    cap=elements+new_cap;
}

void StrVec::reallocate()
{
    auto newcapacity=size() ? 2*size() : 1;
    alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t new_cap)
{
    if(new_cap<=capacity())
        return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
    resize(count, string());
}

void StrVec::resize(size_t count, const string &s)
{
    if(count>size())
    {
        if(count>capacity())
            reserve(2*count);
        for(size_t i=size(); i!=count; ++i)
            alloc.construct(first_free++, s);
    }
    else if(count<size())
    {
        while(first_free!=elements+count)
            alloc.destroy(--first_free);
    }
}
