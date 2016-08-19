//
//  ex13_22.h
//  Exercise 13.22
//
//  Created by pezy on 1/13/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Assume that we want HasPtr to behave like a value. That is, each object 
//  should have its own copy of the string to which the objects point.
//  We'll show the definitions of the copy-control members in the next section.
//  However, you already know everything you need to know to implement these
//  members.
//  Write the HasPtr copy constructor and copy-assignment operator before reading
//  on.
//
//  See ex13_11.h
//

#ifndef CP5_ex13_22_h
#define CP5_ex13_22_h

#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &hp)
    {
        delete ps;
        ps=new string(*hp.ps);
        i=hp.i;
        return *this;
    }
    ~HasPtr() {delete ps;}
private:
    string *ps;
    int i;
};

#endif
