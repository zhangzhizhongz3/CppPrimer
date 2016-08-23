#include <string>
#include <iostream>
#include "ex13_53.h"
using namespace std;

void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout<<"call swap"<<endl;
}

HasPtr::HasPtr(const string &s=string()):ps(new string(s)), i(0)
{
    cout<<"call constructor"<<endl;
}

HasPtr::HasPtr(const HasPtr &p):ps(new string(*p.ps)), i(p.i)
{
    cout<<"call copy constructor"<<endl;
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i)
{
    p.ps=0;
    cout<<"call move constructor"<<endl;
}

HasPtr &HasPtr::operator=(HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}

/*
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    auto newp=new string(*rhs.ps);
    delete ps;
    ps=newp;
    i=rhs.i;
    cout<<"call copy-assignment operator"<<endl;
    return *this;
}
*/

/*
HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept
{
    if(this!=&rhs)
    {
        delete ps;
        ps=rhs.ps;
        i=rhs.i;
        rhs.ps=nullptr;
        cout<<"call move-assignment operator"<<endl;
    }
    return *this;
}
*/

HasPtr::~HasPtr()
{
    delete ps;
    cout<<"call destructor"<<endl;
}
