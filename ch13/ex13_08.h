//
//  ex13_08.h
//
//  Created by pezy on 1/12/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Write the assignment operator for the HasPtr class from exercise 13.5 in
//  13.1.1 (p. 499).
//  As with the copy constructor, your assignment operator should copy the
//  object to which ps points.
//
//  See ex13_05.h
//

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &hp)
    {
        auto newp=new string(*hp.ps);
        delete ps;
        ps=newp;
        i=hp.i;
        return *this;
    }
private:
    string *ps;
    int i;
};
