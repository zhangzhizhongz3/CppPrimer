//
//  ex13_17.cpp
//  Exercise 13.17
//
//  For 13.15
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

void f(numbered s)
{
    cout<<s.mysn<<endl;
}

int main()
{
    numbered a, b=a, c=b;
    f(a); f(b); f(c);
}

// output
// 11
// 12
// 13
