/*========================================================================================================
    Alessandro Luis Pinheiro da Rocha Junior                Código: 2230837
    Bruno Saraiva                                           Código: 2185932
    Mateus de Castro                                        Código: 2200040
    Sergio Luis Filippin                                    Código: 2259500
=========================================================================================================*/


#include <iostream>
#include <vector>


using namespace std;

bool kparticoes(vector<int> &V, const int  &soma_v, const int &k_part, vector<vector<int>> &subconjuntos, vector<int> &somas_subconj, int index, int &count){
    /*=================================================================================
        Divide o vetor resultante em subvetores, baseado no número de partições k passado
        @args: V (vetor), soma_v (soma do vetor V), k_part (n de partições k)
        subconjuntos (armazena os vetores particionados), somas_subconj
        index (elemento a ser alocacado)

        Complexidade: O(k^n)
        Para cada um dos n elementos, o algoritmo tenta k subconjuntos possíveis.

    ==================================================================================*/
    int soma_result = 0;
    
    
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

        count ++;
        cout << "\nSolução encontrada: " << endl;
        for(int i = 0; i < k_part; i++){
            cout << "S" << i+1 << " = { ";
            for(int num : subconjuntos[i]){
                cout << num << " ";
            }
            cout << "}\n";
        }

        return true;
    }
    
    // tenta alocar o v[index] em cada subconjunto
    for (int k= 0; k < k_part; k++){
        
        // se a soma do subconjunto ultrapassar a soma_result, pula para o próximo subconjunto
        if (somas_subconj[k] + V[index] > soma_result) continue; 
        
        // evita explorar subconjuntos com mesma soma parcial (simetria)
        if (k > 0 && somas_subconj[k] == somas_subconj[k-1]) continue;

        subconjuntos[k].push_back(V[index]);
        somas_subconj[k] +=V[index]; 
        
        // próximo elemento  
       kparticoes(V, soma_v, k_part, subconjuntos, somas_subconj, index + 1, count);

        

        subconjuntos[k].pop_back(); // remove o elemento alocado
        somas_subconj[k] -= V[index]; 
    }

    return false;

}


int main(){
    vector<int>  V = {7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4};
    int soma_v = 0;// tamanho V
    int k_part = 5;// k partições
    int count  = 0;// contador de soluções 

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

    kparticoes(V, soma_v, k_part, subconjuntos, somas_subconj, 0, count);

    if(count == 0)
        cout << "\nNenhuma solução encontrada.\n";

    cout << "\nNumero total de soluções encontradas: " << count << endl;
        return 0;

}