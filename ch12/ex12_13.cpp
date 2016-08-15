//!
//! ex12.13 What happens if we execute the following code?
//!
//! generate a runtime error : double free
//!

#include <iostream>
#include <memory>

int main()
{
    {
        auto sp = make_shared<int>();
        auto p = sp.get();
        delete p;
    }
}
