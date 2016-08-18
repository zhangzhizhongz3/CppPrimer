//
//  ex12_32.cpp
//  Exercise 12.32
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>
#include "ex12_32.h"

using namespace std;

TextQuery::TextQuery(ifstream &is):file(new StrBlob)
{
    string line;
    while(getline(is, line))
    {
        file->push_back(line);
        int n=file->size()-1;
        istringstream in(line);
        string text, word;
        while(in>>text)
        {
            //avoid read a word followed by punctuation(such as: word,)
            remove_copy_if(text.begin(), text.end(), back_inserter(word), [](const char &ch) {return ispunct(ch);});
            auto &lines=wm[word];
            if(!lines)
                lines.reset(new set<StrBlob::size_type>);
            lines->insert(n);
            word.clear();
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    //use static just allocate once
    static shared_ptr<set<StrBlob::size_type>> nodata(new set<StrBlob::size_type>);

    auto loc=wm.find(sought);
    if(loc==wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os<<qr.sought<<" occurs "<<qr.lines->size()<<(qr.lines->size()>1 ? " times" : " time")<<endl;
    for(auto num : *qr.lines)
    {
        ConstStrBlobPtr p(*qr.file, num);
        os<<"\t(line "<<num+1<<") "<<p.deref()<<endl;
    }
    return os;
}
