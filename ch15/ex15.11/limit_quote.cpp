#include <iostream>
#include <cstddef>
#include "Limit_quote.h"

double Limit_quote::net_price(size_t n) const
{
    if(n<=max_qty)
        return n*price*(1-discount);
    else
        return max_qty*price*(1-discount)+(n-max_qty)*price;
}

void Limit_quote::debug() const
{
    Quote::debug();
    cout<<"max_qty= "<<max_qty<<" "
        <<"discount= "<<discount<<" ";
}
