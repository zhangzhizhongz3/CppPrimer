#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

bool hasUppercase(const string &str)
{
    for (auto c : str)
        if (isupper(c)) return true;
    return false;
}

void makeLowercase(string &str)
{
    for (auto &c : str)
        if (isupper(c)) c = tolower(c);
}

int main()
{
    string str("Hello World!");
    cout << boolalpha << hasUppercase(str) << endl;
    makeLowercase(str);
    cout << str << endl;

    return 0;
}
