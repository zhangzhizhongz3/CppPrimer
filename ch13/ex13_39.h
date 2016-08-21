//
//  ex13_39.h
//  Exercise 13.39
//
//  Created by pezy on 2/3/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Write your own version of StrVec, including versions of
//  reserve, capacity (9.4, p. 356), and resize (9.3.5, p. 352).
//

#ifndef CP5_ex13_39_h
#define CP5_ex13_39_h

#include <string>
#include <memory>
#include <utility>
using namespace std;

class StrVec {
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();

    void push_back(const string&);
    size_t size() const (return first_free-elements;)
    size_t capacity() const {return cap-elements;}
    string *begin() const {return elements;}
    string *end() const {return first_free;}

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const string&);

private:
    static allocator<string> alloc;

    void chk_n_alloc() {if(size()==capacity()) reallocate();}

    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    void alloc_n_move(size_t);

    string *elements;
    string *first_free;
    string *cap;
};

#endif
