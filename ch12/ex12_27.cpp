//
//  ex12_27.cpp
//  Exercise 12.27
//

#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include "ex12_27.h"

using namespace std;

TextQuery::TextQuery(ifstream &is):file(new vector<string>)
{
    string text;
    while(getline(is, text))
    {
        file->push_back(text);
        int n=file->size()-1;
        istringstream line(text);
        string word;
        while(line>>word)
        {
            //avoid read a word followed by punctuation(such as: word,)
            remove_copy_if(word.begin(), word.end(), back_inserter(word), [](const char &ch) {return isalpha(ch);});
            auto &lines=wm[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    //use static just allocate once
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

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
        os<<"\t(line "<<num+1<<") "<<qr.file->at(num)<<endl;
    return os;
}
