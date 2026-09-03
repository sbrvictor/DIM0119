#include <iostream>

//Função de busca linear iterativa 
//Recebe um array, o valor a ser buscado e o intervalo [esq, dir)
//Retorna o indice do elemento se encontrada, ou -1 caso contrário.

int busca_linear_iter(int arr[], int valor, int esq, int dir) {
    for (int i = esq; i < dir; i++) {
        if ( arr[i] == valor) {

            return i;
        }
    }
    return -1;
}