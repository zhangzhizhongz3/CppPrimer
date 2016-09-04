#ifndef Quote_h
#define Quote_h

#include <iostream>
#include <string>
#include <cstddef>
#include <utility>
using namespace std;

class Quote {
friend bool operator!=(const Quote&, const Quote&);
public:
    Quote() {cout<<"Quote: default constructor"<<endl;}
    Quote(const string& b, double p) : bookNo(b), price(p) {cout<<"Quote: constructor taking 2 parameters"<<endl;}

    //! copy constructor
    Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) {cout<<"Quote: copy constructor"<<endl;}
    //! move constructor
    Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {cout<<"Quote: move constructor"<<endl;}
    //! copy =
    Quote& operator=(const Quote& rhs)
    {
        if(*this!=rhs)
        {
            bookNo=rhs.bookNo;
            price=rhs.price;
        }
        cout<<"Quote: copy ="<<endl;
        return *this;
    }
    //! move =
    Quote& operator=(Quote&& rhs) noexcept
    {
        if(*this!=rhs)
        {
            bookNo=std::move(rhs.bookNo);
            price=std::move(rhs.price);
        }
        cout<<"Quote: move ="<<endl;
        return *this;
    }

    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) const {return n*price;}
    virtual void debug() const;

    virtual ~Quote() {cout<<"Quote: destructor"<<endl;}

private:
    string bookNo;
protected:
    double price=0.0;
};

inline bool operator!=(const Quote& lhs, const Quote& rhs)
{
    return lhs.bookNo!=rhs.bookNo||lhs.price!=rhs.price;
}

#endif // Quote_h
