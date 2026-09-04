/*
 * Autor: Victor Sobrinho de Santana
 * Disciplina: DIM0119 - Estruturas de Dados Básicas 1
 * Exercício 5: Busca Binária Iterativa
 */
#include <iostream>
#include <vector>

using namespace std;

// Função de Busca Binária Iterativa
// Requisito: O array de entrada precisa estar previamente ordenado.
int busca_binaria_iterativa(int arr[], int valor, int esq, int dir) {
    // O laço mantém a busca ativa enquanto houver um intervalo não nulo
    while (esq < dir) {
        // Cálculo seguro do ponto médio para evitar 'integer overflow'
        // em arrays extremamente grandes (esq + dir poderia exceder o limite do tipo int)
        int meio = esq + (dir - esq) / 2; 
        
        // Sucesso: alvo encontrado exatamente no meio do intervalo atual
        if (arr[meio] == valor) {
            return meio; 
        }
        // Se o valor do meio for menor que o buscado, sabemos que o alvo 
        // só pode estar na metade direita. Logo, descartamos a metade esquerda.
        else if (arr[meio] < valor) {
            esq = meio + 1; // Ajusta o limite inferior
        }
        // Se o valor do meio for maior, o alvo deve estar na metade esquerda.
        // O limite superior 'dir' assume a posição 'meio' (mantendo a regra do intervalo aberto).
        else {
            dir = meio;
        }
    }
    // Retorna -1 se o intervalo se fechar sem localizar o número
    return -1;
}

int main() {
    int alvo, valor;
    
    // Inicia a leitura capturando o número alvo
    if (!(cin >> alvo)) return 0;

    vector<int> arr;
    
    // Absorve os dados ordenados do arquivo de texto
    while (cin >> valor) {
        arr.push_back(valor);
    }

    // Aplica o algoritmo de busca logarítmica
    int resultado = busca_binaria_iterativa(arr.data(), alvo, 0, arr.size());
    
    return 0;
}