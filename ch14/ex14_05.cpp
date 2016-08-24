#include <iostream>
#include "ex14_05.h"

std::istream& operator>>(std::istream& is, Book& book)
{
    is >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_;
    if(!is)
        book=Book();
    return is;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os<<book.no_<<" "<<book.name_<<" "<<book.author_<<" "<<book.pubdate_;
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
