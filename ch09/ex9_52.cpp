//
//  ex9_52.cpp
//  Exercise 9.52
//
//  Created by pezy on 12/5/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Use a stack to process parenthesized expressions.
//          When you see an open parenthesis, note that it was seen.
//          When you see a close parenthesis after an open parenthesis,
//          pop elements down to and including the open parenthesis off the
//          stack.
//          push a value onto the stack to indicate that a parenthesized
//          expression was replaced.

//Version1
#include <iostream>
#include <stack>
#include <string>
using std::cout;
using std::endl;
using std::stack;
using std::string;

int main()
{
    auto &expr="This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";
    auto repl='#';
    auto seen=0;

    stack<char> stk;

    for(const auto &c : expr)
    {
        stk.push(c);
        if(c=='(')
            ++seen;                 //open
        if(seen && c==')')         //pop elements down to the stack
        {
            while(stk.top()!='(')
                stk.pop();
            stk.pop();              //including the open parenthesis
            stk.push(repl);         //push a value indicate it was replaced
            --seen;                 //close
        }
    }

    //Test
    string output;
    while(!stk.empty())
    {
        output.insert(output.begin(), stk.top());
        stk.pop();
    }

    cout<<output<<endl;             //"This is # and # over"
}


//Version2
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> stk;
    string s;
    cout<<"Input a expression: ";
    getline(cin, s);

    //deal the stk
    string::iterator it=s.begin();
    while(it!=s.end())
    {
        if(*it!=')')
            stk.push(*it);
        else
        {
            while(!stk.empty()&&stk.top()!='(')
                    stk.pop();

            if(stk.empty())
                cout<<"It't not matched."<<endl;
            else
            {
                stk.pop();
                stk.push('@');
            }
        }

        ++it;
    }

    //show out the elements of the stack
    cout<<"\nThe elements of the stack are:"<<endl;
    string output;
    while(!stk.empty())
    {
        output.insert(output.begin(), stk.top());
        stk.pop();
    }

    cout<<output<<endl;
}
