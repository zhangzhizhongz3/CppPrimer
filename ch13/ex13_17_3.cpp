//
//  ex13_17.cpp
//  Exercise 13.17
//
//  For 13.16
//

#include <iostream>

using namespace std;

class numbered {
public:
    numbered()
    {
        static int unique=10;
        mysn=unique++;
    }

    numbered(const numbered &n)
    {
        mysn=n.mysn+1;
    }

    int mysn;
};

void f(const numbered &s)
{
    cout<<s.mysn<<endl;
}

int main()
{
    numbered a, b=a, c=b;
    f(a); f(b); f(c);
}

// output
// 10
// 11
// 12
