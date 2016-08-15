//!
//! Exercise 12.10:
//! Explain whether the following call to the process function defined on page
//! 464 is correct. If not, how would you correct the call?
//  correct.

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
    process(shared_ptr<int>(p));
}
