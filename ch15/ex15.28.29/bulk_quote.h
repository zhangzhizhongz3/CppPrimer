#ifndef Bulk_quote_h
#define Bulk_quote_h

#include <string>
#include <cstddef>
#include <utility>
#include "Disc_quote.h"
using namespace std;

class Bulk_quote : public Disc_quote {
friend bool operator!=(const Bulk_quote&, const Bulk_quote&);
public:
    Bulk_quote() {};
    //Bulk_quote(const string& b, double p, size_t q, double d) : Disc_quote(b, p, q, d) {}

    using Disc_quote::Disc_quote;

    //! copy constructor
    Bulk_quote(const Bulk_quote& bq) : Disc_quote(bq) {}
    //! move constructor
    Bulk_quote(Bulk_quote&& bq) noexcept : Disc_quote(std::move(bq)) {}
    //! copy =
    Bulk_quote& operator=(const Bulk_quote& rhs)
    {
        Disc_quote::operator=(rhs);

        return *this;
    }
    //! move =
    Bulk_quote& operator=(Bulk_quote&& rhs) noexcept
    {
        Disc_quote::operator=(std::move(rhs));

        return *this;
    }

    double net_price(size_t) const override;
    void debug() const override;

    virtual ~Bulk_quote() {}
};

inline bool operator!=(const Bulk_quote& lhs, const Bulk_quote& rhs)
{
    return Quote(lhs)!=Quote(rhs)||lhs.quantity!=rhs.quantity||lhs.discount!=rhs.discount;
}

#endif // Bulk_quote_h
