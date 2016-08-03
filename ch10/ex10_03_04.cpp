//!
//! @author Yue Wang
//! @date   01.12.2014
//!
//! Exercise 10.3:
//! Use accumulate to sum the elements in a vector<int>.
//!
//! Exercise 10.4:
//! Assuming v is a vector<double>, what, if anything,
//! is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?
//!  Check below:
//!

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    //! Exercise 10.3
    vector<int> ivec={1, 2, 3, 4};
    cout<<"ex 10.03: "<<accumulate(ivec.cbegin(), ivec.cend(), 0)<<endl;
    
    //! Exercise 10.4
    vector<double> dvec={1.1, 0.5, 3.3};
    cout<<"ex 10.04: "<<accumulate(dvec.cbegin(), dvec.cend(), 0)<<endl;    //! ^<--note here
    //! @attention
    //! The output is 4 rather than 4.9 as expected.
    //! The reason is accumulate is a template function. The third
    //! parameter is _Tp __init
    //! When "0", an integer, had been specified here, the compiler
    //! deduced _Tp as integer. As a result, when the following statements
    //! were being executed:
    //  for (; __first != __last; ++__first)
    //  __init = __init + *__first;
    //  return __init;
    //! all calculation would be converted to integer.
}

//! output
//!
// ex 10.03: 10
// ex 10.04: 4
