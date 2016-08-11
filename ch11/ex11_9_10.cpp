//! @Alan
//!
//! Exercise 11.9:
//! Define a map that associates words with a list of
//! line numbers on which the word might occur.
//!
//! Exercise 11.10:
//! Could we define a map from vector<int>::iterator
//! to int? What about from list<int>::iterator to int?
//! In each case, if not, why not?
//  vector<int>::iterator to int is ok ,because < is defined
//  list<int>::iterator to int is not ok,as no < is defined.

#include <map>
#include <string>
#include <vector>
#include <list>
#include <cstddef>
#include <algorithm>

using namespace std;

int main()
{
    //! ex 11.9
    map<string, list<size_t>> m;

    //! ex 11.10
    //! can be declared
    map<vector<int>::iterator, int> mv;
    map<list<int>::iterator, int> ml;

    vector<int> vi;
    mv.insert(pair<vector<int>::iterator, int>(vi.begin(), 0));

    //! but when using this one the compiler complained that
    //! error: no match for 'operator<' in '_x < _y'
    list<int> li;
    ml.insert(pair<list<int>::iterator, int>(li.begin(), 0));
}
