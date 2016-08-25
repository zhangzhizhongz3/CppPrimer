#include <iostream>
#include "ex14_16_StrBlob.h"
using namespace std;

int main()
{
    StrBlob sb{"Hello", "World", "Pezy"};

    for (ConstStrBlobPtr iter = sb.cbegin(); iter != sb.cend(); iter.incr())
        cout << iter.deref() << " ";
    cout << endl;
}
