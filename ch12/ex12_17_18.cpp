//!
//! Exercise 12.17:
//! Which of the following unique_ptr declarations are illegal or likely to
//! result in subsequent program error? Explain what the problem is with each
//! one.
//!
//! Exercise 12.18:
//! Why doesn’t shared_ptr have a release member?
//! Because other shared_ptr that points the same object can still delete this
//! object. Thus, it's meaningless to provide this member.

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    int ix=1024, *pi=&ix, *pi2=new int(2048);
    typedef unique_ptr<int> IntP;

    // @brief error: invalid conversion from 'int' to
    // 'std::unique_ptr<int>::pointer {aka int*}' [-fpermissive]
    // IntP p0(ix);

    // @brief the code below can compile, but will cause
    // error at run time. the reason is that when the
    // unique_ptr p1 is out of scope, delete will be called
    // to free the object. but the object is not allocated using
    // new. thus, an error would be thrown by operating system.
    // @badcode
    // IntP p1(pi);

    // @brief this code can compile but cause a dangling pointer
    // at run time. the reason is that the unique_ptr will free the
    // object the raw pointer is pointing to.
    // @badcode
    // {IntP p2(pi2);}

    // @brief when the unique_ptr goes out of scope, it will call
    // delete to free an object not allocated using new.
    // @badcode
    // IntP p3(&ix);

    // @brief recommended.
    // IntP p4(new int(2048));

    // @brief error:double free or corruption at run time. two
    // unique_ptr are pointing to the same object. thus, when both
    // are out of scope, operating system will throw double free
    // or corruption.
    // IntP p5(p2.get());
}
