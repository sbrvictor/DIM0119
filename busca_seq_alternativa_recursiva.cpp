#include <iostream>

// Função de Busca Sequencial Alternativa Recursiva (Busca de trás para frente)
// Recebe um array, o valor a ser buscado e o intervalo [esq, dir)
// Retorna o índice do elemento se encontrado, ou -1 caso contrário.
int busca_seq_alternativa_recursiva(int arr[], int valor, int esq, int dir) {
    // Condição de parada (caso base): se o índice esquerdo alcançar o direito,
    // o intervalo acabou e o valor não foi encontrado.
    if (esq == dir) {
        return -1; 
    }
    
    if (arr[dir - 1] == valor) {
        return dir - 1; // Encontrou o valor, retorna o índice
    }
    
    // Chamada recursiva: busca no restante do array decrementando o limite direito
    return busca_seq_alternativa_recursiva(arr, valor, esq, dir - 1);
}