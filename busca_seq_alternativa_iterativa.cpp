#include <iostream>

// Função de Busca Sequencial Alternativa Iterativa (Busca de trás para frente)
// Recebe um array, o valor a ser buscado e o intervalo [esq, dir)
// Retorna o índice do elemento se encontrado, ou -1 caso contrário.
int busca_seq_alternativa_iterativa(int arr[], int valor, int esq, int dir) {
    // Percorre o array do índice 'dir - 1' até 'esq' (fechado à esquerda e aberto à direita)
    // a ideia de percorrer de tras para frente é criar um contraste com a primeira busca nos algoritmos lineares
    for (int i = dir - 1; i >= esq; --i) {
        
        if (arr[i] == valor) {
            return i;
        }
    }
    
    return -1; 
}