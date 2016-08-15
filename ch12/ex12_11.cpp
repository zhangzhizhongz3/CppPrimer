//!
//! Exercise 12.11:
//! What would happen if we called process as follows?
//! An error was generated at run time : double free or corruption.
//!

#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> ptr)
{
    cout<<"inside the process function: "<<ptr.use_count()<<endl;
}

int main()
{
    shared_ptr<int> p(new int(42));

    // @brief shared_ptr<int>(p.get() construct a temporary shared_ptr and copy it
    //        to the parameter. However it is not a copy of p. As a result, at the
    //        end of this main function p will free the memory that has been freed
    //        inside process(). That's why "double freed or corruption" was generated.

    process(shared_ptr<int>(p.get()));
}
