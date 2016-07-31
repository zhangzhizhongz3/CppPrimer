//! @Alan
//!
//! Exercise 9.51:
//! Write a class that has three unsigned members representing year,
//! month, and day. Write a constructor that takes a string representing
//! a date. Your constructor should handle a variety of date formats,
//! such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
//!

#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    Date(const string &s);
    unsigned year;
    unsigned month;
    unsigned day;
};

int main()
{
    Date d("1/1/1900");

    cout<<d.day<<" "<<d.month<<" "<<d.year<<endl;
}

Date::Date(const string &s)
{
    unsigned format=0;

    //! 1/1/1900
    if(s.find_first_of("/")!=string::npos)
        format=0x10;

    //! January 1, 1900 or Jan 1, 1900
    if(s.find_first_of(",")!=string::npos&&s.find_first_of(",")>=5)
        format=0x01;

    switch(format) {
    //! format=1/1/1990
    case 0x10:
        day=stoi(s.substr(0, s.find_first_of("/")));

        month=stoi(s.substr(s.find_first_of("/")+1, s.find_last_of("/")-s.find_first_of("/")-1));

        year=stoi(s.substr(s.find_last_of("/")+1, 4));

        break;

    //! format=January 1, 1900 or Jan 1, 1900
    case 0x01:
        day=stoi(s.substr(s.find_first_of("1234567890"), s.find_first_of(",")-s.find_first_of("1234567890")));

        if(s.find("Jan")!=string::npos)  month=1;
        if(s.find("Feb")!=string::npos)  month=2;
        if(s.find("Mar")!=string::npos)  month=3;
        if(s.find("Apr")!=string::npos)  month=4;
        if(s.find("May")!=string::npos)  month=5;
        if(s.find("Jun")!=string::npos)  month=6;
        if(s.find("Jul")!=string::npos)  month=7;
        if(s.find("Aug")!=string::npos)  month=8;
        if(s.find("Sep")!=string::npos)  month=9;
        if(s.find("Oct")!=string::npos)  month=10;
        if(s.find("Nov")!=string::npos)  month=11;
        if(s.find("Dec")!=string::npos)  month=12;

        year=stoi(s.substr(s.find_last_of(" ")+1, 4));

        break;
    }
}
