//
//  ex13_27.h
//  Exercise 13.27
//
//  Created by pezy on 1/20/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Define your own reference-counted version of HasPtr.
//

#ifndef CP5_ex13_27_h
#define CP5_ex13_27_h

#include <string>
using namespace std;

class HasPtr {
public:
    HasPtr(const string &s=string()):ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &p):ps(p.ps), i(p.i), use(p.use) {++*use;}
    HasPtr &operator=(const HasPtr &rhs)
    {
        ++*rhs.use;
        if(--*use==0)
        {
            delete ps;
            delete use;
        }
        ps=rhs.ps;
        i=rhs.i;
        use=rhs.use;
        return *this;
    }
    ~HasPtr()
    {
        if(--*use==0)
        {
            delete ps;
            delete use;
        }
    }
    
private:
    string *ps;
    int i;
    size_t *use;
};

#endif
