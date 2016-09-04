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
    Bulk_quote() {cout<<"Bulk_quote: default constructor"<<endl;};
    //Bulk_quote(const string& b, double p, size_t q, double d) : Disc_quote(b, p, q, d) {cout<<"Bulk_quote: constructor taking 4 parameters"<<endl;}

    using Disc_quote::Disc_quote;

    //! copy constructor
    Bulk_quote(const Bulk_quote& bq) : Disc_quote(bq) {cout<<"Bulk_quote: copy constructor"<<endl;}
    //! move constructor
    Bulk_quote(Bulk_quote&& bq) noexcept : Disc_quote(std::move(bq)) {cout<<"Bulk_quote: move constructor"<<endl;}
    //! copy =
    Bulk_quote& operator=(const Bulk_quote& rhs)
    {
        Disc_quote::operator=(rhs);
        cout<<"Bulk_quote: copy ="<<endl;
        return *this;
    }
    //! move =
    Bulk_quote& operator=(Bulk_quote&& rhs) noexcept
    {
        Disc_quote::operator=(std::move(rhs));
        cout<<"Bulk_quote: move ="<<endl;
        return *this;
    }

    double net_price(size_t) const override;
    void debug() const override;

    virtual ~Bulk_quote() {cout<<"Bulk_quote: destructor"<<endl;}
};

inline bool operator!=(const Bulk_quote& lhs, const Bulk_quote& rhs)
{
    return Quote(lhs)!=Quote(rhs)||lhs.quantity!=rhs.quantity||lhs.discount!=rhs.discount;
}

#endif // Bulk_quote_h
