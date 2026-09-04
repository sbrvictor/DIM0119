/*
 * Autor: Victor Sobrinho de Santana
 * Disciplina: DIM0119 - Estruturas de Dados Básicas 1
 * Exercício 4: Busca Sequencial Alternativa Recursiva
 */
#include <iostream>
#include <vector>

using namespace std;

// Função de Busca Sequencial Alternativa Recursiva
// Diminui recursivamente o tamanho do array pela direita.
int busca_seq_alternativa_recursiva(int arr[], int valor, int esq, int dir) {
    // Caso base 1: Os limites se encontraram, logo o intervalo está vazio
    if (esq == dir) {
        return -1; 
    }
    
    // Caso base 2: Verifica sempre a última posição válida do intervalo atual
    if (arr[dir - 1] == valor) {
        return dir - 1; 
    }
    
    // Passo recursivo: reduz o intervalo diminuindo o limite direito (dir - 1),
    // forçando a próxima chamada a olhar o elemento anterior.
    return busca_seq_alternativa_recursiva(arr, valor, esq, dir - 1);
}

int main() {
    int alvo, valor;
    
    // Lê o alvo definido para o pior ou melhor caso deste teste
    if (!(cin >> alvo)) return 0;

    vector<int> arr;
    
    // Carrega a massa de dados do arquivo de texto para a memória
    while (cin >> valor) {
        arr.push_back(valor);
    }

    // Chama a função definindo o intervalo de busca como [0, tamanho_do_array)
    int resultado = busca_seq_alternativa_recursiva(arr.data(), alvo, 0, arr.size());
    
    return 0;
}