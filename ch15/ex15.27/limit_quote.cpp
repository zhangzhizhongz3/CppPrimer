#include <iostream>
#include <cstddef>
#include "Limit_quote.h"

double Limit_quote::net_price(size_t n) const
{
    if(n<=quantity)
        return n*price*(1-discount);
    else
        return quantity*price*(1-discount)+(n-quantity)*price;
}

void Limit_quote::debug() const
{
    Quote::debug();
    cout<<"max_qty= "<<quantity<<" "
        <<"discount= "<<discount<<" ";
}
