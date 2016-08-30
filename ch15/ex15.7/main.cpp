//!
//! Exercise 15.7:
//! Define a class that implements a limited discount strategy, which applies
//! a discount to books purchased up to a given limit. If the number of copies
//! exceeds that limit, the normal price applies to those purchased beyond the
//! limit.
//!

#include <iostream>
#include <cstddef>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
using namespace std;

double print_total(ostream& os, const Quote& item, size_t n);

int main()
{
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.6, 10, 0.3);
    Limit_quote lq("Bible", 10.6, 10, 0.3);

    print_total(cout, q, 5);
    print_total(cout, bq, 5);
    print_total(cout, lq, 5);
}

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret=item.net_price(n);

    os<<"ISBN: "<<item.isbn()<<" # sold: "<<" total due: "<<ret<<endl;
    return ret;
}
