/*========================================================================================================
    Alessandro Luis Pinheiro da Rocha Junior                Código: 2230837
    Bruno Saraiva                                           Código: 2185932
    Mateus de Castro                                        Código: 2200040
    Sergio Luis Filippin                                    Código: 2259500
=========================================================================================================*/


#include <iostream>
#include <vector>


using namespace std;

bool kparticoes(vector<int> &V, const int  &soma_v, const int &k_part, vector<vector<int>> &subconjuntos, vector<int> &somas_subconj, int index){
    /*=================================================================================
        Divide o vetor resultante em subvetores, baseado no número de partições k passado
        @args: V (vetor), soma_v (soma do vetor V), k_part (n de partições k)
        subconjuntos (armazena os vetores particionados), somas_subconj
        index (elemento a ser alocacado)
    ==================================================================================*/
    int soma_result = 0;
    vector<int> n_usados; // armazena os números já usados
    
    
    //Soma a ser conquistada por cada subconjunto
    soma_result = (soma_v / k_part);
    
    // Caso Base: Verifica se a somaTotal de elementos tem resto 0
    if((soma_v % k_part) != 0){
        return false;
    }
    // Verifica se o índice chegou ao fim do vetor
    if(index == V.size()){
        // verifica se os suconjuntos atingiram a soma_result
        for(int i = 0; i < k_part; i++){
            if(somas_subconj[i] != soma_result) return false;
        }
        return true;
    }

    //preciso dividir os elementos em subconjuntos, e os elementos iguais devem ficar em conjuntos diferentes

    // a partir daqui (SÉRGIO)

    for (int k= 0; k < k_part; k++){ // tenta alocar o v[index] em cada subconjunto

        if (somas_subconj[k] + V[index] > soma_result) continue; // se a soma do subconjunto ultrapassar a soma_result, pula para o próximo subconjunto
        
        if ( k > 0 && subconjuntos[k].empty()&& subconjuntos[k-1].empty()) continue; // evita alocar subconjutos vazios iguais

        subconjuntos[k].push_back(V[index]);
        somas_subconj[k] +=V[index]; 

        kparticoes(V, soma_v, k_part, subconjuntos, somas_subconj, index + 1); // recursão para o próximo elemento  

        subconjuntos[k].pop_back(); // remove o elemento alocado
        somas_subconj[k] -= V[index]; 
    }

    return false;

    // até aqui (SÉRGIO)
}


int main(){
    vector<int>  V = {7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4 };
    int soma_v = 0;// tamanho V
    int k_part = 2; // k partições
    vector<int> somas_subconj(k_part, 0); //soma dos suconjuntos;
    vector<vector<int>> subconjuntos(k_part); //subconjuntos do vetor V

    for(int i = 0; i < V.size(); i++){
        soma_v += V[i];
    }

    //verifica se o número de partições é > 0
    if(k_part <= 0){
        cout << "Impossível particionar!" << endl;
        return 0;
    }
    

    cout << "SomaTotal de V: " <<  soma_v << endl;

    kparticoes(V, soma_v, k_part, subconjuntos, somas_subconj, 0);

    return 0;

}