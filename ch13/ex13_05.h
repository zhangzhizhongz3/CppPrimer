//
//  ex13_05.h
//
//  Created by pezy on 1/5/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Given the following sketch of a class, write a copy constructor that copies
//  all the members.
//  Your constructor should dynamically allocate a new string and copy the
//  object to which ps points, rather than copying ps itself.
//

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
private:
    string *ps;
    int i;
};
