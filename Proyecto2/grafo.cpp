#include "grafo.h"

Grafo::Grafo()
{
    this->first=NULL;
    cont=0;
}

void Grafo::insertAirport(QString ciudad)
{
    Airport *temp ,*nuevo=new Airport();
    nuevo->name=ciudad;
    nuevo->next = NULL;
    nuevo->ady=NULL;
    if(first==NULL)
         {
            first = nuevo;
            nuevo->etq=cont;
            //First Airport
            cont++;
          }
        else
         {
            temp = first;
            while(temp->next!=NULL)
             {
                temp = temp->next;
              }
            temp->next = nuevo;
            nuevo->etq=cont;
            cont++;
            //Other
          }
}

void Grafo::addConnection(Airport *origin, Airport *dest, Connection *con)
{


    Connection *q;
    if(origin->ady==NULL)
    {   origin->ady=con;
        con->destination=dest;
       // cout<<"PRIMERA ARISTA....!";
    }
    else
    {   q=origin->ady;
        while(q->next!=NULL)
            q=q->next;
        con->destination=dest;
        q->next=con;
       // cout<<"ARISTA AGREGADA...!!!!";
    }
}


void Grafo::insertConnection(QString ini, QString fin, double costo)
{
       // char ini, fin;
        Connection *nuevo=new Connection();
        nuevo->price = costo;

        Airport*aux, *aux2;

        if(first==NULL)
         {
             cout<<"GRAFO VACIO...!!!!";
             return;
         }
        nuevo->next=NULL;

        aux=first;
        aux2=first;
        while(aux2!=NULL)
        {
            if(aux2->name==fin)
            {
                break;
            }

            aux2=aux2->next;
        }
        while(aux!=NULL)
        {
            if(aux->name==ini)
            {
                addConnection(aux,aux2, nuevo);
                return;
            }
            aux = aux->next;
        }
}

void Grafo::ImprimirGrafo()
{
    Airport *ptr=first;
    Connection *con;

    cout<<"AEROPUERTO|LISTA DE ADYACENCIA\n";

    while(ptr!=NULL)
    {  // cout<<"   "<<ptr->name.toStdString()<<"|";
         cout<<  ptr->name.toStdString();
        if(ptr->ady!=NULL)
        {
           con=ptr->ady;


            while(con!=NULL)
            {   cout<<" "<<con->price<<" "
                     <<con->destination->name.toStdString()<<endl;
                con=con->next;
            }

        }
        ptr=ptr->next;
        cout<<endl;
    }
}

void Grafo::ImprimirConexiones(QString name)
{
    Airport *aux;
    Connection *ar;

    aux=first;
    while(aux!=NULL)
    {
        if(aux->name==name)
        {
            if(aux->ady==NULL)
            {   cout<<"EL AEROPUERTO NO TIENE CONEXIONESS...!!!!";
                return;
            }
            else
            {
                cout<<"AEROPUERTO|LISTA DE ADYACENCIA\n";
                cout<<"   "<<aux->name.toStdString()<<"|";
                ar=aux->ady;

                while(ar!=NULL)
                {
                    cout<<ar->destination->name.toStdString()<<" ";
                    ar=ar->next;
                }
                cout<<endl;
                return;
            }
        }
        else
        aux=aux->next;
    }



}

double Grafo::MinimoAdj(QString  origen)
{

    Airport *aux=first;
    Connection *ar;
    double min=10000;
    Airport *sig;




   while(aux!=NULL)
    {

        if(aux->name==origen){
                cout<<"llego"<<endl;
                 if(aux->ady!=NULL) {
                    ar=aux->ady;

                    while(ar!=NULL)
                    {
                      if(min>ar->price){
                          min=ar->price;
                              sig=ar->destination;
                              sig->dist=min;
                      }



                    ar=ar->next;
                    }

                }

        }

        aux=aux->next;


    }
      cout<< "NOdo Menor"<<sig->name.toStdString()<<endl;
      cout<< "Precio Min: "<<min;
      return min;
}

Airport * Grafo::MinimoAdjAirp(QString  origen)
{

    Airport *aux=first;
    Connection *ar;
    double min=10000;
    Airport *sig;




   while(aux!=NULL)
    {

        if(aux->name==origen){
                cout<<"llego"<<endl;
                 if(aux->ady!=NULL) {
                    ar=aux->ady;

                    while(ar!=NULL)
                    {
                      if(min>ar->price){
                          min=ar->price;
                              sig=ar->destination;
                              sig->dist=min;
                      }
                    ar=ar->next;
                    }

                }
        }

        aux=aux->next;


    }
      cout<< "NOdo Menor"<<sig->name.toStdString()<<endl;
      cout<< "Precio Min: "<<min;
      return sig;
}


