#include <string>
#include <iostream>
#include "ListaPlaca.hpp"

using namespace std;

ListaPlaca::ListaPlaca()
{
    primeiraplaca = new NodoPlaca();
    totalPlacas = 0;
}
int ListaPlaca::comparaPlaca(string p1, string p2)
{
    if (p1.compare(p2) < 0)
        return 0;
    else if (p1.compare(p2) > 0)
        return 1;
    else
        return 2;
}
// adiciona uma placa para a lista
void ListaPlaca::addPlaca(double la, double lo, string l, string d, string da)
{
    // novo NodoPlaca
    NodoPlaca *novo = new NodoPlaca(la, lo, l, d, da);
    // se a lista estiver vazia, a primeira placa vira a nova placa
    if (totalPlacas == 0)
    {
        primeiraplaca = novo;
        totalPlacas++;
        return;
    }
    else if (totalPlacas >= 1)
    { // se a lista não estiver vazia, coloca a placa no final da lista
        NodoPlaca *aux = primeiraplaca;
        while (aux->prox != nullptr)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = nullptr;
        totalPlacas++;
        return;
    }
}
// apresentar o numero total de sinalizações registradas em uma rua especifica
void ListaPlaca::sinalregRua()
{
    double porcentagem;
    porcentagem = 100 * (totalPlacas / 91229);
    cout << "A quantidade de placas nesta rua e " << totalPlacas << ", que e equivalente a " << porcentagem << "% do total de placas." << endl;
}
void ListaPlaca::imprimePlacas()
{
    NodoPlaca *aux = primeiraplaca;
    if (totalPlacas == 0)
    {
        return;
    }
    while (aux != nullptr)
    {
        cout << "Descricao da placa: " << aux->desc << endl;
        cout << "Data da placa: " << aux->data << endl;
        cout << "Localizacao da placa: " << aux->localizacao << endl;
        cout << "Latitude da placa: " << aux->latitude << endl;
        cout << "Longitude da placa: " << aux->longitude << endl;
        cout << endl;
        aux = aux->prox;
    }
    cout << "fim da lista de placas" << endl;
}
NodoPlaca::NodoPlaca(double la, double lo, string l, string d, string de)
{
    latitude = la;
    longitude = lo;
    localizacao = l;
    data = d;
    desc = de;
    prox = nullptr;
}
