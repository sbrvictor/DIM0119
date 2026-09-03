#include <iostream>

// Função de Busca Ternária Iterativa (exige que o array esteja ordenado)
// Recebe um array, o valor a ser buscado e o intervalo [esq, dir)
// Retorna o índice do elemento se encontrado, ou -1 caso contrário.
int busca_ternaria_iterativa(int arr[], int valor, int esq, int dir) {
    // Mantém o laço enquanto o intervalo for válido
    while (esq < dir) {
        // Como 'dir' é aberto, o último índice válido é dir - 1
        int dir_inc = dir - 1;
        
        // Calcula os dois pontos que dividem o array em três terços
        int meio1 = esq + (dir_inc - esq) / 3;
        int meio2 = dir_inc - (dir_inc - esq) / 3;

        // Verifica se o valor está em algum dos dois pontos médios
        if (arr[meio1] == valor) {
            return meio1;
        }
        if (arr[meio2] == valor) {
            return meio2;
        }

        // Se o valor for menor que o primeiro ponto, busca no primeiro terço
        if (valor < arr[meio1]) {
            dir = meio1; // Novo intervalo: [esq, meio1)
        } 
        // Se o valor for maior que o segundo ponto, busca no último terço
        else if (valor > arr[meio2]) {
            esq = meio2 + 1; // Novo intervalo: [meio2 + 1, dir)
        } 
        // Caso contrário, o valor está no terço do meio
        else {
            esq = meio1 + 1; // Novo intervalo: [meio1 + 1, meio2)
            dir = meio2;
        }
    }
    
    // Retorna -1 se o intervalo acabar e o valor não for encontrado
    return -1;
}