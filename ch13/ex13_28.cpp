//
//  ex13_28.cpp
//  Exercise 13.28
//

#include "ex13_28.h"

TreeNode &TreeNode::operator=(const TreeNode &rhs)
{
    ++*rhs.count;
    if(--*count==0)
    {
        if(left)
        {
            delete left;
            left=nullptr;
        }
        if(right)
        {
            delete right;
            right=nullptr;
        }
        delete count;
        count=nullptr;
    }
    value=rhs.value;
    count=rhs.count;
    left=rhs.left;
    right=rhs.right;
    return *this;
}

BinStrTree &BinStrTree::operator=(const BinStrTree &rhs)
{
    auto newb=new TreeNode(*rhs.root);
    delete root;
    root=newb;
    return *this;
}
