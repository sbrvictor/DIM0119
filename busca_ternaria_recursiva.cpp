#include <iostream>

// Função de Busca Ternária Recursiva (exige que o array esteja ordenado)
// Recebe um array, o valor a ser buscado e o intervalo [esq, dir)
// Retorna o índice do elemento se encontrado, ou -1 caso contrário.
int busca_ternaria_recursiva(int arr[], int valor, int esq, int dir) {
    // Condição de parada: se o intervalo acabar, o valor não está no array
    if (esq >= dir) {
        return -1;
    }

    // Calcula o limite direito incluído para facilitar a matemática dos terços
    int dir_inc = dir - 1;
    
    // Define os dois pontos divisores
    int meio1 = esq + (dir_inc - esq) / 3;
    int meio2 = dir_inc - (dir_inc - esq) / 3;

    // Caso base de sucesso: verifica os dois pontos médios
    if (arr[meio1] == valor) return meio1;
    if (arr[meio2] == valor) return meio2;

    // Passos recursivos para cada um dos três terços possíveis
    if (valor < arr[meio1]) {
        // Busca no primeiro terço
        return busca_ternaria_recursiva(arr, valor, esq, meio1);
    } 
    else if (valor > arr[meio2]) {
        // Busca no último terço
        return busca_ternaria_recursiva(arr, valor, meio2 + 1, dir);
    } 
    else {
        // Busca no terço central
        return busca_ternaria_recursiva(arr, valor, meio1 + 1, meio2);
    }
}