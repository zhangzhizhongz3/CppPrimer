#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo {
public:
    Foo sorted() &&;
    Foo sorted () const &;
    
private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    cout<<"&&"<<endl;   //debug
    return *this;
}

Foo Foo::sorted() const &
{
    //Foo ret(*this);
    //sort(ret.data.begin(), ret.data.end());
    //return ret;
    
    cout<<"const &"<<endl;   //debug
    
    //Exercise 13.56
    //Foo ret(*this);
    //return ret.sorted();
    
    //Exercise 13.57
    return Foo(*this).sorted();
}

int main()
{
    Foo().sorted(); //call "&&"
    Foo f;
    f.sorted(); //call "const &"
}
