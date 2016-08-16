//
//  ex12_19.cpp
//  Exercise 12.19
//
//  Created by pezy on 12/26/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @See    ex12_19.h

#include "ex12_19.h"

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}
