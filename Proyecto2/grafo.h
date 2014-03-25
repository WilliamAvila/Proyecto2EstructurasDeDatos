#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include "airport.h"
#include "connection.h"
#include <iostream>
#include <QString>
#include <vector>
#include <list>
#include <deque>
using namespace std;


class Grafo
{
public:
    Grafo();
    Airport *first;
    int cont;
    void insertAirport(QString ciudad);
    void addConnection(Airport *,Airport *,Connection *);
    void insertConnection(QString ,QString,double);
    void ImprimirGrafo();
    void ImprimirConexiones(QString);
    void Dijkstra(QString, QString);
    double MinimoAdj(QString  origen);
    double MinimoAirp(QString ,QString);
    double minimo;
    Airport * MinimoAdjAirp(QString  origen);




    int MatrizAdj(int inicial, int final);

    double Minimo(double val1, double val2);
    int recuperar(QString);
    void dijkstra(int Origen);
};

#endif // GRAFO_H
