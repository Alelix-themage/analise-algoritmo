/*========================================================================================================
    Alessandro Luis Pinheiro da Rocha Junior                Codigo: 2230837
    Bruno Saraiva                                           Codigo: 2185932
    Mateus de Castro                                        Codigo: 2200040
    Sergio Luis Filippin                                    Codigo: 2259500
=========================================================================================================*/

#ifndef GRAFO_H
#define GRAFO_H

#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef map<char, vector<pair<char, int>>> ListaAdjacencia;

ListaAdjacencia lerGrafo(string nomeArquivo, bool digrafo, bool ponderado);
void imprimirGrafo(const ListaAdjacencia &grafo, string nome, bool ponderado);

#endif
