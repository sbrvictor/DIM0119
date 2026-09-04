/*
 * Autor: Victor Sobrinho de Santana
 * Disciplina: DIM0119 - Estruturas de Dados Básicas 1
 * Exercício 8: Busca Ternária Recursiva
 */
#include <iostream>
#include <vector>

using namespace std;

// Função de Busca Ternária Recursiva (exige array ordenado)
// Delega a busca para um dos três blocos menores a cada camada recursiva
int busca_ternaria_recursiva(int arr[], int valor, int esq, int dir) {
    // Caso base: cruzamento de limites aponta que o valor não existe no array
    if (esq >= dir) {
        return -1;
    }

    // Variável auxiliar apontando para o último índice inclusivo do bloco atual
    int dir_inc = dir - 1;
    
    // Determina matematicamente as duas quebras que separam os terços
    int meio1 = esq + (dir_inc - esq) / 3;
    int meio2 = dir_inc - (dir_inc - esq) / 3;

    // Checagem imediata nos pontos de quebra para abreviar a busca
    if (arr[meio1] == valor) return meio1;
    if (arr[meio2] == valor) return meio2;

    // Se o alvo for menor que a primeira quebra, a recursão foca no bloco inferior
    if (valor < arr[meio1]) {
        return busca_ternaria_recursiva(arr, valor, esq, meio1);
    }
    // Se o alvo for superior à segunda quebra, a recursão assume o bloco superior
    else if (valor > arr[meio2]) {
        return busca_ternaria_recursiva(arr, valor, meio2 + 1, dir);
    }
    
    // Por eliminação, caso o alvo esteja ensanduichado entre meio1 e meio2,
    // a recursão resolve apenas o bloco central.
    return busca_ternaria_recursiva(arr, valor, meio1 + 1, meio2);
}

int main() {
    int alvo, valor;
    
    // Lê e isola a chave a ser buscada no array principal
    if (!(cin >> alvo)) return 0;

    vector<int> arr;
    
    // Criação da lista de dados originada do arquivo de testes empíricos
    while (cin >> valor) {
        arr.push_back(valor);
    }

    // Invocação inicial da recursão contemplando a totalidade dos elementos
    int resultado = busca_ternaria_recursiva(arr.data(), alvo, 0, arr.size());
    
    return 0;
}