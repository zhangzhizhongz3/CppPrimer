//
//  ex7_27.h
//  Exercise 7.27
//
//  Created by pezy on 11/14/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#ifndef CP5_ex7_27_h
#define CP5_ex7_27_h

#include <string>

class Screen {
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    inline Screen& move(pos, pos);
    inline Screen& set(char);
    inline Screen& set(pos, pos, char);

    const Screen& display(std::ostream& os) const { do_display(os); return *this; }
    Screen& display(std::ostream& os) { do_display(os); return *this; }

private:
    void do_display(std::ostream& os) const { os << contents; }

    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

Screen& Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen& Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

#endif
