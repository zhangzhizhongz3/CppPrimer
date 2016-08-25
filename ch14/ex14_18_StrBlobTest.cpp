#include <iostream>
#include "ex14_18_StrBlob.h"
using namespace std;

int main()
{
    StrBlob sb1{"a", "b", "c"};
    StrBlob sb2{"a", "b", "b"};

    if (sb1 > sb2)
    {
        for (ConstStrBlobPtr iter = sb1.cbegin(); iter < sb1.cend(); iter.incr())
            cout << iter.deref() << " ";
        cout << endl;
    }
}
