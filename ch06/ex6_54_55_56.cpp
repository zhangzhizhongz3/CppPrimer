//!
//! Exercise 6.54:
//! Write a declaration for a function that takes two int
//! parameters and returns an int, and declare a vector whose
//! elements have this function pointer type.
//!
//! Exercise 6.55:
//! Write four functions that add, subtract, multiply, and divide
//! two int values. Store pointers to these functions in your
//! vector from the previous exercise.
//!
//! Exercise 6.56:
//! Call each element in the vector and print their result.
//!

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return b != 0 ? a / b : 0;
}

vector<int (*)(int, int)> vec{add, subtract, multiply, divide};

int main()
{
    for (auto f : vec)
        cout << f(2, 2) << endl;

}
