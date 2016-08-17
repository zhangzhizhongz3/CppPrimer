//
//  ex12_26.cpp
//  Exercise 12.26
//
//  Created by pezy on 12/30/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Rewrite the program on page 481 using an allocator.
//

#include <iostream>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

void input_reverse_output_string(int n)
{
    allocator<string> alloc;
    auto const p=alloc.allocate(n);
    string s;
    auto q=p;
    while(cin>>s&&q!=p+n)
        alloc.construct(q++, s);
    while(q!=p)
    {
        cout<<*--q<<" ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
}

int main()
{
    input_reverse_output_string(5);
}
