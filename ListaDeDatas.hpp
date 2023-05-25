
#include <string>
#include <sstream>
#include <iostream>

#ifndef _NODO_DATA
#define _NODO_DATA
using namespace std;

class NodoData
{
public:
    string data;
    int frequencia;
    NodoData *prox; // ponteiro para o próximo da lista

    NodoData(string data = "00/00/0000", int frequencia = 0);
    void setData(string data);
    void setFrequencia(int frequencia);
    string getData();
    int getFrequencia();
    void addFrequencia();
    string str();
};
#endif // _NODO_DATA

#ifndef LISTA_DE_DATAS
#define LISTA_DE_DATAS

class ListaDeDatas
{
private:
    NodoData *head;
    int count;

public:
    ListaDeDatas();

    int compareData(string n1, string n2);
    void addDatas(string data = "00/00/0000", int frequencia = 0);
    string str();
    void forceImprime();
};

#endif // LISTA_DE_DATAS