//!
//! @author @huangjuncmj @Yue Wang
//! @date   19.11.2014
//!
//! Exercise 9.26:
//! Using the following definition of ia, copy ia into a vector and into a list.
//! Use the single-iterator form of erase to remove the elements with odd values
//! from your list and the even values from your vector.
//!
#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    int ia[]={0,1,1,2,3,5,8,13,21,55,89};

    //! init
    list<int> ilst(begin(ia), end(ia));
    vector<int> ivec(begin(ia), end(ia));

    //! remove odd value
    for(auto it=ilst.begin(); it!=ilst.end(); )
        if(*it & 0x1)
            it=ilst.erase(it);
        else
            ++it;

    //! remove even value
    for(auto it=ivec.begin(); it!=ivec.end(); )
        if(!(*it & 0x1))
            it=ivec.erase(it);
        else
            ++it;

    //! print
    cout<<"list: ";
    for(auto i:ilst)
        cout<<i<<" ";
    cout<<endl;
    cout<<"vector: ";
    for(auto i:ivec)
        cout<<i<<" ";
    cout<<endl;
}
