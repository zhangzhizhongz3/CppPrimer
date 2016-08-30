//!
//! Exercise 15.15:
//! Define your own versions of Disc_quote and Bulk_quote.
//!
//! Exercise 15.16:
//! Rewrite the class representing a limited discount strategy, which you wrote
//! for the exercises in § 15.2.2 (p. 601), to inherit from Disc_quote.
//!
//! Exercise 15.17:
//! Try to define an object of type Disc_quote and see what errors you get from
//! the compiler.
//  error: cannot declare variable 'd' to be of abstract type 'Disc_quote'
//!                 ^

#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
using namespace std;

int main()
{
    Disc_quote d;
}
