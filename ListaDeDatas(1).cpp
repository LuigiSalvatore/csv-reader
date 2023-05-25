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
    if (count == 0)
    {
        head = novo;
        // novo->data = data;
        // novo->frequencia = frequencia;
        count++;
#ifdef DEBUG
        cout << "entrou em count ==0 " << endl;
        cout << head->data << "\t\t" << novo->data << endl;
        cin.ignore();
#endif

        return;
    }
    else
    {

        NodoData *aux = head;
        while (aux != nullptr)
        {
#ifdef DEBUG1
            cout << "entrou em while (aux != nullptr)" << endl;
            cout << aux->data << "\t\t" << novo->data << endl;
            cin.ignore();
#endif
            if (compareData(aux->data, novo->data) == 2)
            {
                novo->addFrequencia();
#ifdef DEBUG1
                cout << "retornou" << endl;
#endif
                return;
            }
#ifdef DEBUG
            cout << "aux prox" << endl;
            cout << &aux << "\t\t" << &aux->prox << endl;
            cin.ignore();
#endif
            aux = aux->prox;
        }
#ifdef DEBUG1
        cout << "terminou o while" << endl;
        cin.ignore();
#endif
        aux = novo;
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