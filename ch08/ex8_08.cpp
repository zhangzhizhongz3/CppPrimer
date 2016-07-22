//
//  ex8_08.cpp
//  Exercise 8.8
//
//  Created by pezy on 11/28/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Revise the program from the previous exercise to append its output to its given file.
//          Run the program on the same output file at least twice to ensure that the data are preserved
//  @See    ex8_07.cpp
//  @Run    give arguments: "E:\book_sales.txt" "E:\zzz.txt"

#include <iostream>
using std::cerr; using std::cin; using std::cout; using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;

#include "ex7_26.h"

int main(int argc, char *argv[])
{
	ifstream input(argv[1]);
	ofstream output(argv[2], ofstream::app);
	Sales_data total;
	if (read(input, total))
	{
		Sales_data trans;
		while(read(input, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}
}
