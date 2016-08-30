#ifndef Bulk_quote_h
#define Bulk_quote_h

#include <string>
#include <cstddef>
#include "Disc_quote.h"
using namespace std;

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote()=default;
    Bulk_quote(const string& b, double p, size_t q, double d) : Disc_quote(b, p, q, d) {}
    double net_price(size_t) const override;
    void debug() const override;
};

#endif // Bulk_quote_h
