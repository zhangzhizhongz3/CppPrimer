//!
//! Exercise 15.28:
//! Define a vector to hold Quote objects but put Bulk_quote objects into that
//! vector. Compute the total net_price of all the elements in the vector.
//!
//! Exercise 15.29:
//! Repeat your program, but this time store shared_ptrs to objects of type
//! Quote. Explain any discrepancy in the sum generated by the this version and
//! the previous program. If there is no discrepancy, explain why there isn’t one.
//!
//  Since the vector from the previous exercise holds objects, there's no polymorphism
//  happened while calling the virtual function net_price. Essentially, the obejcts
//  held in it are the Quote subjects of the Bulk_quote objects being pushed back,
//  Thus, the virtual net_price functions called are Quote::net_price. As a result,
//  no discount was applied.
//  The obejcts held for this exercise are smart pointers to the Quote objects. In this
//  case, polymorphism happened as expected. The actual virtual functions being called
//  are Bulk_quote::net_price that ensure discount is applied.
//!

#include <iostream>
#include <vector>
#include <memory>
#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
using namespace std;

int main()
{
    //@brief ex15.28 outcome==9090
    vector<Quote> v;
    for(unsigned i=1; i!=10; ++i)
        v.push_back(Bulk_quote("sss", i*10.1, 10, 0.3));

    double total=0;
    for(const auto& e : v)
        total+=e.net_price(20);
    cout<<total<<endl;
    cout << "======================\n";

    //@brief ex15.29 outcome==6363
    vector<shared_ptr<Quote>> pv;
    for(unsigned i=1; i!=10; ++i)
        pv.push_back(make_shared<Bulk_quote>(Bulk_quote("sss", i*10.1, 10, 0.3)));

    double total_p=0;
    for(const auto& pe : pv)
        total_p+=pe->net_price(20);
    cout<<total_p<<endl;
}
