/*
 * Autor: Victor Sobrinho de Santana
 * Disciplina: DIM0119 - Estruturas de Dados Básicas 1
 * Exercício 3: Busca Sequencial Alternativa Iterativa
 */
#include <iostream>
#include <vector>

using namespace std;

// Função de Busca Sequencial Alternativa Iterativa
// Realiza a varredura em sentido inverso: da direita (final) para a esquerda (início).
int busca_seq_alternativa_iterativa(int arr[], int valor, int esq, int dir) {
    // Inicia no último índice válido do intervalo, que é 'dir - 1'
    // e decrementa a cada iteração até alcançar o limite inferior 'esq'
    for (int i = dir - 1; i >= esq; --i) {
        // Retorna imediatamente o índice se o valor for encontrado no caminho inverso
        if (arr[i] == valor) {
            return i;
        }
    }
    // Retorna -1 se varrer todo o array de trás para frente e não encontrar o alvo
    return -1; 
}

int main() {
    int alvo, valor;
    
    // Captura o alvo do teste que encabeça o arquivo de entrada
    if (!(cin >> alvo)) return 0;

    // Instancia o vetor para o armazenamento dos dados de teste
    vector<int> arr;
    
    // Preenche o vetor até que não haja mais dados de entrada
    while (cin >> valor) {
        arr.push_back(valor);
    }

    // Inicia a busca passando o tamanho total como limite superior aberto
    int resultado = busca_seq_alternativa_iterativa(arr.data(), alvo, 0, arr.size());
    
    return 0;
}