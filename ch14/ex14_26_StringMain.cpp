#include <iostream>
#include <vector>
#include "ex14_26_String.h"
using namespace std;

void foo(String x)
{
    cout << x << endl;
}

void bar(const String& x)
{
    cout << x.c_str() << endl;
}

String baz()
{
    String ret("world");
    return ret;
}

int main()
{
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(std::move(s0));
    String s3 = s1;
    String s4(text);
    s2 = s1;

    if (s2 == s1)
        cout << "s2 == s1" << endl;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz();

    vector<String> svec;
    //svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto& s : svec)
    {
        cout << s << endl;
    }

    cout << "Input a string: ";
    String s6;
    cin >> s6;
    cout << s6 << endl;

    if (s6 > s1)
        cout << "s6 > s1" << endl;

    cout<<s5[2]<<endl;
}
