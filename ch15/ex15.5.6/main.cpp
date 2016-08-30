//!
//! Exercise 15.4:
//! Which of the following declarations, if any, are incorrect? Explain why.
//       class Base { ... };
//      (a) class Derived : public Derived { ... }; //incorrect, deirve from itself
//      (b) class Derived : private Base { ... };   //incorrect, this is a definition not a declaration
//      (c) class Derived : public Base;            //incorrect, A derived class is declared like any other class. The declaration
                                                    //contains the class name but does not include its derivation list.
                                                    
//! Exercise 15.5:
//! Define your own version of the Bulk_quote class.
//!
//! Exercise 15.6:
//! Test your print_total function from the exercises in § 15.2.1 (p. 595)
//! by passing both Quote and Bulk_quote objects to that function.
//!

#include <iostream>
#include <cstddef>
#include "Quote.h"
#include "Bulk_quote.h"
using namespace std;

double print_total(ostream& os, const Quote& item, size_t n);

int main()
{
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);

    print_total(cout, q, 12);
    print_total(cout, bq, 12);
    return 0;
}

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret=item.net_price(n);

    os<<"ISBN: "<<item.isbn()<<" # sold: "<<" total due: "<<ret<<endl;
    return ret;
}
