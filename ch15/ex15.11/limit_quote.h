#ifndef Limit_quote_h
#define Limit_quote_h

#include <string>
#include <cstddef>
#include "Quote.h"
using namespace std;

class Limit_quote : public Quote {
public:
    Limit_quote()=default;
    Limit_quote(const string& b, double p, size_t q, double d) : Quote(b, p), max_qty(q), discount(d) {}
    double net_price(size_t) const override;
    void debug() const override;

private:
    size_t max_qty=0;
    double discount=0.0;
};

#endif // Limit_quote_h
