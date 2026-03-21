#include <chrono>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int N;
vector<vector<char>> tabuleiro;
int totalSolucoes = 0;

bool seguro(int linha, int coluna)
{
    // Complexidade: O(N), pois verifica no maximo uma coluna e duas diagonais.
    for (int i = 0; i < linha; i++)
        if (tabuleiro[i][coluna] == 'R')
            return false;

    for (int i = linha - 1, j = coluna - 1; i >= 0 && j >= 0; i--, j--)
        if (tabuleiro[i][j] == 'R')
            return false;

    for (int i = linha - 1, j = coluna + 1; i >= 0 && j < N; i--, j++)
        if (tabuleiro[i][j] == 'R')
            return false;

    return true;
}

void imprimir(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << tabuleiro[i][j] << " ";
        cout << endl;
    }
    totalSolucoes++;
    cout << "---------------------\n";
}

void resolver(int linha){
    // Complexidade de pior caso: O(N!), pois cada linha tenta ate N colunas
    // e o backtracking explora as combinacoes validas de posicionamento.
    if(linha == N){
        imprimir();
        return;
    }

    for (int col = 0; col < N; col++){
        if (seguro(linha, col)){
            tabuleiro[linha][col] = 'R';
            resolver(linha + 1);
            tabuleiro[linha][col] = '-';
        }
    }
}

int main(){
    char resposta;

    do {
        totalSolucoes = 0;

        cout << "Digite o numero de rainhas: ";

        if (!(cin >> N)) {
            cout << "Entrada invalida. Digite um numero inteiro." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (N <= 0) {
            cout << "O numero de rainhas deve ser maior que zero." << endl;
        } else if (N == 2 || N == 3) {
            cout << "Nao existe solucao para N = " << N << "." << endl;
        } else {
            auto inicio = chrono::high_resolution_clock::now();
            tabuleiro = vector<vector<char>>(N, vector<char>(N, '-'));
            resolver(0);
            auto fim = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duracao = fim - inicio;

            cout << "Total de solucoes: " << totalSolucoes << endl;
            cout << "Tempo de execucao: " << duracao.count() << " ms" << endl;
        }

        do {
            cout << "Deseja testar outro valor de N? (s/n): ";
            cin >> resposta;

            if (resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N') {
                cout << "Opcao invalida. Digite apenas s ou n." << endl;
            }
        } while (resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N');

    } while (resposta == 's' || resposta == 'S');

    cout << "Programa encerrado." << endl;

    return 0;
}
