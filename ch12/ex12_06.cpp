//!
//! Exercise 12.6:
//! Write a function that returns a dynamically allocated vector of ints.
//! Pass that vector to another function that reads the standard input to
//! give values to the elements. Pass the vector to another function to print
//! the values that were read.
//! Remember to delete the vector at the appropriate time.
//!

#include <iostream>
#include <vector>

using namespace std;

vector<int> *dynamic_vector_generator()
{
    return new vector<int>();
   //vector<int> *ptr_v=new vector<int>();
   //return ptr_v;
}

void dynamic_vector_processor(vector<int> *ptr_v)
{
    int i;
    while(cin>>i)
        ptr_v->push_back(i);
}

void dynamic_vector_printer(const vector<int> *ptr_v)
{
    for(const auto &e : *ptr_v)
        cout<<e<<" ";
    cout<<endl;
}

int main()
{
    //testing the 3 functions
    vector<int> *ptr_vi=dynamic_vector_generator();
    dynamic_vector_processor(ptr_vi);
    dynamic_vector_printer(ptr_vi);
    delete ptr_vi;
}
