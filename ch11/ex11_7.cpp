//! @Alan
//!
//! Exercise 11.7:
//! Define a map for which the key is the family’s last name and
//! the value is a vector of the children’s names. Write code to
//! add new families and to add new children to an existing family.
//!

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    map<string, vector<string>> famls;
    string lastName, chldName;

    //! while(lambda)
    cin.clear();
    while([&]() ->bool {cout<<"Please enter last name:\n"; return cin>>lastName&&lastName!="@q";}())    //the () used here is to call the lambda, otherwise it does not work
    {
        cout<<"Please enter children's names:\n";
        cin.clear();
        while(cin>>chldName&&chldName!="@q")
        {
            //! add new items into vector
            famls[lastName].push_back(chldName);
        }
    }

    //! iterate through the map
    for(const auto &e:famls)
    {
        cout<<e.first<<":\n" ;
        //! iterate through the vector
        for(const auto &c: e.second)
            cout<<c<<" ";
        cout<<endl;
    }
}
