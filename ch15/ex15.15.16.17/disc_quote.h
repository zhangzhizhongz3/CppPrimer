#ifndef Disc_quote_h
#define Disc_quote_h

#include <string>
#include <cstddef>
#include "Quote.h"
using namespace std;

class Disc_quote : public Quote {
public:
    Disc_quote()=default;
    Disc_quote(const string& b, double p, size_t q, double d) : Quote(b, p), quantity(q), discount(d) {}
    double net_price(size_t) const =0;
    void debug() const =0;

protected:
    size_t quantity=0;
    double discount=0.0;
};

#endif // Disc_quote_h
