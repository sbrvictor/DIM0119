#include <iostream>

// Função de Busca Binária Recursiva (exige que o array esteja previamente ordenado)
// Recebe um array, o valor a ser buscado e o intervalo [esq, dir)
// Retorna o índice do elemento se encontrado, ou -1 caso contrário.
int busca_binaria_recursiva(int arr[], int valor, int esq, int dir) {
    // Condição de parada: intervalo inválido ou esgotado
    if (esq >= dir) {
        return -1;
    }
    
    int meio = esq + (dir - esq) / 2;
    
    // Verifica se o valor buscado está no meio
    if (arr[meio] == valor) {
        return meio;
    }
    
    // Se o valor buscado for maior que o do meio, busca recursivamente na metade direita
    if (arr[meio] < valor) {
        return busca_binaria_recursiva(arr, valor, meio + 1, dir);
    }
    
    // Se o valor buscado for menor que o do meio, busca recursivamente na metade esquerda
    return busca_binaria_recursiva(arr, valor, esq, meio);
}