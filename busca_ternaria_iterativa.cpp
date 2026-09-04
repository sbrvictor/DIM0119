/*
 * Autor: Victor Sobrinho de Santana
 * Disciplina: DIM0119 - Estruturas de Dados Básicas 1
 * Exercício 7: Busca Ternária Iterativa
 */
#include <iostream>
#include <vector>

using namespace std;

// Função de Busca Ternária Iterativa (exige array ordenado)
// Reduz o espaço de busca descartando 2/3 do array a cada repetição
int busca_ternaria_iterativa(int arr[], int valor, int esq, int dir) {
    // Laço executa enquanto o intervalo [esq, dir) possuir elementos
    while (esq < dir) {
        // Define o índice final válido do intervalo para auxiliar no cálculo dos terços
        int dir_inc = dir - 1;
        
        // Quebra o array definindo dois pontos pivôs
        // meio1 divide o primeiro terço, meio2 divide o último terço
        int meio1 = esq + (dir_inc - esq) / 3;
        int meio2 = dir_inc - (dir_inc - esq) / 3;

        // Compara diretamente com os dois pivôs
        if (arr[meio1] == valor) return meio1;
        if (arr[meio2] == valor) return meio2;

        // Se o valor for menor que o primeiro pivô, ele só pode estar no primeiro terço
        if (valor < arr[meio1]) {
            dir = meio1; // Ajusta limite superior para o início do array
        } 
        // Se o valor for maior que o segundo pivô, ele deve estar no último terço
        else if (valor > arr[meio2]) {
            esq = meio2 + 1; // Ajusta limite inferior para o final do array
        } 
        // Se não for nenhum dos extremos, o valor obrigatoriamente está no terço central
        else {
            esq = meio1 + 1; 
            dir = meio2;
        }
    }
    // Caso os limites colidam sem encontrar o alvo, retorna falha
    return -1;
}

int main() {
    int alvo, valor;
    
    // Captura o objetivo da busca na primeira linha de entrada
    if (!(cin >> alvo)) return 0;

    vector<int> arr;
    
    // Loop de leitura para compor os dados que serão avaliados
    while (cin >> valor) {
        arr.push_back(valor);
    }

    // Dispara a busca logarítmica de base 3
    int resultado = busca_ternaria_iterativa(arr.data(), alvo, 0, arr.size());
    
    return 0;
}