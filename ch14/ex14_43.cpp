//!
//! Exercise 14.43:
//! Using library function objects, determine whether a given int value is
//! divisible by any element in a container of ints.
//!

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> data = {2, 3, 4, 5};
    int input;
    std::cin >> input;
    std::modulus<int> mod;
    auto predicator = [&](int i) { return 0 == mod(input, i); };
    auto is_divisible = std::all_of(data.begin(), data.end(), predicator);
    std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;
}

