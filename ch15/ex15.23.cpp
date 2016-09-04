//!
//! Exercise 15.23:
//! Assuming class D1 on page 620 had intended to override its inherited fcn
//! function, how would you fix that class? Assuming you fixed the class so
//! that fcn matched the definition in Base, how would the calls in that section
//! be resolved?
//  remove the parameter int.
//!

#include <iostream>
using namespace std;

class Base {
public:
    virtual int fcn() {cout<<"Base::fcn"<<endl; return 0;}
};

class D1 : public Base {
public:
    int fcn() override {cout<<"D1::fcn"<<endl; return 0;}
    //! ^^^^^--fixed to override the inherited version
    virtual void f2() {cout<<"D1::f2"<<endl;}
};

class D2 : public D1 {
public:
    int fcn(int);
    int fcn() override {cout<<"D2::fcn"<<endl; return 0;}
    void f2() override {cout<<"D2::f2"<<endl;}
};

int main()
{
    Base bobj; D1 d1obj; D2 d2obj;
    Base *bp1=&bobj, *bp2=&d1obj, *bp3=&d2obj;
    bp1->fcn(); //! virtual call, will call Base::fcn at run time
    bp2->fcn(); //! virtual call, will call D1::fcn at run time
    bp3->fcn(); //! virtual call, will call D2::fcn at run time

    D1 *d1p=&d1obj; D2 *d2p=&d2obj;
    //bp2->f2();
    //! You are calling virtual member functions via a pointer
    //! to Base. That means that you can only call methods that
    //! exist in the Base class. You cannot simply add methods
    //! to a type dynamically.
    d1p->f2();  //! virtual call, will call D1::f2 at run time
    d2p->f2();  //! virtual call, will call D2::f2 at run time
}
