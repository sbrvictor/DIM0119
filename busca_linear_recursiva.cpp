#include <iostream>

//Função de busca linear recursiva
//Recebe um array, o valor a ser buscado e o intervalo [esq, dir)
//Retorna o índice do elemento se encontrado , ou -1

int busca_linear_rec(int A[], int valor, int esq, int dir) {
    if (esq == dir) {
        return -1;
    }

    if ( A[esq] == valor) {
        return esq;
    }

    return busca_linear_rec( A, valor, esq + 1, dir );
}