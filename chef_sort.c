#include <stdio.h>
#include <string.h>

// ANÁLISE DE ALGORITMO - Desafio Chef Sort
// Este é o arquivo inicial para o desafio. 
// Dependendo do nível escolhido (Novato, Aventureiro ou Mestre), 
// descomente e utilize as estruturas e funções correspondentes.

// ====================================================================
// ESTRUTURAS DE DADOS (Para Níveis Aventureiro e Mestre)
// ====================================================================

// Struct para o Nível Aventureiro
/*
typedef struct {
    char nome[50];
    int qtd_ingredientes;
} Prato;
*/

// Struct para o Nível Mestre
/*
typedef struct {
    char nome_prato[50];
    int numero_comanda;
} Comanda;
*/


// ====================================================================
// PROTÓTIPOS DAS FUNÇÕES DE ORDENAÇÃO
// ====================================================================

// Nível Novato: Bubble Sort para strings
// Dica: Use strcmp() da biblioteca <string.h> para comparar strings.
// Dica: Passe ponteiros para contadores de comparações e trocas se quiser alterá-los dentro da função.
#define NUM_INGREDIENTS 6
#define MAX_NAME_LENGTH 30

void bubbleSort(char arr[][MAX_NAME_LENGTH], int n, int *compracoes, int *trocas) {
    int i, j;
    int swapped;
    char temp_ingredient[MAX_NAME_LENGTH];
    
    // Inicializa as métricas com zero
    *compracoes = 0;
    *trocas = 0;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        
        for (j = 0; j < n - i - 1; j++) {
            (*compracoes)++; // Sensor de comparação (atualiza o valor na memória)
            
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                
                // Realiza a troca (swap)
                strcpy(temp_ingredient, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp_ingredient);
                
                (*trocas)++; // Sensor de trocas (atualiza o valor na memória)
                swapped = 1;
            }
        }
        
        // Parada antecipada se nenhuma troca foi feita nesta passagem
        if (!swapped) break;
    }
}

// Nível Aventureiro: Selection Sort para array de structs (Prato)
/*
void selectionSortPratos(Prato arr[], int n) {
    // Sua lógica do Selection Sort aqui buscando a menor qtd_ingredientes
}
*/

// Nível Mestre: Recursive Insertion Sort para array de structs (Comanda)
// Dica: Lembre-se de definir o "caso base" (n <= 1) para parar a recursão!
/*
void recursiveInsertionSort(Comanda arr[], int n) {
    // Sua lógica do Insertion Sort Recursivo aqui
}
*/


// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    // Vetor bidimensional de ingredientes criado na main
    char ingredientes[NUM_INGREDIENTS][MAX_NAME_LENGTH] = {
        "Tomate",
        "Cebola",
        "Alho",
        "Pimenta",
        "Manjericao",
        "Azeite"
    };
    
    int i;
    
    // Variáveis para armazenar as métricas na main
    int total_comparacoes, total_trocas;

    // 1. Imprimir estado inicial
    printf("=== CHEF SORT: STATUS INICIAL DA BANCADA  ===\n");
    printf("Ingredientes Desorganizados\n");
    for(i = 0; i < NUM_INGREDIENTS; i++) {
        printf(" [ ] %s\n", ingredientes[i]);
    }
    printf("===================================================\n\n");

    // 2. Chamar a função de ordenação passando os endereços (&) das variáveis de métrica
    bubbleSort(ingredientes, NUM_INGREDIENTS, &total_comparacoes, &total_trocas);

    // 3. Imprimir estado final
    printf("=== ESTADO FINAL: Ingredientes Ordenados (A-Z) ===\n");
    for(i = 0; i < NUM_INGREDIENTS; i++) {
        printf(" [x] %s\n", ingredientes[i]);
    }
    printf("==================================================\n");
    
    // 4. Exibir as métricas finais (função da main, conforme solicitado)
    printf("\nMetricas da Ordenacao:\n");
    printf("Comparações realizadas: %d | Trocas efetuadas: %d\n", total_comparacoes, total_trocas);


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
