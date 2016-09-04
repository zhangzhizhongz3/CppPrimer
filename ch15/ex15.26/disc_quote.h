#ifndef Disc_quote_h
#define Disc_quote_h

#include <string>
#include <cstddef>
#include <utility>
#include "Quote.h"
using namespace std;

class Disc_quote : public Quote {
friend bool operator!=(const Disc_quote&, const Disc_quote&);
public:
    Disc_quote() {cout<<"Disc_quote: default constructor"<<endl;}
    Disc_quote(const string& b, double p, size_t q, double d) : Quote(b, p), quantity(q), discount(d) {cout<<"Disc_quote: constructor taking 4 parameters"<<endl;}

    //! copy constructor
    Disc_quote(const Disc_quote& dq) : Quote(dq), quantity(dq.quantity), discount(dq.discount) {cout<<"Disc_quote: copy constructor"<<endl;}
    //! move constructor
    Disc_quote(Disc_quote&& dq) noexcept : Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) {cout<<"Disc_quote: move constructor"<<endl;}
    //! copy =
    Disc_quote& operator=(const Disc_quote& rhs)
    {
        Quote::operator=(rhs);
        quantity=rhs.quantity;
        discount=rhs.discount;
        cout<<"Disc_quote: copy ="<<endl;
        return *this;
    }
    //! move =
    Disc_quote& operator=(Disc_quote&& rhs) noexcept
    {
        Quote::operator=(std::move(rhs));
        quantity=std::move(rhs.quantity);
        discount=std::move(rhs.discount);
        cout<<"Disc_quote: move ="<<endl;
        return *this;
    }

    double net_price(size_t) const =0;
    void debug() const =0;

    ~Disc_quote() {cout<<"Disc_quote: destructor"<<endl;}

protected:
    size_t quantity=0;
    double discount=0.0;
};

inline bool operator!=(const Disc_quote& lhs, const Disc_quote& rhs)
{
    return Quote(lhs)!=Quote(rhs)||lhs.quantity!=rhs.quantity||lhs.discount!=rhs.discount;
}

#endif // Disc_quote_h
