//!
//! Exercise 15.26:
//! Define the Quote and Bulk_quote copy control members to do the same job
//! as the synthesized versions. Give them and the other constructors print
//! statements that identify which function is running. Write programs using
//! these classes and predict what objects will be created and destroyed.
//! Compare your predictions with the output and continue experimenting
//! until your predictions are reliably correct.
//!

#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
using namespace std;

int main()
{
    Bulk_quote bq1;
    Bulk_quote bq2("ss", 2.05, 12, 0.3);
    bq2=std::move(bq2);
}
