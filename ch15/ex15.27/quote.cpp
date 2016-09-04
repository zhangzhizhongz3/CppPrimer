#include <iostream>
#include "Quote.h"
using namespace std;

void Quote::debug() const
{
    cout<<"data members of this class:\n"
        <<"bookNo= "<<bookNo<<" "
        <<"price= "<<price<<" ";
}
