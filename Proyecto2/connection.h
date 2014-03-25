#ifndef CONNECTION_H
#define CONNECTION_H
#include <iostream>
class Airport;
class Connection
{
public:
    Connection();
    double price;
    Connection *next;
    Airport *destination;
    int etq;


};

#endif // CONNECTION_H
