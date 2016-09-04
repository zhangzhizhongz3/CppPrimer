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
#include <string>
#include <vector>
#include <memory>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"


int main()
{
    /**
     * @brief ex15.28   outcome == 9090
     */
    std::vector<Quote> v;
    for(unsigned i =1; i != 10; ++i)
        v.push_back(Bulk_quote("sss", i * 10.1, 10, 0.3));

    double total = 0;
    for (const auto& b : v)
    {
        total += b.net_price(20);
    }
    std::cout << total << std::endl;

    std::cout << "======================\n\n";

    /**
     * @brief ex15.29   outccome == 6363
     */
    std::vector<std::shared_ptr<Quote>> pv;

    for(unsigned i =1; i != 10; ++i)
        pv.push_back(std::make_shared<Bulk_quote>(Bulk_quote("sss", i * 10.1, 10, 0.3)));

    double total_p = 0;
    for (auto p : pv)
    {
        total_p +=  p->net_price(20);
    }
    std::cout << total_p << std::endl;

    return 0;

}
