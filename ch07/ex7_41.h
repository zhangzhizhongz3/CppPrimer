//
//  ex7_41.h
//  Exercise 7.41
//
//  Created by pezy on 11/20/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @See ex7_26.h
//  @Add 1. use delegating constructors
//       2. add a statement to the body of each of the constructors that prints
//       a message whether it is executed.

#ifndef CP5_ex7_41_h
#define CP5_ex7_41_h

#include <string>
#include <iostream>

class Sales_data;
std::istream &read(std::istream&, Sales_data&);

class Sales_data {
    friend std::istream& read(std::istream&, Sales_data&);
    friend std::ostream& print(std::ostream&, const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);

public:
    Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)
    {
        std::cout << "Sales_data(const std::string&, unsigned, double)" << std::endl;
    }

    Sales_data() : Sales_data("", 0, 0)
    {
        std::cout << "Sales_data()" << std::endl;
    }

    Sales_data(const std::string& s) : Sales_data(s, 0, 0)
    {
        std::cout << "Sales_data(const std::string&)" << std::endl;
    }

    Sales_data(std::istream& is) : Sales_data()
    {
        read(is, *this);
        std::cout<<"Sales_data(std::istream&)"<<std::endl;
    }
    
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

private:
    inline double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

// declarations for nonmember parts of the Sales_data interface
std::istream& read(std::istream&, Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

#endif
