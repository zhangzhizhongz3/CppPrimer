//
//  ex10_33.cpp
//  Exercise 10.33
//
//  Created by pezy on 12/13/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program that takes the names of an input file and two output files.
//  The input file should hold integers. Using an istream_iterator read the
//  input file. Using ostream_iterators, write the odd numbers into the first
//  output file. Each value should be followed by a space. Write the even numbers 
//  into the second output file. Each of these values should be placed on a separate line.
//

#include <iterator>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc!=4)
        return -1;
    ifstream ifs(argv[1]);
    ofstream ofs_odd(argv[2]), ofs_even(argv[3]);

    istream_iterator<int> in(ifs), in_eof;
    ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");
    for_each(in, in_eof, [&out_odd, &out_even](const int i) {(i & 0x1 ? out_odd : out_even)=i;});
}
