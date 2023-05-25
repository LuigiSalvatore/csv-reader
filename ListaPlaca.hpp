#ifndef _LISTA_PLACA
#define _LISTA_PLACA

#include <string>
#include <iostream>
using namespace std;

#ifndef _NODO_PLACA
#define _NODO_PLACA
using namespace std;

class NodoPlaca
{
public:
    double latitude;    // armazena a latitude da placa
    double longitude;   // armazena a longitude da placa
    string localizacao; // armazena a localização da placa (calçada, leito da via, etc.)
    string desc;        // armazena a descricao da placa
    string data;        // armazena a data de expedicao da placa
    NodoPlaca *prox;    // ponteiro para o próximo da lista
    // construtor do NodoPlaca
    NodoPlaca(double la = 0, double lo = 0, string l = "", string d = "", string de = "");
};
#endif // _NODO_PLACA

class ListaPlaca
{
public:
    NodoPlaca *primeiraplaca;
    double totalPlacas; // numero total de placas em uma rua

    // construtor da lista de placas, com valores default em 0
    ListaPlaca();
    int comparaPlaca(string p1, string p2);                             // adiciona uma placa para a lista
    void addPlaca(double la, double lo, string l, string d, string da); // apresentar o numero total de sinalizações registradas em uma rua especifica
    void sinalregRua();
    void imprimePlacas();
};
#endif // _LISTA_PLACA
