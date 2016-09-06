#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ShorterString {
public:
    bool operator()(const string &s1, const string &s2) const
    {
        return s1.size()<s2.size();
    }
};

class SizeComp {
public:
    SizeComp(size_t n) : sz(n) {}
    bool operator()(const string &s) const
    {
        return s.size()>=sz;
    }
private:
    size_t sz;
};

class Print {
public:
    void operator()(const string &s) {cout<<s<<" ";}
};

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr>1) ? word+ending : word;
}

void elimdups(vector<string> &svec)
{
    sort(svec.begin(), svec.end());
    auto new_end=unique(svec.begin(), svec.end());
    svec.erase(new_end, svec.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimdups(words);

    stable_sort(words.begin(), words.end(), ShorterString());

    auto wc=find_if(words.begin(), words.end(), SizeComp(sz));

    auto count=words.end()-wc;

    cout<<count<<" "<<make_plural(count, "word", "s")<<" of length "<<sz<<" or longer"<<endl;

    for_each(wc, words.end(), Print());

    cout<<endl;
}

int main()
{
    vector<string> svec{"fox", "jumps", "over", "quick", "red", "red", "slow",  "the",  "turtle"};
    biggies(svec, 4);
}
