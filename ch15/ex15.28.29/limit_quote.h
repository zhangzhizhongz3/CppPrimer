#ifndef Limit_quote_h
#define Limit_quote_h

#include <string>
#include <cstddef>
#include "Disc_quote.h"
using namespace std;

class Limit_quote : public Disc_quote {
public:
    Limit_quote()=default;
    Limit_quote(const string& b, double p, size_t q, double d) : Disc_quote(b, p, q, d) {}
    double net_price(size_t) const override;
    void debug() const override;
};

#endif // Limit_quote_h
