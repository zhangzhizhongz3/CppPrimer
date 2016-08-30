//!
//! Exercise 15.12:
//! Is it ever useful to declare a member function as both override and final?
//! Why or why not?
//  Sure. override means overriding the same name virtual function in base class.
//  final means preventing any overriding this virtual function by any derived classes
//  that are more lower at the hierarchy .
//!
//! Exercise 15.13:
//! Given the following classes, explain each print function:
//! If there is a problem in this code, how would you fix it?
//!
//! Exercise 15.14:
//! Given the classes from the previous exercise and the following objects,
//! determine which function is called at run time:
//!

#include <iostream>
#include <string>
using namespace std;

class base {
public:
    string name() {return basename;}
    virtual void print(ostream& os) {os<<basename;}
    //!     ~~~~~^^^^^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //!  The print here just output the basename of the base.

private:
    string basename="base\n";
};

class derived : public base {
public:
    void print(ostream& os) {base::print(os); os<<"derived "<<i<<endl;}
    //!  ^^^^^                     ^^^^^   --  added to fix this problem
    //!  this print wanted to call the print from the base class.
    //!  however, the class scope base:: was omitted. As a result
    //!  it will cause an infinite recursion.

private:
    int i;
};

int main()
{
    base bobj;
    base* bp1=&bobj;
    base& br1=bobj;
    derived dobj;
    base* bp2=&dobj;
    base& br2=dobj;

    //! a.  this is an object, so compile time
    bobj.print(cout);

    //! b.  this is an object, so compile time
    dobj.print(cout);

    //! c.  function name is not virtual , so no dynamic
    //!     binding happens.so compile time
    cout << bp1->name();

    //! d.  function name is not virtual , so no dynamic
    //!     binding happens.so compile time
    cout << bp2->name();

    //! e.  run time
    br1.print(cout);

    //! f.  run time
    br2.print(cout);
}
