//!
//! Exercise 15.24:
//! What kinds of classes need a virtual destructor? What operations must a
//! virtual destructor perform?
//  Generally, a base class should define a virtual destructor.
//  The destructor needs to be virtual to allow objects in the inheritance
//  hierarchy to be dynamically allocated and destroyed.
//!
//! Exercise 15.25:
//! Why did we define a default constructor for Disc_quote? What effect, if
//! any, would removing that constructor have on the behavior of Bulk_quote?
//  Without it, when building the statement below, the compiler would complain
//  that:
//  note: 'Bulk_quote::Bulk_quote()' is implicitly deleted because the default
//  definition would be ill-formed.
//  The reason is that a constructor taking 4 parameters has been defined, which
//  prevented the compiler generate synthesized version default constructor. As a
//  result, the default constructor of any class derived from it has been defined
//  as deleted. Thus the default constructor must be defined explicitly so that
//  the derived classes can call it when executing its default constructor.
//!

#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"

int main()
{
    //Bulk_quote b;
}
