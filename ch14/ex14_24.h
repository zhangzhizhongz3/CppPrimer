#ifndef Date_h
#define Date_h

#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;

class Date {
//! friend
friend ostream& operator<<(ostream&, const Date&);
friend bool operator==(const Date&, const Date&);
friend bool operator<(const Date&, const Date&);
friend bool check(const Date&);

public:
    //! constructors
    //! default constructor
    Date()=default;
    //! constructor taking size_t as days
    explicit Date(size_t);
    //! constructor taking three size_t
    Date(size_t d, size_t m, size_t y):day(d), month(m), year(y) {}
    //! constructor taking iostream
    Date(istream&, ostream&);

    //! copy constructor
    Date(const Date&);
    //! copy-assignment operator
    Date& operator=(const Date&);
    //! move constructor
    Date(Date&&) noexcept;
    //! move-assignment operator
    Date& operator=(Date&&) noexcept;
    //! destructor -- in this case, user-defined destructor is not necessary
    ~Date() {cout<<"destroying"<<endl;}

    //! member functions
    size_t toDays() const;  //not implemented yet
    Date& operator+=(size_t);
    Date& operator-=(size_t);

private:
    //! tool functions

    //! data members
    size_t day=1;
    size_t month=1;
    size_t year=0;
};

static const size_t YtoD_400=146097;    //365*400=400/4-3==146097
static const size_t YtoD_100=36524;     //365*100+100/4-1==36524
static const size_t YtoD_4=1461;        //365*4+1        ==1461
static const size_t YtoD_1=365;         //365

//! normal year
static const vector<size_t> monthsVec_n={31,28,31,30,31,30,31,31,30,31,30,31};

//! leap year
static const vector<size_t> monthsVec_l={31,29,31,30,31,30,31,31,30,31,30,31};

istream& operator>>(istream&, Date&);
ostream& operator<<(ostream&, const Date&);
bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator<(const Date&, const Date&);
bool operator>(const Date&, const Date&);
bool operator<=(const Date&, const Date&);
bool operator>=(const Date&, const Date&);
int operator-(const Date&, const Date&);
Date operator-(const Date&, size_t);
Date operator+(const Date&, size_t);

//! utilities
bool check(const Date&);
inline bool isLeapYear(size_t);

//! check if the date object passed in is valid
inline bool check(const Date& d)
{
    if(d.month==0||d.month>12)
        return false;
    else
    {
        //! month==1 3 5 7 8 10 12
        if(d.month==1||d.month==3||d.month==5||d.month==7||d.month==8||d.month==10||d.month==12)
        {
            if(d.day==0||d.day>31)
                return false;
            else
                return true;
        }
        else
        {
            //! month==4 6 9 11
            if(d.month==4||d.month==6||d.month==9||d.month==11)
            {
                if(d.day==0||d.day>30)
                    return false;
                else
                    return true;
            }
            else
            {
                //! month==2
                if(isLeapYear(d.year))
                {
                    if(d.day==0||d.day>29)
                        return false;
                    else
                        return true;
                }
                else
                {
                    if(d.day==0||d.day>28)
                        return false;
                    else
                        return true;
                }
            }
         }
    }
}

inline bool isLeapYear(size_t y)
{
    return ((y%4==0&&y%100!=0)||(y%400==0));
}

#endif
