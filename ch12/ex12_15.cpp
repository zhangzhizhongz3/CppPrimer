//
//  ex12_15.cpp
//  Exercise 12.15
//
//  Created by pezy on 12/22/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Rewrite the first exercise to use a lambda (10.3.2, p.388) in place of the
//  end_connection function.

#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct destination {
    string ip;
    int port;
    destination(string ip_, int port_):ip(ip_), port(port_) {}
};

struct connection {
    string ip;
    int port;
    connection(string ip_, int port_):ip(ip_), port(port_) {}
};

connection connect(destination *pDest)
{
    shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    cout<<"creating connection("<<pConn.use_count()<<")"<<endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    cout<<"connection close("<<pConn.ip<<":"<<pConn.port<<")"<<endl;
}

void f(destination &d)
{
    connection conn=connect(&d);
    shared_ptr<connection> p(&conn, [](connection *pConn) { disconnect(*pConn);});
    cout<<"connecting now("<<p.use_count()<<")"<<endl;
}

int main()
{
    destination dest("202.118.176.67", 3316);
    f(dest);
}
