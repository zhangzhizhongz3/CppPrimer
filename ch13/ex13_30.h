//
//  ex13_30.h
//  Exercise 13.30
//
//  Created by pezy on 1/23/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Write and test a swap function for your value like version of HasPtr.
//  Give your swap a print statement that notes when it is executed.
//
//  See ex13_22.h
//

#ifndef CP5_ex13_30_h
#define CP5_ex13_30_h

#include <iostream>
#include <string>
using namespace std;

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string &s=string()):ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)), i(p.i) {}
    HasPtr &operator=(const HasPtr &rhs)
    {
        auto newp=new string(*rhs.ps);
        delete ps;
        ps=newp;
        i=rhs.i;
        return *this;
    }
    ~HasPtr() {delete ps;}

private:
    string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout<<"call swap(HasPtr&, HasPtr&)"<<endl;
}

#endif
