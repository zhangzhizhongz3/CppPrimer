#ifndef String_h
#define String_h

#include <iostream>
#include <memory>
#include <utility>
using namespace std;

class String {
friend ostream& operator<<(ostream&, const String&);

public:
    String():String("") {}
    String(const char*);
    String(const String&);
    String &operator=(const String&);
    ~String();

    const char* c_str() const {return elements;}
    size_t size() const {return end-elements;}
    size_t length() const {return end-elements-1;}

private:
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initialize(const char*, const char*);
    void free();

    char *elements;
    char *end;
    allocator<char> alloc;
};

ostream& operator<<(ostream&, const String&);

#endif
