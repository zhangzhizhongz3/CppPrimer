//
//  ex7_50.h
//  Exercise 7.50
//
//  Created by pezy on 11/24/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @See ex7_22.h
//  @Add constructors should be explicit

#ifndef CP5_ex7_50_h
#define CP5_ex7_50_h

#include <string>
#include <iostream>

class Person;
std::istream& read(std::istream&, Person&);

class Person {
    friend std::istream& read(std::istream&, Person&);
    friend std::ostream& print(std::ostream&, const Person&);

public:
    Person() = default;
    Person(const std::string &sname, const std::string &saddr) : name(sname), address(saddr) {}
    explicit Person(std::istream& is) { read(is, *this); }

    const std::string &getName() const { return name; }
    const std::string &getAddress() const { return address; }
private:
    std::string name;
    std::string address;
};

std::istream& read(std::istream& is, Person& person)
{
    is >> person.name >> person.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& person)
{
    os << person.name << " " << person.address;
    return os;
}

#endif
