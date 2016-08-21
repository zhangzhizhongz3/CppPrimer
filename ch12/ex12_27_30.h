//
//  ex12_27_30.h
//  Exercise 12.27 12.30
//
//  Created by pezy on 12/31/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  The TextQuery and QueryResult classes use only capabilities that we have
//  already covered.
//  Without looking ahead, write your own versions of these classes.
//

#ifndef CP5_ex12_27_30_h
#define CP5_ex12_27_30_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

using namespace std;

class QueryResult;

class TextQuery {
public:
    using line_no=vector<string>::size_type;

    TextQuery(ifstream&);

    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult {
friend ostream &print(ostream&, const QueryResult&);

public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f):sought(s), lines(p), file(f) {}

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream &print(ostream&, const QueryResult&);

#endif
