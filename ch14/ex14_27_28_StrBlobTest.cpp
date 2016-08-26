#include <iostream>
#include "ex14_27_28_StrBlob.h"
using namespace std;

int main()
{
    StrBlob sb1{"a", "b", "c"};
    StrBlob sb2=sb1;

    sb2[2]="b";

    if (sb1 > sb2)
    {
        for (StrBlobPtr iter = sb1.begin(); iter < sb1.end(); ++iter)
            cout << iter.deref() << " ";
        cout << endl;
    }

    ConstStrBlobPtr iter(sb2);
    cout<<(iter+2).deref()<<endl;
}
