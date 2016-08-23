#ifndef CP5_ex13_53_h
#define CP5_ex13_53_h

#include <string>
using namespace std;

class HasPtr {
friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const string&);
    HasPtr(const HasPtr&);
    HasPtr(HasPtr&&) noexcept;
    HasPtr &operator=(HasPtr);
    //HasPtr &operator=(const HasPtr&);
    //HasPtr &operator=(HasPtr&&) noexcept;
    ~HasPtr();

private:
    string *ps;
    int i;
};

#endif
