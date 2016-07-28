//
//  ex9_31.cpp
//  Exercise 9.31
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  The program on page 354 to remove even-valued elements and
//          duplicate odd ones will not work on a list or forward_list. Why?
//          Revise the program so that it works on these types as well.
//  @forward_list   1. vi.insert -> vi.insert_after
//                  2. ++iter; ++iter; -> advance(iter, 2);
//                  3. vi.erase -> vi.erase_after
//                  4. added iterator prev, and edit some detail

#include <iostream>
#include <forward_list>

using std::cout;
using std::endl;
using std::forward_list;
using std::advance;

int main()
{
    forward_list<int> vi={0,1,2,3,4,5,6,7,8,9};
    auto prev=vi.before_begin();
    auto curr=vi.begin();
    while(curr!=vi.end())
    {
        if(*curr%2)
        {
            curr=vi.insert_after(prev, *curr);
            advance(curr, 2);
            advance(prev, 2);
        }
        else
            curr=vi.erase_after(prev);
    }

    for(auto i:vi)
        cout<<i<<" ";
    cout<<endl;
}
