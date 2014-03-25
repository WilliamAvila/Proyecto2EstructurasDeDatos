#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
#include <QString>
class Connection;
class Airport
{
public:
    Airport();
    QString name;//nombre del vertice o nodo
    Airport *next;
    Connection *ady;
    double dist;
    bool visto;
    int etq;
};

#endif // AIRPORT_H
