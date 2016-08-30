//!
//! Exercise 15.11:
//! Add a virtual debug function to your Quote class hierarchy that displays
//! the data members of the respective classes.
//!

#include <iostream>
#include <cstddef>
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
using namespace std;

void print_debug(const Quote& q);
double print_total(ostream& os, const Quote& item, size_t n);

int main()
{
    Quote q("aaa", 10.60);
    Bulk_quote bq("bbb", 111, 10, 0.3);
    Limit_quote lq("ccc", 222, 10, 0.3);

    Quote& r=q;
    r.debug();
    cout<<"\n";
    r=bq;
    r.debug();
    cout<<"\n";
    r=lq;
    r.debug();
    cout<<"\n";

    cout << "====================\n";

    print_debug(q);
    cout<<"\n";
    print_debug(bq);
    cout<<"\n";
    print_debug(lq);
    cout<<"\n";
}

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret=item.net_price(n);

    os<<"ISBN: "<<item.isbn()<<" # sold: "<<" total due: "<<ret<<endl;
    return ret;
}

void print_debug(const Quote& q)
{
    q.debug();
}
