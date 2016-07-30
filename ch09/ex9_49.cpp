//! @file   Exercise 9.49
//! @author pezy
//! @date   2014-12-05
//! @Brief  A letter has an ascender if, as with d or f, part of the letter
//          extends above the middle of the line.
//          A letter has a descender if, as with p or g, part of the letter
//          extends below the line.
//          Write a program that reads a file containing words and reports the
//          longest word that contains neither ascenders nor descenders.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input("E:\\zzz.txt");
    if(input)
    {
        string longest_word;
        for(string word; input>>word; )
            if((word.find_first_not_of("aceimnorsuvwxz"))==string::npos&&word.size()>longest_word.size())
                longest_word=word;
        cout<<longest_word<<endl;
    }
}
