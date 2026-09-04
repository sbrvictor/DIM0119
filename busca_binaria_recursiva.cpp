/*
 * Autor: Victor Sobrinho de Santana
 * Disciplina: DIM0119 - Estruturas de Dados Básicas 1
 * Exercício 6: Busca Binária Recursiva
 */
#include <iostream>
#include <vector>

using namespace std;

// Função de Busca Binária Recursiva (exige array ordenado)
// Divide o problema reduzindo o espaço de busca pela metade a cada chamada
int busca_binaria_recursiva(int arr[], int valor, int esq, int dir) {
    // Caso base: O limite inferior cruzou ou alcançou o superior (intervalo inválido)
    if (esq >= dir) {
        return -1;
    }
    
    // Calcula a posição central do intervalo
    int meio = esq + (dir - esq) / 2;
    
    // Verifica se a posição central contém o valor
    if (arr[meio] == valor) {
        return meio;
    }
    
    // Se o elemento central for menor, repassa a tarefa recursivamente 
    // apenas para o sub-array da direita [meio + 1, dir)
    if (arr[meio] < valor) {
        return busca_binaria_recursiva(arr, valor, meio + 1, dir);
    }
    
    // Caso contrário (elemento central maior), busca recursivamente 
    // no sub-array da esquerda [esq, meio)
    return busca_binaria_recursiva(arr, valor, esq, meio);
}

int main() {
    int alvo, valor;
    
    // Extrai a condição de busca do arquivo (o alvo)
    if (!(cin >> alvo)) return 0;

    vector<int> arr;
    
    // Popula o vetor com os elementos para a simulação de teste
    while (cin >> valor) {
        arr.push_back(valor);
    }

    // Inicia a cadeia recursiva passando o vetor e os limites globais
    int resultado = busca_binaria_recursiva(arr.data(), alvo, 0, arr.size());
    
    return 0;
}