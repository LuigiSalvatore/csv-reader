#include "Funcs.hpp"
void orderByIntDescending(vector<pair<string, int>> &dados)
{
    for (size_t i = 0; i < dados.size() - 1; ++i)
    {
        for (size_t j = 0; j < dados.size() - i - 1; ++j)
        {
            if (dados[j].second < dados[j + 1].second)
            {
                // Swap
                pair<string, int> temp = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = temp;
            }
        }
    }
    if (dados.size() > 10)
    {
        dados.resize(10);
    }
}

void printObras(vector<pair<string, int>> &dados)
{
    cout << "Data\t\tFrequencia" << endl;
    for (auto &item : dados)
    {
        cout << item.first << "\t\t" << item.second << endl;
    }
    // cout << endl;
    // cin.ignore();
}
