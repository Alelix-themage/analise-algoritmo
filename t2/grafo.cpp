/*========================================================================================================
    Alessandro Luis Pinheiro da Rocha Junior                Codigo: 2230837
    Bruno Saraiva                                           Codigo: 2185932
    Mateus de Castro                                        Codigo: 2200040
    Sergio Luis Filippin                                    Codigo: 2259500
=========================================================================================================*/

#include "grafo.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

// Le o arquivo e monta a lista de adjacencia.
// Complexidade aproximada: O(E log E), por causa da ordenacao dos vizinhos.
ListaAdjacencia lerGrafo(string nomeArquivo, bool digrafo, bool ponderado) {
    ListaAdjacencia grafo;
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return grafo;
    }

    string linha;

    while (getline(arquivo, linha)) {
        if (linha.empty()) {
            continue;
        }

        stringstream ss(linha);
        string origemTexto, destinoTexto, pesoTexto;

        getline(ss, origemTexto, ';');
        getline(ss, destinoTexto, ';');

        if (origemTexto.empty() || destinoTexto.empty()) {
            continue;
        }

        char origem = origemTexto[0];
        char destino = destinoTexto[0];
        int peso = 1;

        if (ponderado) {
            getline(ss, pesoTexto, ';');
            peso = stoi(pesoTexto);
        }

        grafo[origem].push_back({destino, peso});

        if (grafo.find(destino) == grafo.end()) {
            grafo[destino] = {};
        }

        if (!digrafo) {
            grafo[destino].push_back({origem, peso});
        }
    }

    arquivo.close();

    for (auto &vertice : grafo) {
        sort(vertice.second.begin(), vertice.second.end());
    }

    return grafo;
}

void imprimirGrafo(const ListaAdjacencia &grafo, string nome, bool ponderado) {
    cout << nome << " - Lista de adjacencia:" << endl;

    for (auto vertice : grafo) {
        cout << vertice.first << ": ";

        for (int i = 0; i < vertice.second.size(); i++) {
            pair<char, int> vizinho = vertice.second[i];

            if (ponderado) {
                cout << "(" << vizinho.first << ", " << vizinho.second << ")";
            } else {
                cout << vizinho.first;
            }

            if (i + 1 < vertice.second.size()) {
                cout << ", ";
            }
        }

        cout << endl;
    }

    cout << endl;
}
