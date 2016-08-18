//
//  ex12_33.h
//  Exercise 12.33
//
//  Created by pezy on 1/1/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  In Chapter 15 we’ll extend our query system and will need some additional
//  members in the QueryResult class. Add members named [begin] and [end] that
//  return iterators into the set of line numbers returned by a given query, 
//  and a member named [get_file] that returns a shared_ptr to the file in the QueryResult object.
//

#ifndef CP5_ex12_33_h
#define CP5_ex12_33_h

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
    using ResultIter=set<StrBlob::size_type>::iterator;

    QueryResult(string s, shared_ptr<set<StrBlob::size_type>> p, shared_ptr<StrBlob> f):sought(s), lines(p), file(f) {}

    ResultIter begin() const {return lines->begin();}
    ResultIter end() const {return lines->end();}
    shared_ptr<StrBlob> get_file() const {return file;}
    
private:
    string sought;
    shared_ptr<set<StrBlob::size_type>> lines;
    shared_ptr<StrBlob> file;
};

ostream &print(ostream&, const QueryResult&);

#endif
