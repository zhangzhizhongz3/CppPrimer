//
//  ex13_26.cpp
//  Exercise 13.26
//
//  @See    ex12_22 and ex13_25
//

#include "ex12_26.h"

StrBlob &StrBlob::operator=(const StrBlob &sb)
{
    data=make_shared<vector<string>>(*sb.data);
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const // should add const
{
    return ConstStrBlobPtr(*this);
}
ConstStrBlobPtr StrBlob::end() const // should add const
{
    return ConstStrBlobPtr(*this, data->size());
}
