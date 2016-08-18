//
//  ex12_32.h
//  Exercise 12.32
//
//  Created by pezy on 1/1/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Rewrite the TextQuery and QueryResult classes to use a StrBlob
//  instead of a vector<string> to hold the input file.
//

#ifndef CP5_ex12_32_h
#define CP5_ex12_32_h

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <memory>
#include "ex12_22.h"

using namespace std;

class QueryResult;

class TextQuery {
public:
    TextQuery(ifstream&);

    QueryResult query(const string&) const;

private:
    shared_ptr<StrBlob> file;
    map<string, shared_ptr<set<StrBlob::size_type>>> wm;
};

class QueryResult {
friend ostream &print(ostream&, const QueryResult&);

public:
    QueryResult(string s, shared_ptr<set<StrBlob::size_type>> p, shared_ptr<StrBlob> f):sought(s), lines(p), file(f) {}

private:
    string sought;
    shared_ptr<set<StrBlob::size_type>> lines;
    shared_ptr<StrBlob> file;
};

ostream &print(ostream&, const QueryResult&);

#endif
