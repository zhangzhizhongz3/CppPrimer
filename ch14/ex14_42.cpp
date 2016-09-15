#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using std::placeholders::_1;

int main()
{
    std::vector<int> ivec{1, 111, 1111, 11111};
    int count = std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
    std::cout << count << std::endl;

    std::vector<std::string> svec{"pooh", "pooh", "pezy", "pooh"};
    auto found = std::find_if(svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
    std::cout << *found << std::endl;

    std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<int>(), _1, 2));
    for (int i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;
}
