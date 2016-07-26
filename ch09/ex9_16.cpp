//! @file   Exercise 9.16
//! @author pezy
//! @date   2014-12-02
//! @Brief  Repeat the previous program, but compare elements in a list<int> to
//! a vector<int>.

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> ilst{1,2,3,4,5};
    std::vector<int> ivec1{1,2,3,4,5};
    std::vector<int> ivec2{1,2,3,4};

    std::cout<<std::boolalpha
             <<(std::vector<int>(ilst.begin(), ilst.end())==ivec1)
             <<std::endl;
    std::cout<<std::boolalpha
             <<(std::vector<int>(ilst.begin(), ilst.end())==ivec2)
             <<std::endl;
}
