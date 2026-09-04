/*
 * Autor: Victor Sobrinho de Santana
 * Disciplina: DIM0119 - Estruturas de Dados Básicas 1
 * Exercício 2: Busca Linear Recursiva
 */
#include <iostream>
#include <vector>

using namespace std;

// Função de Busca Linear Recursiva
// Explora o array de forma recursiva avançando o limite esquerdo a cada passo
int busca_linear_recursiva(int arr[], int valor, int esq, int dir) {
    // Condição de parada (Caso base 1): O intervalo se esgotou
    // Se 'esq' alcançar 'dir', todos os elementos foram verificados sem sucesso
    if (esq == dir) {
        return -1; 
    }
    
    // Condição de sucesso (Caso base 2): O elemento atual é o procurado
    if (arr[esq] == valor) {
        return esq; 
    }
    
    // Passo recursivo: chama a função novamente para o restante do array,
    // incrementando o índice inicial (esq + 1) para verificar o próximo elemento
    return busca_linear_recursiva(arr, valor, esq + 1, dir);
}

int main() {
    int alvo, valor;
    
    // Lê o primeiro número (alvo da busca) para iniciar o teste
    if (!(cin >> alvo)) return 0;

    // Estrutura para armazenar dinamicamente os valores de teste
    vector<int> arr;
    
    // Insere todos os números contidos no arquivo dentro do vector
    while (cin >> valor) {
        arr.push_back(valor);
    }

    // Dispara a busca recursiva começando da posição 0 até o tamanho do array
    int resultado = busca_linear_recursiva(arr.data(), alvo, 0, arr.size());
    
    return 0;
}