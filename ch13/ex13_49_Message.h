#ifndef Message_h
#define Message_h

#include <string>
#include <set>
using namespace std;

class Folder;

class Message {
friend class Folder;
friend void swap(Message&, Message&);
friend void swap(Folder&, Folder&);

public:
    explicit Message(const string &str=""):contents(str) {}
    Message(const Message&);
    Message &operator=(const Message&);
    Message(Message&&);
    Message &operator=(Message&&);
    ~Message();

    void save(Folder&);
    void remove(Folder&);

    void print_debug();

private:
    string contents;
    set<Folder*> folders;


    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message*);

    void addFldr(Folder *f) {folders.insert(f);}
    void remFldr(Folder *f) {folders.erase(f);}
};

void swap(Message&, Message&);

class Folder {
friend class Message;
friend void swap(Message&, Message&);
friend void swap(Folder&, Folder&);

public:
    Folder()=default;
    Folder(const Folder&);
    Folder &operator=(const Folder&);
    Folder(Folder&&);
    Folder &operator=(Folder&&);
    ~Folder();

    void print_debug();

private:
    set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Messages();
    void move_Messages(Folder*);

    void addMsg(Message *m) {msgs.insert(m);}
    void remMsg(Message *m) {msgs.erase(m);}
};

void swap(Folder&, Folder&);

#endif
