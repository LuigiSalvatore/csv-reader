#include "ListaRua.hpp"

ListaRua::ListaRua()
{
    primeirarua = new NodoRua("");
    ultimarua = new NodoRua("");
    primeirarua->prox = ultimarua;
    ultimarua->ant = primeirarua;
    totalRuas = 0;
}
int ListaRua::comparaRua(string n1, string n2)
{
    if (n1.compare(n2) < 0)
        return 0;
    else if (n1.compare(n2) > 0)
        return 1;
    else
        return 2;
}
string ListaRua::removeSubstrings(const string input, string &removedSubstring)
{
    string result = input;
    size_t found;

    // Remove "TRAV"
    if ((found = result.find("TRAV ")) != string::npos)
    {
        result.erase(found, 5); // 4 is the length of "TRAV"
        removedSubstring = "TRAV";
    }
    // Remove "AV"
    else if ((found = result.find("AV ")) != string::npos)
    {
        result.erase(found, 3); // 2 is the length of "AV"
        removedSubstring = "AV";
    }
    // Remove "R"
    else if ((found = result.find("R ")) != string::npos)
    {
        result.erase(found, 2); // 1 is the length of "R"
        removedSubstring = "R";
    }
    else
    {
        removedSubstring = ""; // No substring removed
    }

    return result;
}
void ListaRua::addRua(string n, double la, double lo, string l, string d, string da, string prefix)
{

    // nname = removePrefix(n);
    // nprefix = getPrefix(n);

    NodoRua *novo = new NodoRua(n, prefix);
    // addNameAndPrefix(n, novo);
    // se não há ruas na lista, insere a nova no inicio
    if (totalRuas == 0)
    {
        primeirarua = novo;
        novo->placas->addPlaca(la, lo, l, d, da);
        totalRuas++;
        return;
    }
    else // se há ruas na lista, faz a função abaixo
    {
        NodoRua *aux = primeirarua;
        while (aux->prox != nullptr)
        {
            aux = aux->prox;
        }
        ultimarua = aux;

        // percorre a lista até o final para verificar ruas duplicadas
        aux = primeirarua;
        while (aux != nullptr)
        {
            if (comparaRua(aux->nome, novo->nome) == 2)
            {
                aux->placas->addPlaca(la, lo, l, d, da);
                return;
            }
            aux = aux->prox;
        }
        if (addRuaAntes(novo->nome, la, lo, l, d, da, prefix) == 1) // se a rua nova não for maior que as da lista, ela automaticamente vai pro final
        {
            return;
        }
        else
        {
            ultimarua->prox = novo;
            novo->ant = ultimarua;
            ultimarua = novo;
            ultimarua->placas->addPlaca(la, lo, l, d, da);
            totalRuas++;
        }
    }
}
int ListaRua::addRuaAntes(string n, double la, double lo, string l, string d, string da, string prefix)
{
    // string nname = n, nprefix = "";
    // nname = removeSubstrings(n, nprefix);

    // nname = removePrefix(n);
    // nprefix = getPrefix(n);

    NodoRua *novo = new NodoRua(n, prefix);
    NodoRua *aux = primeirarua;
    // percorre a lista para ver se a rua nova é maior que as ruas na lista
    while (aux != nullptr)
    {
        if (comparaRua(aux->nome, novo->nome) == 1)
        {
            // se a rua nova for "maior" que a rua anterior, insere ela antes
            if (aux->ant == nullptr)
            {
                primeirarua = novo;
                novo->ant = aux->ant;
                novo->prox = aux;
                aux->ant = novo;
                novo->placas->addPlaca(la, lo, l, d, da);
                totalRuas++;
                return 1;
            }
            else
            {
                aux->ant->prox = novo;
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant = novo;
                novo->placas->addPlaca(la, lo, l, d, da);
                totalRuas++;
                return 1;
            }
        }
        aux = aux->prox;
    }
    return 0;
}
void ListaRua::imprimeLista()
{
    NodoRua *aux = primeirarua;
    if (totalRuas == 0)
    {
        return;
    }
    while (aux != nullptr)
    {

        cout << aux->prefixo << " " << aux->nome << endl;
        aux = aux->prox;
    }
    cout << "fim da lista" << endl;
}
int ListaRua::noLocation()
{
    int noLalo = 0;
    NodoRua *aux = primeirarua;
    while (aux != nullptr)
    {
        NodoPlaca *temp = aux->placas->primeiraplaca;
        while (temp != nullptr)
        {
            if ((temp->latitude) == 0 && (temp->longitude) == 0)
            {
                noLalo++;
            }
            temp = temp->prox;
        }
        aux = aux->prox;
    }
    return noLalo;
}
void ListaRua::navega()
{
    NodoRua *aux = primeirarua->prox;
    char input = 'Y';
    char placas = ' ';
    while (input == 'Y' || input == 'y')
    {
        cout << "Voce esta atualmente na rua: " << aux->nome << "." << endl;
        cout << "Voce gostaria de saber mais sobre as placas desta rua? Y/N " << endl;
        cin >> placas;
        if (placas == 'y' || placas == 'Y')
        {
            cout << "Numero de placas na rua: " << aux->placas->totalPlacas << endl;
            cout << endl;
            cout << "Primeira placa registrada: " << endl;
            cout << "Desrcicao: " << aux->placas->primeiraplaca->desc << endl;
            cout << "Data: " << aux->placas->primeiraplaca->data << endl;
            if (aux->placas->primeiraplaca->latitude == 0)
            {
                cout << "Latitude: indefinida" << endl;
                cout << "Longitude: indefinida" << endl;
            }
            else
            {
                cout << "Latitude: " << aux->placas->primeiraplaca->latitude << endl;
                cout << "Longitude: " << aux->placas->primeiraplaca->longitude << endl;
            }
            cout << "Localizacao: " << aux->placas->primeiraplaca->localizacao << endl;
            cout << endl;
            cout << "Ultima placa registrada: " << endl;
            NodoPlaca *ultimaplaca = aux->placas->primeiraplaca;
            while (ultimaplaca->prox != nullptr)
            {
                ultimaplaca = ultimaplaca->prox;
            }
            cout << "Desrcicao: " << ultimaplaca->desc << endl;
            cout << "Data: " << ultimaplaca->data << endl;
            if (ultimaplaca->latitude == 0)
            {
                cout << "Latitude: indefinida" << endl;
                cout << "Longitude: indefinida" << endl;
            }
            else
            {
                cout << "Latitude: " << ultimaplaca->latitude << endl;
                cout << "Longitude: " << ultimaplaca->longitude << endl;
            }
            cout << "Localizacao: " << ultimaplaca->localizacao << endl;
            cout << endl;
            aux->placas->sinalregRua();
            cout << endl;
        }
        char move = ' ';
        cout << "Trocar de rua? (F para ir para frente e V para voltar, N para sair) " << endl;
        cin >> move;
        if (move == 'F' || move == 'f')
        {
            aux = aux->prox;
        }
        else if (move == 'V' || move == 'v')
        {
            if (aux == primeirarua)
            {
                cout << "Nao tem rua anterior." << endl;
            }
            else
            {
                aux = aux->ant;
            }
        }
        else
        {
            cout << "Continuar no modo navegacao? Y/N ";
            cin >> input;
            if (input == 'Y' || input == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
    cout << "Saindo do modo navegacao..." << endl;
    return;
}
void ListaRua::insertStringByFrequency(const string &str, vector<pair<string, int>> &data)
{
    for (auto it = data.begin(); it != data.end(); ++it)
    {
        if (str == it->first)
        {
            it->second++;
            return;
        }
        else if (str < it->first)
        {
            data.insert(it, make_pair(str, 1));
            return;
        }
    }

    data.push_back(make_pair(str, 1));
}
void ListaRua::lerArquivo(ListaDeDatas *data)
{

    ifstream fin;
    fin.open("data.csv", ios::in);

    string line = "";
    string word = "";
    string descricao = "";
    string rua = "";
    string tiporua = "";
    string prefix = "";
    string datarua = "";
    string localplaca = "";

    double latitude = 0;
    double longitude = 0;

    int count = 0;
    getline(fin, line); // remove cabecalho
    while (fin.good())
    {
        int i = 0;
        getline(fin, word);
        stringstream ss(word);
        while (getline(ss, word, ';'))
        {
            switch (i)
            {
            case DESCRICAO:
                descricao = word;
                break;
            case IMPLANTACAO:

                // insertStringByFrequency(word, dados);
                datarua = word;
                break;
            case LOGRADOURO_NOME:
                rua = removeSubstrings(word, prefix);
                // rua = word;
                break;
            case LATITUDE:
                localplaca = word;
                ss << word;
                ss >> latitude;
                break;
            case LONGITUDE:
                ss << word;
                ss >> longitude;
                break;
            default:
                break;
            }
            i++;
        }
        if (latitude == 0 || longitude == 0)
        {
            latitude = 0;
            longitude = 0;
        }
        addRua(rua, latitude, longitude, localplaca, datarua, descricao, prefix);
        count++;
        // cout << datarua << endl;
        // cin.ignore();
        data->addDatas(datarua);
#ifdef MESSAGE
        if (count % 10000 == 0)
            cout << (static_cast<double>(count) / 92288) * 100 << endl;
            // cout << count << " -> ruas adicionadas" << endl;

#endif
    }
    fin.close();
#ifdef DEBUG
    imprimeLista();
#endif
}
NodoRua::NodoRua(string n, string p)
{
    prefixo = p;
    nome = n;
    prox = nullptr;
    ant = nullptr;
}
void NodoRua::setPrefix(string p) { prefixo = p; }
void NodoRua::setNome(string n) { nome = n; }
string NodoRua::getPrefix() { return prefixo; }
