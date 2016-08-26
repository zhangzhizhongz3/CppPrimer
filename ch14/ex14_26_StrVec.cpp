#include <string>
#include <memory>
#include <utility>
#include <cstddef>
#include <algorithm>
#include <initializer_list>
#include "ex14_26_StrVec.h"
using namespace std;

bool operator==(const StrVec& lhs, const StrVec& rhs)
{
    return ((lhs.size()==rhs.size())&&equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs==rhs);
}

bool operator<(const StrVec& lhs, const StrVec& rhs)
{
    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const StrVec& lhs, const StrVec& rhs)
{
    return rhs<lhs;
}

bool operator<=(const StrVec& lhs, const StrVec& rhs)
{
    return !(rhs<lhs);
}

bool operator>=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs<rhs);
}

StrVec::StrVec(initializer_list<string> il)
{
    range_initialize(il.begin(), il.end());
}

StrVec::StrVec(const StrVec& s)
{
    range_initialize(s.begin(), s.end());
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data=alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}

StrVec::StrVec(StrVec&& s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements=s.first_free=s.cap=nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
    if(this!=&rhs)
    {
        free();
        elements=rhs.elements;
        first_free=rhs.first_free;
        cap=rhs.cap;
        rhs.elements=rhs.first_free=rhs.cap=nullptr;
    }
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
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

void StrVec::resize(size_t count, const string& s)
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

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e)
{
    auto data=alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::range_initialize(const string* first, const string* last)
{
    auto newdata=alloc_n_copy(first, last);
    elements=newdata.first;
    first_free=cap=newdata.second;
}

void StrVec::free()
{
    if(elements)
    {
        for_each(elements, first_free, [this](string& s) {alloc.destroy(&s);});
        alloc.deallocate(elements, cap-elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity=size() ? 2*size() : 1;
    alloc_n_move(newcapacity);
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
