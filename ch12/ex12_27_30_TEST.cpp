//
//  ex12_27_TEST.cpp
//  Exercise 12.27
//

#include <iostream>
#include <fstream>
#include "ex12_27.h"

using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);

    while(true)
    {
        cout<<"enter word to look for, or q to quit: ";
        string s;

        if(!(cin>>s)||s=="q")
            break;

        print(cout, tq.query(s))<<endl;
    }
}

int main()
{
    ifstream file("E:\\zzz.txt");
    runQueries(file);
}
