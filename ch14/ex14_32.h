#ifndef StrBlobPtr_pointer_h
#define StrBlobPtr_pointer_h

#include "ex14_30_StrBlob.h"

class StrBlobPtr;

//@brief a class that holds a pointer to a StrBlobPtr
class StrBlobPtr_pointer {
public:
    StrBlobPtr_pointer()=default;
    StrBlobPtr_pointer(StrBlobPtr* p) : pointer(p) {}

    StrBlobPtr& operator*();
    StrBlobPtr* operator->();

private:
    StrBlobPtr* pointer=nullptr;
} ;

#endif // StrBlobPtr_pointer_h
