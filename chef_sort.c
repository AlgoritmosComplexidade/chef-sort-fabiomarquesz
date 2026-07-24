#include <stdio.h>
#include <string.h>

// ANÁLISE DE ALGORITMO - Desafio Chef Sort
// Este é o arquivo inicial para o desafio. 
// Dependendo do nível escolhido (Novato, Aventureiro ou Mestre), 
// descomente e utilize as estruturas e funções correspondentes.


#define NUM_DISHES 5
#define MAX_NAME_LENGTH 50

// 1. Definição da struct Prato conforme o requisito
typedef struct {
    char name[MAX_NAME_LENGTH];
    int ingredient_count; // Representa a complexidade do prato
} Prato;

/*
 * Função selectionSort
 * Ordena um vetor de structs Prato com base na quantidade de ingredientes (ordem crescente).
 */
void selectionSort(Prato arr[], int n) {
    int i, j, min_index;
    
    // Variável temporária do tipo Prato para realizar a troca
    Prato temp; 

    // O loop externo avança a fronteira do subvetor ordenado
    for (i = 0; i < n - 1; i++) {
        
        // Assume que o primeiro elemento não ordenado é o menor
        min_index = i;
        
        // O loop interno procura o menor elemento no restante do vetor
        for (j = i + 1; j < n; j++) {
            
            // Compara a quantidade de ingredientes
            if (arr[j].ingredient_count < arr[min_index].ingredient_count) {
                // Se encontrar um prato com menos ingredientes, atualiza o índice do menor
                min_index = j;
            }
        }
        
        // Se o menor elemento encontrado não for o que já estava na posição 'i', faz a troca
        if (min_index != i) {
            // Vantagem de usar Struct em C: podemos copiar todos os dados 
            // (nome e quantidade) de uma vez só com o operador de atribuição "="
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    // 2. Vetor fixo com 5 pratos de complexidades diferentes
    Prato menu[NUM_DISHES] = {
        {"Lasanha a Bolonhesa", 14},
        {"Ovo Frito", 2},
        {"Feijoada Completa", 18},
        {"Salada Caprese", 4},
        {"Risoto de Funghi", 8}
    };
    
    int i;

    // 3. Imprimir a lista ANTES da ordenação
    printf("=== ESTADO INICIAL: Pratos (Por Ordem de Chegada) ===\n");
    for(i = 0; i < NUM_DISHES; i++) {
        printf(" [ ] %s - %d ingredientes\n", menu[i].name, menu[i].ingredient_count);
    }
    printf("=====================================================\n\n");

    // 4. Implementar a ordenação chamando a função selectionSort
    selectionSort(menu, NUM_DISHES);

    // 5. Imprimir a lista DEPOIS da ordenação
    printf("=== ESTADO FINAL: Menu Ordenado por Complexidade (Simples -> Complexo) ===\n");
    for(i = 0; i < NUM_DISHES; i++) {
        printf(" [x] %s - %d ingredientes\n", menu[i].name, menu[i].ingredient_count);
    }
    printf("==========================================================================\n");

    return 0;
}


    // ---------------------------------------------------------
    // ÁREA DO NÍVEL NOVATO (Despensa / Bubble Sort)
    // ---------------------------------------------------------
    /*
    char ingredientes[5][50] = {"Tomate", "Cebola", "Alho", "Cenoura", "Batata"};
    int num_ingredientes = 5;
    int comparacoes = 0;
    int trocas = 0;

    printf("--- Nivel Novato: Organizando a Despensa ---\n");
    printf("Lista ANTES da ordenacao:\n");
    // Laco para imprimir ingredientes antes

    // Chamada da funcao bubbleSortStrings(...)

    printf("\nLista DEPOIS da ordenacao:\n");
    // Laco para imprimir ingredientes depois
    // Imprimir totais de comparacoes e trocas
    */


    // ---------------------------------------------------------
    // ÁREA DO NÍVEL AVENTUREIRO (Pratos / Selection Sort)
    // ---------------------------------------------------------
    /*
    // Inicialize aqui o seu vetor de Pratos
    
    printf("\n--- Nivel Aventureiro: Organizando os Pratos ---\n");
    // Imprima antes, chame a funcao selectionSortPratos, imprima depois
    */


    // ---------------------------------------------------------
    // ÁREA DO NÍVEL MESTRE (Comandas / Recursive Insertion Sort)
    // ---------------------------------------------------------
    /*
    // Inicialize aqui o seu vetor de Comandas
    
    printf("\n--- Nivel Mestre: Organizando as Comandas ---\n");
    // Imprima antes, chame a funcao recursiveInsertionSort, imprima depois
    */

    return 0;
}
