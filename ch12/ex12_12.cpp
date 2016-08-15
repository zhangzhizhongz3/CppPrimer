//!
//! Exercise 12.12:
//! Using the declarations of p and sp explain each of the following calls to
//! process. If the call is legal, explain what it does. If the call is illegal,
//! explain why:
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
    auto p=new int();
    auto sp=make_shared<Int>();
    
    //legal. Just copy sp which is a shared_ptr to process().
    process(sp);
    
    //illegal. Plain pointer can not convert to smart pointer implicitly.
    process(new int());
    
    //illegal. Plain pointer can not convert to smart pointer implicitly.
    process(p);
    
    //It's a bad practice to do so.
    //Because using smart pointer together with raw pointer could
    //potentially cause problems.
    process(shared_ptr<int>(p));
}
