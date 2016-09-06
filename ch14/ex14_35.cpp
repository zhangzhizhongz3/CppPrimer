#include <iostream>
#include <string>
using namespace std;

class GetString {
public:
    GetString(istream &i=cin) : is(i) {}
    string operator()() const
    {
        string str;
        getline(is, str);
        return is ? str : string();
    }
private:
    istream &is;
};

int main()
{
    GetString getstring;
    cout<<getstring()<<endl;
}
