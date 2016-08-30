#ifndef Bulk_quote_h
#define Bulk_quote_h

#include <string>
#include <cstddef>
#include "Quote.h"
using namespace std;

class Bulk_quote : public Quote {
public:
    Bulk_quote()=default;
    Bulk_quote(const string& b, double p, size_t q, double d) : Quote(b, p), min_qty(q), discount(d) {}
    double net_price(size_t) const override;
    void debug() const override;

private:
    size_t min_qty=0;
    double discount=0.0;
};

#endif // Bulk_quote_h
