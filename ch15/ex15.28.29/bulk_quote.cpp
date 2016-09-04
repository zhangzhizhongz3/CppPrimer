#include <iostream>
#include <cstddef>
#include "Bulk_quote.h"
using namespace std;

double Bulk_quote::net_price(size_t n) const
{
    return n*price*(n>=quantity ? 1-discount : 1);
}

void Bulk_quote::debug() const
{
    Quote::debug();
    cout<<"min_qty= "<<quantity<<" "
        <<"discount= "<<discount<<" ";
}