double Grafo::MinimoAirp(QString orgen, QString destino)
{
    Airport *aux=first,*aux2=first,*org,*dest,*tem;
    vector<double> distancias;
    list<Airport> visitados;
    list<Airport> :: iterator itList;
    QString te=orgen;

    while(aux!=NULL){

        if(aux->name==orgen){

            org=aux;
        }

        if(aux->name==destino){
            dest=aux;

        }

        aux=aux->next;


    }

    while(aux2!=NULL){




        if(aux2==org){
            this->minimo+=this->MinimoAdj(orgen);

            org=MinimoAdjAirp(te);

            cout<<tem->name.toStdString();


        }
            aux2=aux2->next;

    }

    return this->minimo;

}

int Grafo::MatrizAdj(int inicial,int final)
{
    Airport *aux=first;
    Connection *ar;

    double matA[cont][cont];

    for(int i=0;i<cont;i++){
        for(int j=0;j<cont;j++)
            matA[i][j]=10000;

    }

    int x=0;
    while(aux!=NULL)
    {

        if(aux->ady!=NULL)
        {
            ar=aux->ady;
            while(ar!=NULL)
            {
                matA[x][ar->destination->etq] = ar->price;

                ar=ar->next;

            }

        }
        x++;
        aux=aux->next;
        //cout<<endl;

    }
    //imprimir
    for(int i=0;i<cont;i++){

        for(int j=0;j<cont;j++){
            cout<<matA[i][j]<<" ";

        }
        cout<<endl;
    }


             int i, k, small;
             int d[cont];
             int path[cont];
             int visited[cont];

             for (i = 0; i <= cont; i++) {
                 d[i] = 10000;
                 visited[i] = 0;
                 path[i]=0;
                 //element i hasn't been visited
             }

             d[inicial] = 0;

             for (k = 0; k < cont; k++) {
                     small = -1;
                     for (i = 0; i < cont; i++)
                     if (!visited[i] && ((small == -1) || (d[i] < d[small])))
                         small = i;

                 visited[small] = 1;

                 for (i = 0; i < cont; i++)
                     if (matA[small][i])
                         if (d[small] + matA[small][i] < d[i]){
                             d[i] = d[small] + matA[small][i];
                             path[i]=matA[small][i];

                         }

             }

             for(int i=0;i<cont;i++)
                 cout<<path[i]<<endl;




         return d[final];

}

double Grafo::Minimo(double val1, double val2){
    if(val1<=val2)
        return val1;
    else
        return val2;

}

int  Grafo::recuperar(QString origen)
{
    int etq;
    Airport *aux=first;


    while(aux!=NULL)
     {

         if(aux->name==origen){

                 etq=aux->etq;

         }

         aux=aux->next;
     }

    return etq;
}

void Grafo::dijkstra(int Origen)
{

//    int Aux[cont], VertInc[cont], Ver1, Ver2, Ind1, Ind2, Menor, Band,
//    Origen;
//    /* El arreglo VertInc se utiliza para guardar los vértices elegidos
//    ➥por ser los de la distancia mínima. El arreglo Aux es un arreglo
//    ➥lógico que indica si el nodo de la posición i ya fue incluido en
//    ➥VertInc y de esta manera evitar ciclos. */
//    for (Ind1= 0; Ind1 < cont; Ind1++)
//    {
//     Aux[Ind1]= 0;
//     VertInc[Ind1]= 0;
//    }
//    cout<<"\n\n Ingrese vértice origen: ";
//    cin>>Origen;
//    Aux[Origen – 1]= 1;
//    /* El arreglo donde se guardan las distancias mínimas del Origen a
//    ➥los demás vértices se inicializa con los valores de la matriz de
//    ➥adyacencia. */
//    /*for (Ind1= 0; Ind1 < cont; Ind1++)
//    DistMin[Ind1]= MatAdy[Origen][Ind1];
//    for (Ind1= 0; Ind1<cont; Ind1++)
//    {
//     Se busca el vértice Ver1 en (Vertices - VertInc) tal que
//    ➥DistMin[Ver1] sea el mínimo valor. Se usa el 999 como valor
//    ➥inicial ya que es el elegido para indicar que no existe camino
//    ➥entre dos vértices. */
//    Menor= 9999;
//    for (Ind2= 1; Ind2 < cont; Ind2++)
//    if (DistMin[Ind2] < Menor && !Aux[Ind2])
//    {
//    Ver1= Ind2;
//    Menor= DistMin[Ind2];
//    }
//    /* Se incluye Ver1 a VertInc y se actualiza el arreglo Aux. */
//    VertInc[Ind1]= Ver1;
//    Aux[Ver1]= 1;
//    /* Se busca la distancia mínima para cada vértice Ver2 en(Vertices - VertInc). */
//    Ver2= 1;
//    while (Ver2 < cont)
//    {
//        Band=0;
//        Ind2= 1;
//        while (Ind2 < cont && !Band)
//        if (VertInc[Ind2] == Ver2)
//        Band= 1;
//        else
//        Ind2++;
//        if (!Band)
//        DistMin[Ver2]=  Minimo (DistMin[Ver2],DistMin[Ver1] + MatAdy[Ver1][Ver2]);
//        Ver2++;
//    }
//    }

}




