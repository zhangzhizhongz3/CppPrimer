#include <iostream>
#include "ex14_32.h"
#include "ex14_30_StrBlob.h"
using namespace std;

StrBlobPtr& StrBlobPtr_pointer::operator*()
{
    return *(this->pointer);
}

StrBlobPtr* StrBlobPtr_pointer::operator->()
{
    return &this->operator*();
}

int main()
{
    StrBlob sb{"hello", "world"};
    StrBlobPtr iter = sb.begin();
    StrBlobPtr_pointer p(&iter);
    cout << p->operator*() << endl;
}
