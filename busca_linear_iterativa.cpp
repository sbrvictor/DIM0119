/*
 * Autor: Victor Sobrinho de Santana
 * Disciplina: DIM0119 - Estruturas de Dados Básicas 1
 * Exercício 1: Busca Linear Iterativa
 */
#include <iostream>
#include <vector>

using namespace std;

// Função de Busca Linear Iterativa
// Recebe o array, o valor buscado e os limites do intervalo [esq, dir)
// O limite 'esq' é fechado (inclusivo) e o 'dir' é aberto (exclusivo).
int busca_linear_iterativa(int arr[], int valor, int esq, int dir) {
    // Laço percorre sequencialmente os elementos do intervalo válido
    // Começa em 'esq' e vai estritamente até antes de 'dir'
    for (int i = esq; i < dir; ++i) {
        // Se o elemento na posição atual for igual ao valor buscado,
        // a busca é encerrada e o índice correspondente é retornado.
        if (arr[i] == valor) {
            return i; 
        }
    }
    // Se o laço terminar sem encontrar o valor, retorna -1 indicando falha
    return -1; 
}

int main() {
    int alvo, valor;
    
    // Lê o primeiro número do arquivo txt, que definimos como o alvo da busca
    if (!(cin >> alvo)) {
        return 0; // Previne execução incorreta se o arquivo estiver vazio
    }

    // Utiliza um vector pois permite armazenar dados lidos dinamicamente
    vector<int> arr;
    
    // Lê os números restantes do arquivo separadamente até o final (EOF)
    while (cin >> valor) {
        arr.push_back(valor); // Adiciona cada número lido ao final da estrutura
    }

    // Executa a busca passando o ponteiro do array interno (arr.data()), o alvo,
    // o índice inicial (0) e o limite final do intervalo (tamanho total do vector)
    int resultado = busca_linear_iterativa(arr.data(), alvo, 0, arr.size());
    
    return 0;
}