#ifndef StrVec_h
#define StrVec_h

#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
using namespace std;

class StrVec {
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>);
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec &operator=(StrVec&&) noexcept;
    ~StrVec();

    void push_back(const string&);
    size_t size() const (return first_free-elements;)
    size_t capacity() const {return cap-elements;}
    string *begin() const {return elements;}
    string *end() const {return first_free;}
    
    string &at(size_t pos) {return *(elements+pos);}
    const string &at(size_t pos) const {return *(elements+pos);}

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const string&);

private:
    void chk_n_alloc() {if(size()==capacity()) reallocate();}

    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    void alloc_n_move(size_t);
    void range_initialize(const string*, const string*);

    string *elements;
    string *first_free;
    string *cap;
    allocator<string> alloc;
};

#endif
