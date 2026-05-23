#include <iostream>
#include <fstream>
#include <sstream> // permite dividir a string em partes
#include <map>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

// Estrutura usada para representar a lista de adjacência do grafo
// Cada vértice é identificado por um char e possui uma lista de vizinhos
// Cada vizinho é representado por um pair<char, int>, onde:
// first  = vértice de destino
// second = peso da aresta
typedef map<char, vector<pair<char,int>>> ListaAdjacencia;

ListaAdjacencia lerGrafo(string nomeArquivo, bool digrafo, bool ponderado){
    /*========================================================================
    Lê um arquivo de texto contendo as arestas de um grafo e monta sua
    lista de adjacência em memória.

    Parâmetros:
    - nomeArquivo: caminho do arquivo a ser lido;
    - digrafo: indica se o grafo é direcionado;
    - ponderado: indica se as arestas possuem peso.

    Formato esperado do arquivo:
    - Grafo não ponderado: origem;destino
    - Grafo ponderado:     origem;destino;peso

    Retorno:
    - Lista de adjacência representando o grafo.
    ==========================================================================*/

    ListaAdjacencia grafo;

    ifstream arquivo(nomeArquivo);

    // tenta abrir o arquivo
    if(!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return grafo;
    }

    string linha;

    while (getline(arquivo, linha)) {

        //Se a linha estiver vazia, continua para a próxima
        if (linha.empty()) {
            continue;
        }

        stringstream ss(linha);

        string origemTexto;
        string destinoTexto;
        string pesoTexto;

        getline(ss, origemTexto, ';');
        getline(ss, destinoTexto, ';');

        char origem = origemTexto[0];
        char destino = destinoTexto[0];

        int peso = 1;

        if (ponderado) {
            getline(ss, pesoTexto, ';');
            // converte o valor string para int
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

    //percorre todos os vértices do grafo
    for (auto &vertice : grafo) {
        //ordena em ordem alfabética
        sort(vertice.second.begin(), vertice.second.end());
    }

    return grafo;
}


void imprimirGrafo(ListaAdjacencia grafo) {
    /*========================================================================
    Imprime o grafo e as suas adjacências
    ==========================================================================*/
    for (auto vertice : grafo) {
        cout << vertice.first << " -> ";

        for (auto vizinho : vertice.second) {
            cout << "(" << vizinho.first << ", peso: " << vizinho.second << ") ";
        }

        cout << endl;
    }
}
