
#include "ListaDeDatas.hpp"
#include "ListaRua.hpp"
#include "Funcs.hpp"

using namespace std;

int main()
{
    /**/
    // vector<pair<string, int>> dados;
    ListaDeDatas *dados = new ListaDeDatas();
    ListaRua *rua = new ListaRua();
#pragma region
#ifdef MESSAGE
    // cout << "Created ListaRua" << endl;
#endif
#ifdef DEBUG
    cout << "press enter to continue..." << endl;
    cin.ignore();
    cout << "Going into ReadArq" << endl;
#endif
#ifdef MESSAGE
    cout << "Comecei a ler o arquivo... Aguarde!" << endl;
#endif
    rua->lerArquivo(dados);
    cout << "Numero de placas sem latitude e longitude = " << rua->noLocation() << endl;
    char n = ' ';
#ifdef DEBUG
    cout << "press enter to continue..." << endl;
    cin.ignore();
    cout << "going into PrintObras" << endl;
    printObras(dados);
#endif
#ifdef DEBUG
    cout << "press enter to continue..." << endl;
    cin.ignore();
    cout << "going into ordered PrintObras" << endl;
#endif
#ifdef MESSAGE
    cout << "Agora estou Organizando a lista de datas! Talvez demore um pouco!" << endl;
    cin.ignore();
#endif
    // cout << dados->str() << endl;
    dados->forceImprime();
    cin.ignore();

    // orderByIntDescending(dados);
    // printObras(dados);
#ifdef DEBUG
    cout << "press enter to continue..." << endl;
    cin.ignore();
    cout << "going into Navegation mode" << endl;
#endif
    cout << "Voce gostaria de entrar no modo navegacao? Y/N " << endl;
    cin >> n;
    if (n == 'Y' || n == 'y')
    {
        rua->navega();
    }

#ifdef DEBUG
    cout << "press enter to continue..." << endl;
    cin.ignore();
#endif
#pragma endregion

    delete rua;
    delete dados;
    return 0;
}
