//
//  ex13_11.h
//
//  Created by pezy on 1/13/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Add a destructor to your HasPtr class from the previous exercises.
//
//  See ex13_08.h
//

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
