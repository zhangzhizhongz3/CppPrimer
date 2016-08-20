//
//  ex13_31.h
//  Exercise 13.31
//
//  Created by pezy on 1/23/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Give your class a < operator and define a vector of HasPtrs.
//  Give that vector some elements and then sort the vector.
//  Note when swap is called.
//
//  See ex13_30.h
//

#ifndef CP5_ex13_31_h
#define CP5_ex13_31_h

#include <iostream>
#include <string>
using namespace std;

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
friend bool operator<(const HasPtr&, const HasPtr&);
public:
    HasPtr(const string &s=string()):ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)), i(p.i) {}
    HasPtr &operator=(HasPtr tmp)
    {
        this->swap(tmp);
        return *this;
    }
    ~HasPtr() {delete ps;}

    void swap(HasPtr &rhs)
    {
       using std::swap;
       swap(ps,rhs.ps);
       swap(i, rhs.i);
       cout<<"call swap(HasPtr&)"<<endl;
    }

    void show() const {cout<<*ps<<endl;}

private:
    string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs)
{
    lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps<*rhs.ps;
}

#endif
