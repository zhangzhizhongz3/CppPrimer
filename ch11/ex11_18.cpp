//! @Alan
//!
//! Exercise 11.18:
//! Write the type of map_it from the loop on page 430 without using auto or
//! decltype.
//!

#include <iostream>
#include <map>
#include <string>
#include <cstddef>

using namespace std;

int main()
{
    map<string, size_t> word_count;

    //! the original codes:
    // auto map_it = word_count.begin();

    //! the type ex11.18 required.
    map<string, size_t>::iterator map_it = word_count.begin();

    //! compare the current iterator to the off-the-end iterator
    while (map_it != word_count.end())
    {
        // dereference the iterator to print the element key--value pairs
        cout << map_it->first << " occurs " << map_it->second << " times" << endl;
        ++map_it; // increment the iterator to denote the next element
    }
}
