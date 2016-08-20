//
//  ex13_28.h
//  Exercise 13.28
//
//  Created by pezy on 1/20/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Given the following classes, implement a default constructor and the
//  necessary copy control members.
//

#ifndef CP5_ex13_28_h
#define CP5_ex13_28_h

#include <string>
using namespace std;

class TreeNode {
public:
    TreeNode():value(string()), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &p):value(p.value), count(p.count), left(p.left), right(p.right) {++*count;}
    TreeNode &operator=(const TreeNode&);
    ~TreeNode()
    {
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
    }
    
private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
public:
    BinStrTree():root(new TreeNode()) {}
    BinStrTree(const BinStrTree &b):root(new TreeNode(*b.root)) {}
    BinStrTree &operator=(const BinStrTree&);
    ~BinStrTree() {delete root;}
    
private:
    TreeNode *root;
};

#endif
