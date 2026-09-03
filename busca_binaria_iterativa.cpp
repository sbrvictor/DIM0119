#include <iostream>

// Função de Busca Binária Iterativa (exige que o array esteja previamente ordenado)
// Recebe um array, o valor a ser buscado e o intervalo [esq, dir)
// Retorna o índice do elemento se encontrado, ou -1 caso contrário.
int busca_binaria_iterativa(int arr[], int valor, int esq, int dir) {
    // Mantém o laço enquanto houver um intervalo válido
    while (esq < dir) {
        
        int meio = esq + (dir - esq) / 2;
        
        // Verifica se o valor buscado está exatamente no meio
        if (arr[meio] == valor) {
            return meio; 
        }
        
        else if (arr[meio] < valor) {
            esq = meio + 1;
        }
        
        else {
            dir = meio;
        }
    }
    
    // Se o intervalo se esgotar e não encontrar o valor, retorna -1
    return -1;
}