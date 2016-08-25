#ifndef StrBlob_h
#define StrBlob_h

#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <memory>
#include <initializer_list>
using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

//=================================================================================
//
//		StrBlob - custom vector<string>
//
//=================================================================================

class StrBlob {
friend class StrBlobPtr;
friend class ConstStrBlobPtr;
friend bool operator==(const StrBlob&, const StrBlob&);
friend bool operator!=(const StrBlob&, const StrBlob&);
friend bool operator<(const StrBlob&, const StrBlob&);
friend bool operator>(const StrBlob&, const StrBlob&);
friend bool operator<=(const StrBlob&, const StrBlob&);
friend bool operator>=(const StrBlob&, const StrBlob&);

public:
    using size_type = vector<string>::size_type;

    StrBlob():data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)) {}

    StrBlob(const StrBlob& sb):data(make_shared<vector<string>>(*sb.data)) {}
    StrBlob& operator=(const StrBlob&);

    StrBlob(StrBlob&& sb) noexcept : data(std::move(sb.data)) {}
    StrBlob& operator=(StrBlob&&) noexcept;

    StrBlobPtr begin();
    StrBlobPtr end();

    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string& s) { data->push_back(s); }
    void push_back(string&& s) { data->push_back(std::move(s)); }

    void pop_back();
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;

private:
    void check(size_type, const string&) const;

    shared_ptr<vector<string>> data;
};

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

inline string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::check(size_type i, const string& msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

//=================================================================================
//
//		StrBlobPtr - custom iterator of StrBlob
//
//=================================================================================

class StrBlobPtr {
friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

public:
    StrBlobPtr():curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz=0):wptr(a.data), curr(sz) {}

    string& deref() const;
    StrBlobPtr& incr();

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;


    weak_ptr<vector<string>> wptr;
    size_t curr;
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

inline string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

//=================================================================================
//
//		ConstStrBlobPtr - custom const_iterator of StrBlob
//
//=================================================================================

class ConstStrBlobPtr {
friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

public:
    ConstStrBlobPtr():curr(0) {}
    ConstStrBlobPtr(const StrBlob& a, size_t sz=0):wptr(a.data), curr(sz) {}

    const string& deref() const;
    ConstStrBlobPtr& incr();

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;

    weak_ptr<vector<string>> wptr;
    size_t curr;
};

bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

inline const string& ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

#endif
