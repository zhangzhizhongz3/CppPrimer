#include <iostream>
#include "ex14_15.h"

Book& Book::operator+=(const Book& rhs)
{
    if(rhs==*this)
        number_+=rhs.number_;
    return *this;
}

std::istream& operator>>(std::istream& is, Book& book)
{
    is >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_>>book.number_;
    if(!is)
        book=Book();
    return is;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os<<book.no_<<" "<<book.name_<<" "<<book.author_<<" "<<book.pubdate_<<" "<<book.number_;
    return os;
}

bool operator==(const Book& lhs, const Book& rhs)
{
    return lhs.no_==rhs.no_;
}

bool operator!=(const Book& lhs, const Book& rhs)
{
    return !(lhs==rhs);
}

bool operator<(const Book& lhs, const Book& rhs)
{
    return lhs.no_<rhs.no_;
}

bool operator>(const Book& lhs, const Book& rhs)
{
    return rhs<lhs;
}

Book operator+(const Book& lhs, const Book&rhs)
{
    Book book=lhs;
    book+=rhs;
    return book;
}
