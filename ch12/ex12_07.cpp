//!
//! Exercise 12.7:
//! Redo the previous exercise, this time using shared_ptr.
//!

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> dynamic_vector_generator()
{
    return make_shared<vector<int>>();
}

void dynamic_vector_processor(shared_ptr<vector<int>> ptr_v)
{
    int i;
    while(cin>>i)
        ptr_v->push_back(i);
}

void dynamic_vector_printer(const shared_ptr<vector<int>> ptr_v)
{
    for(const auto &e : *ptr_v)
        cout<<e<<" ";
    cout<<endl;
}

int main()
{
    //testing the 3 functions
    shared_ptr<vector<int>> ptr_vi=dynamic_vector_generator();
    dynamic_vector_processor(ptr_vi);
    dynamic_vector_printer(ptr_vi);
}
