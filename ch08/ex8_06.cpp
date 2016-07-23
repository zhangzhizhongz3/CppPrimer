//
//  ex8_06.cpp
//  Exercise 8.6
//
//  Created by pezy on 11/27/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  Rewrite the bookstore program from §7.1.1 (p.256) to read its transactions from a file.
//          Pass the name of the file as an argument to main (§6.2.5, p.218).
//  @See    ex7_26.h (use the Sales_data)
//  @Run    give a parameter: "E:\book_sales.txt"
//  @Output 0-201-70353-X 4 99.96 24.99
//          0-201-82470-1 4 181.56 45.39
//          0-201-88954-4 16 198 12.375
//          0-399-82477-1 5 226.95 45.39
//          0-201-78345-X 5 110 22

// @Brief   Rewrite the bookstore program from 7.1.1 (p.256) to read its transactions from a file.
//          Pass the name of the file as an argument to main (6.2.5, p.218).
// @See     ex7_26.h (use the Sales_data)
// @Run     give an argument: "E:\book_sales.txt"
// @Output  0-201-70353-X 4 99.96 24.99
//          0-201-82470-1 4 181.56 45.39
//          0-201-88954-4 16 198 12.375
//          0-399-82477-1 5 226.95 45.39
//          0-201-78345-X 5 110 22
#include <iostream>
using std::cerr; using std::cin; using std::cout; using std::endl;
#include <fstream>
using std::ifstream;

#include "ex7_26.h"

int main(int argc, char *argv[])
{
	ifstream input(argv[1]);
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
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}
}
