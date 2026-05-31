/*========================================================================================================
    Alessandro Luis Pinheiro da Rocha Junior                Codigo: 2230837
    Bruno Saraiva                                           Codigo: 2185932
    Mateus de Castro                                        Codigo: 2200040
    Sergio Luis Filippin                                    Codigo: 2259500
=========================================================================================================*/

#include "grafo.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// Executa a busca em largura usando fila e retorna a ordem de visita.
vector<char> buscaLargura(const ListaAdjacencia &grafo, char inicio) {
    vector<char> ordem;
    map<char, bool> visitado;
    queue<char> fila;

    if (grafo.find(inicio) == grafo.end()) {
        return ordem;
    }

    visitado[inicio] = true;
    fila.push(inicio);

    while (!fila.empty()) {
        char atual = fila.front();
        fila.pop();
        ordem.push_back(atual);

        for (auto vizinho : grafo.at(atual)) {
            char destino = vizinho.first;

            if (!visitado[destino]) {
                visitado[destino] = true;
                fila.push(destino);
            }
        }
    }

    return ordem;
}

// Visita os vertices de forma recursiva para a busca em profundidade.
void dfsRecursiva(const ListaAdjacencia &grafo, char atual, map<char, bool> &visitado, vector<char> &ordem) {
    visitado[atual] = true;
    ordem.push_back(atual);

    for (auto vizinho : grafo.at(atual)) {
        char destino = vizinho.first;

        if (!visitado[destino]) {
            dfsRecursiva(grafo, destino, visitado, ordem);
        }
    }
}

// Executa a busca em profundidade a partir do vertice inicial.
vector<char> buscaProfundidade(const ListaAdjacencia &grafo, char inicio) {
    vector<char> ordem;
    map<char, bool> visitado;

    if (grafo.find(inicio) == grafo.end()) {
        return ordem;
    }

    dfsRecursiva(grafo, inicio, visitado, ordem);
    return ordem;
}

// Calcula o menor caminho em um grafo ponderado usando o algoritmo de Dijkstra.
// Complexidade: O((V + E) log V), usando fila de prioridade.
pair<int, vector<char>> dijkstra(const ListaAdjacencia &grafo, char origem, char destino) {
    const int infinito = numeric_limits<int>::max();
    map<char, int> distancia;
    map<char, char> anterior;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> fila;

    for (auto vertice : grafo) {
        distancia[vertice.first] = infinito;
    }

    if (grafo.find(origem) == grafo.end() || grafo.find(destino) == grafo.end()) {
        return {infinito, {}};
    }

    distancia[origem] = 0;
    fila.push({0, origem});

    while (!fila.empty()) {
        int distanciaAtual = fila.top().first;
        char atual = fila.top().second;
        fila.pop();

        if (distanciaAtual > distancia[atual]) {
            continue;
        }

        for (auto vizinho : grafo.at(atual)) {
            char proximo = vizinho.first;
            int peso = vizinho.second;

            if (distancia[atual] != infinito && distancia[atual] + peso < distancia[proximo]) {
                distancia[proximo] = distancia[atual] + peso;
                anterior[proximo] = atual;
                fila.push({distancia[proximo], proximo});
            }
        }
    }

    if (distancia[destino] == infinito) {
        return {infinito, {}};
    }

    vector<char> caminho;

    for (char atual = destino; atual != origem; atual = anterior[atual]) {
        caminho.push_back(atual);
    }

    caminho.push_back(origem);
    reverse(caminho.begin(), caminho.end());

    return {distancia[destino], caminho};
}

// Imprime a ordem de visitacao dos vertices em uma unica linha.
void imprimirOrdem(const vector<char> &ordem) {
    for (int i = 0; i < ordem.size(); i++) {
        cout << ordem[i];

        if (i + 1 < ordem.size()) {
            cout << " ";
        }
    }

    cout << endl;
}

// Imprime o custo total, o caminho e as arestas do menor caminho encontrado.
void imprimirCaminhoMinimo(int custo, const vector<char> &caminho) {
    if (caminho.empty()) {
        cout << "Nao existe caminho entre os vertices informados." << endl;
        return;
    }

    cout << "Custo: " << custo << endl;
    cout << "Caminho: ";

    for (int i = 0; i < caminho.size(); i++) {
        cout << caminho[i];

        if (i + 1 < caminho.size()) {
            cout << " -> ";
        }
    }

    cout << endl;
    cout << "Arestas:" << endl;

    for (int i = 0; i + 1 < caminho.size(); i++) {
        cout << caminho[i] << " -> " << caminho[i + 1] << endl;
    }
}

int main() {
    cout << "Trabalho 2 - Grafos" << endl << endl;

    ListaAdjacencia g1 = lerGrafo("docs/Grafos_Trab_2/g1.txt", false, false);
    ListaAdjacencia g2 = lerGrafo("docs/Grafos_Trab_2/g2.txt", true, false);
    ListaAdjacencia g3 = lerGrafo("docs/Grafos_Trab_2/g3.txt", false, true);

    if (g1.empty() || g2.empty() || g3.empty()) {
        cout << "Erro: um ou mais grafos nao foram carregados corretamente." << endl;
        return 1;
    }

    imprimirGrafo(g1, "G1", false);
    imprimirGrafo(g2, "G2", false);
    imprimirGrafo(g3, "G3", true);

    cout << "Busca em largura em G1 a partir de b:" << endl;
    vector<char> ordemBfs = buscaLargura(g1, 'b');
    imprimirOrdem(ordemBfs);
    cout << endl;

    cout << "Busca em profundidade em G2 a partir de a:" << endl;
    vector<char> ordemDfs = buscaProfundidade(g2, 'a');
    imprimirOrdem(ordemDfs);
    cout << endl;

    cout << "Menor caminho em G3 de x ate t:" << endl;
    pair<int, vector<char>> resultado = dijkstra(g3, 'x', 't');
    imprimirCaminhoMinimo(resultado.first, resultado.second);

    return 0;
}
