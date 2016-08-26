#include <iostream>
#include "ex14_26_StrBlob.h"
using namespace std;

int main()
{
    StrBlob sb1{"a", "b", "c"};
    StrBlob sb2=sb1;

    sb2[2]="b";

    if (sb1 > sb2)
    {
        for (ConstStrBlobPtr iter = sb1.cbegin(); iter < sb1.cend(); iter.incr())
            cout << iter.deref() << " ";
        cout << endl;
    }

    StrBlobPtr iter(sb2);
    cout<<iter[2]<<endl;
}
