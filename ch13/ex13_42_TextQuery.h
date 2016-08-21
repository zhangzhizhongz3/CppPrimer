#ifndef CP5_ex12_27_30_h
#define CP5_ex12_27_30_h

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <cstddef>
#include <memory>
#include "ex13_40.h"

using namespace std;

class QueryResult;

class TextQuery {
public:
    TextQuery(ifstream&);

    QueryResult query(const string&) const;

private:
    shared_ptr<StrVec> file;
    map<string, shared_ptr<set<size_t>>> wm;
};

class QueryResult {
friend ostream &print(ostream&, const QueryResult&);

public:
    QueryResult(string s, shared_ptr<set<size_t>> p, shared_ptr<StrVec> f):sought(s), lines(p), file(f) {}

private:
    string sought;
    shared_ptr<set<size_t>> lines;
    shared_ptr<StrVec> file;
};

ostream &print(ostream&, const QueryResult&);

#endif
