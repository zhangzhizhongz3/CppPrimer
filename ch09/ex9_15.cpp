//! @file   Exercise 9.15
//! @author pezy
//! @date   2014-12-02
//! @Brief  Write a program to determine whether two vector<int>s are equal.

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec1{1,2,3,4,5};
    std::vector<int> ivec2{1,2,3,4,5};
    std::vector<int> ivec3{1,2,3,4};

    std::cout<<std::boolalpha<<(ivec1==ivec2)<<std::endl;
    std::cout<<std::boolalpha<<(ivec1==ivec3)<<std::endl;
}
