#ifndef StrVec_h
#define StrVec_h

#include <string>
#include <memory>
#include <utility>
#include <cstddef>
#include <initializer_list>
using namespace std;

class StrVec {
friend bool operator==(const StrVec&, const StrVec&);
friend bool operator!=(const StrVec&, const StrVec&);
friend bool operator<(const StrVec&, const StrVec&);
friend bool operator>(const StrVec&, const StrVec&);
friend bool operator<=(const StrVec&, const StrVec&);
friend bool operator>=(const StrVec&, const StrVec&);

public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>);

    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();

    StrVec& operator=(initializer_list<string>);

    void push_back(const string&);

    string* begin() const {return elements;}
    string* end() const {return first_free;}

    size_t size() const {return first_free-elements;}
    size_t capacity() const {return cap-elements;}

    string& at(size_t pos) {return *(elements+pos);}
    const string& at(size_t pos) const {return *(elements+pos);}

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const string&);

private:
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void range_initialize(const string*, const string*);
    void free();
    void reallocate();
    void alloc_n_move(size_t);
    void chk_n_alloc() {if(first_free==cap) reallocate();}

    string* elements;
    string* first_free;
    string* cap;
    allocator<string> alloc;
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
bool operator<(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);

#endif
