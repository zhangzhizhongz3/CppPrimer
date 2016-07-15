//
//  ex7_27_TEST.cpp
//  Test of Exercise 7.27
//
//  Created by pezy on 11/14/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#include "ex7_27.h"
#include <iostream>
using std::cout;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";

}
