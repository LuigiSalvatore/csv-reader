#include "ListaDeDatas.hpp"
#define DEBUG1
// #define DEBUG

ListaDeDatas::ListaDeDatas()
{
    head = nullptr;
    count = 0;
}
void NodoData::setData(string data) { this->data = data; }
void NodoData::setFrequencia(int frequencia) { this->frequencia = frequencia; }
string NodoData::getData() { return data; }
int NodoData::getFrequencia() { return frequencia; }
void NodoData::addFrequencia() { frequencia++; }
int ListaDeDatas::compareData(string n1, string n2)
{
    if (n1.compare(n2) < 0)
        return 0;
    else if (n1.compare(n2) > 0)
        return 1;
    else
        return 2;
}
void ListaDeDatas::addDatas(string data, int frequencia)
{
    NodoData *novo = new NodoData(data, frequencia);
    NodoData *aux = head;

    if (count == 0)
    {
        head = novo;
        count++;
#ifdef DEBUG
        cout << "attribuiu head para novo" << endl;
#endif
        return;
    }
    else
    {
        while (aux != nullptr)
        {
            if (compareData(aux->data, novo->data) == 2)
            {
                aux->addFrequencia();
                return;
            }
            aux = aux->prox;
        }

#ifdef DEBUG
        cout << "entrou no segundo while" << endl;
        cin.ignore();
#endif
        aux = head;
        while (aux->prox != nullptr) // adiciona um ponteiro para o ultimo
        {
#ifdef DEBUG
            cout << "aux prox" << endl;
            cout << &aux << "\t\t" << &aux->prox << endl;
            cin.ignore();
#endif
            aux = aux->prox;
        }
        aux->prox = novo;
        count++;
    }
}
string NodoData::str()
{
    stringstream ss;
    ss << data << "\t\t" << frequencia << endl;
    return ss.str();
}
string ListaDeDatas::str()
{
    NodoData *aux = head;
    if (count == 0)
    {
        return "Sem Nenhuma Data!";
    }
    stringstream ss;
    ss << "Data\t\tFrequencia" << endl;
    while (aux->prox != nullptr)
    {
        ss << aux->str();
        aux = aux->prox;
    }
    return ss.str();
}
NodoData::NodoData(string data, int frequencia)
{
    this->data = data;
    this->frequencia = frequencia;
    prox = nullptr;
}
void ListaDeDatas::forceImprime()
{
    NodoData *aux = head;
    cout << "Data\t\tFrequencia" << endl;
    cout << endl;

    while (aux != nullptr)
    {
        cout << aux->data << "\t\t" << aux->frequencia << endl;
        aux = aux->prox;
    }
    return;
}