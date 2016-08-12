//! @Alan @pezy
//!
//! Exercise 11.20:
//! Rewrite the word counting program from § 11.1 (p. 421) to use insert instead
//! of subscripting. Which program do you think is easier to write and read?
//! Explain your reasoning.
//!

#include <iostream>
#include <map>
#include <string>
#include <cstddef>

using namespace std;

int main()
{
   map<string, size_t> word_count;
   string word;
   while(cin>>word)
   {
       auto ret=word_count.insert({word, 1});
       if(!ret.second)
            ++ret.first->second;
   }

   //! print the content of the map
   for(const auto &w:word_count)
   {
       cout<<w.first<<" "<<w.second<<((w.second>1)?" times":" time")<<endl;
   }
}
