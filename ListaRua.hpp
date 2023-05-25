#ifndef _LISTA_RUA
#define _LISTA_RUA
#include <vector>
#include <fstream>
#include <sstream>
#include "ListaPlaca.hpp"
#include "ListaDeDatas.hpp"

#pragma region
#define DATA_EXTRACAO 0
#define DESCRICAO 1
#define ESTADO 2
#define COMPLEMENTO 3
#define IMPLANTACAO 4
#define LOGRADOURO_NOME 5
#define NUM_INICIAL 6
#define NUM_FINAL 7
#define DEFRONTE 8
#define CRUZAMENTO_NOME 9
#define LADO 10
#define LOCAL_DE_INSTAL 11
#define LATITUDE 12
#define LONGITUDE 13
#pragma endregion

#ifndef _NODO_RUA
#define _NODO_RUA
// classe nodo para navegar a lista
class NodoRua
{
public:
    ListaPlaca *placas = new ListaPlaca(); // ponteiro para a lista de placas
    string nome;                           // nome da rua
    string prefixo;                        // Prefixo da rua
    NodoRua *prox;                         // ponteiro para a proxima rua
    NodoRua *ant;                          // ponteiro para a rua anterior
    // construtor do nodo
    NodoRua(string n = "", string p = "");
    void setPrefix(string p);
    void setNome(string n);
    string getPrefix();
};
#endif // _NODO_RUA

class ListaRua
{
public:
    NodoRua *primeirarua; // ponteiro para o inicio da lista de ruas
    NodoRua *ultimarua;   // ponteiro para o final da lista de ruas
    int totalRuas;        // numero total de ruas na lista

    ListaRua(); // compara pra ver se uma rua é "maior" que a outra (ordem alfabetica)
    int comparaRua(string n1, string n2);
    string removeSubstrings(const string input, string &removedSubstring); // adiciona uma rua para a lista
    void addRua(string n, double la, double lo, string l, string d, string da, string prefix);
    int addRuaAntes(string n, double la, double lo, string l, string d, string da, string prefix);
    void imprimeLista();
    int noLocation();
    void navega();
    void insertStringByFrequency(const string &str, vector<pair<string, int>> &data);
    void lerArquivo(ListaDeDatas *data);
};
#endif //_LISTA_RUA
