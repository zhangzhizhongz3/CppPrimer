//===================================================================================
//
//		|s|t|r|i|n|g|\0|-------------------|
//		 ^			 ^  ^ first_free        ^
//		elements	 last_elem			    cap
//
//===================================================================================

#ifndef String_h
#define String_h

#include <iostream>
#include <memory>
#include <utility>
#include <cstddef>
using namespace std;

class String {
friend istream& operator>>(istream&, String&);
friend ostream& operator<<(ostream&, const String&);
friend bool operator==(const String&, const String&);
friend bool operator!=(const String&, const String&);
friend bool operator<(const String&, const String&);
friend bool operator>(const String&, const String&);
friend bool operator<=(const String&, const String&);
friend bool operator>=(const String&, const String&);

public:
    String():String("") {}
    String(const char*);

    String(const String&);
    String& operator=(const String&);
    String(String&&) noexcept;
    String& operator=(String&&) noexcept;
    ~String();

    void push_back(const char&);

    char* begin() const {return elements;}
    char* end() const {return last_elem;}

    const char* c_str() const {return elements;}
    size_t size() const {return last_elem-elements;}
    size_t length() const {return size();}
    size_t capacity() const {return cap-elements;}

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, char);

private:
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initialize(const char*, const char*);
    void free();
    void reallocate();
    void alloc_n_move(size_t);
    void chk_n_alloc() {if(first_free==cap) reallocate();}

    char* elements;
    char* last_elem;
    char* first_free;
    char* cap;
    allocator<char> alloc;
};

istream& operator>>(istream&, String&);
ostream& operator<<(ostream&, const String&);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
bool operator<(const String&, const String&);
bool operator>(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);

#endif
