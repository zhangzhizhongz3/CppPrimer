//
//  ex12_22.cpp
//  Exercise 12.22
//
//  Created by pezy on 12/28/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  What changes would need to be made to StrBlobPtr to create a class
//  that can be used with a const StrBlob?
//  Define a class named ConstStrBlobPtr that can point to a const StrBlob.
//
//  @See    ex12_19.h

#ifndef CP5_ex12_12_h
#define CP5_ex12_12_h

#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <memory>
#include <initializer_list>

using namespace std;

class ConstStrBlobPtr;

class StrBlob {
friend class ConstStrBlobPtr;
public:
    using size_type = vector<string>::size_type;

    StrBlob():data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)) {}

    ConstStrBlobPtr begin() const;  //should add const
    ConstStrBlobPtr end() const;    //should add const

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    string &front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    string &back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const string &front() const
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const string &back() const
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    void check(size_type i, const string &msg) const
    {
        if (i >= data->size())
            throw out_of_range(msg);
    }

    shared_ptr<vector<string>> data;
};

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr():curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz=0):wptr(a.data), curr(sz) {}    //should add const
    bool operator!=(ConstStrBlobPtr &p) { return p.curr!=curr; }
    const string &deref() const
    {   //return value should add const
        auto p=check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr &incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const
    {
        auto ret=wptr.lock();
        if(!ret)
            throw runtime_error("unbound StrBlobPtr");
        if(i>=ret->size())
            throw out_of_range(msg);
        return ret;
    }

    weak_ptr<vector<string>> wptr;
    size_t curr;
};

#endif
