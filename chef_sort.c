#include <stdio.h>
#include <string.h>

#define NUM_INGREDIENTS 6
#define NUM_DISHES 5
#define NUM_ORDERS 5
#define MAX_NAME_LENGTH 50

// ============================================================================
// ESTRUTURAS DE DADOS (STRUCTS)
// ============================================================================

// Struct para o Desafio 2 (Selection Sort)
typedef struct {
    char name[MAX_NAME_LENGTH];
    int ingredient_count;
} DishComplexity;

// Struct para o Desafio 3 (Insertion Sort)
typedef struct {
    int ticket_number;
    char dish_name[MAX_NAME_LENGTH];
} OrderTicket;

// ============================================================================
// ALGORITMOS DE ORDENAÇÃO
// ============================================================================

/* 
 * 1. BUBBLE SORT (Strings)
 * Ordena matriz de char em ordem alfabética e coleta métricas.
 */
void bubbleSort(char arr[][MAX_NAME_LENGTH], int n, int *comparisons, int *swaps) {
    int i, j, swapped;
    char temp[MAX_NAME_LENGTH];
    
    *comparisons = 0;
    *swaps = 0;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
                (*swaps)++;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

/*
 * 2. SELECTION SORT (Structs)
 * Ordena pratos pela quantidade de ingredientes (crescente).
 */
void selectionSort(DishComplexity arr[], int n) {
    int i, j, min_index;
    DishComplexity temp;

    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].ingredient_count < arr[min_index].ingredient_count) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

/*
 * 3. RECURSIVE INSERTION SORT (Structs)
 * Ordena comandas pelo número do ticket (prioridade) usando recursão.
 */
void recursiveInsertionSort(OrderTicket arr[], int n) {
    // Caso base: se a lista tiver 1 ou 0 elementos, já está ordenada.
    if (n <= 1) {
        return;
    }

    // Chamada recursiva para ordenar os primeiros n-1 elementos
    recursiveInsertionSort(arr, n - 1);

    // Pega o último elemento (que está fora de ordem no subvetor atual)
    OrderTicket last = arr[n - 1];
    int j = n - 2;

    // Move os elementos do subvetor ordenado (arr[0..n-2]) que são
    // maiores que o ticket atual, uma posição para a frente.
    while (j >= 0 && arr[j].ticket_number > last.ticket_number) {
        arr[j + 1] = arr[j];
        j--;
    }
    
    // Insere o ticket na sua posição correta
    arr[j + 1] = last;
}

// ============================================================================
// FUNÇÃO AUXILIAR DE IMPRESSÃO (MONITOR DE PEDIDOS)
// ============================================================================

void printMonitor(OrderTicket arr[], int n, const char* status_message) {
    printf("%s\n\n", status_message);
    printf("=======================================================\n");
    printf("   MONITOR DE PEDIDOS - STATUS ATUAL DA COZINHA\n");
    printf("=======================================================\n");
    printf(" TICKET       | PRATO / PEDIDO\n");
    printf("-------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("  #%d        | %s\n", arr[i].ticket_number, arr[i].dish_name);
    }
    printf("=======================================================\n");
    printf(" TOTAL DE PEDIDOS EM FILA: %d\n", n);
    printf("=======================================================\n\n");
}

// ============================================================================
// FUNÇÃO PRINCIPAL
// ============================================================================

int main() {
    int i;

    // ------------------------------------------------------------------------
    // ETAPA 1: BUBBLE SORT (Ingredientes)
    // ------------------------------------------------------------------------
    printf("\n>>> ETAPA 1: PREPARACAO DE INGREDIENTES (BUBBLE SORT) <<<\n\n");
    
    char ingredients[NUM_INGREDIENTS][MAX_NAME_LENGTH] = {
        "Tomate", "Cebola", "Alho", "Pimenta", "Manjericao", "Azeite"
    };
    int total_comparisons, total_swaps;

    printf("=== ESTADO INICIAL: Ingredientes Desorganizados ===\n");
    for(i = 0; i < NUM_INGREDIENTS; i++) { printf(" [ ] %s\n", ingredients[i]); }
    
    bubbleSort(ingredients, NUM_INGREDIENTS, &total_comparisons, &total_swaps);
    
    printf("\n=== ESTADO FINAL: Ingredientes Ordenados (A-Z) ===\n");
    for(i = 0; i < NUM_INGREDIENTS; i++) { printf(" [x] %s\n", ingredients[i]); }
    printf("Metricas: %d comparacoes, %d trocas.\n\n", total_comparisons, total_swaps);


    // ------------------------------------------------------------------------
    // ETAPA 2: SELECTION SORT (Complexidade do Menu)
    // ------------------------------------------------------------------------
    printf("\n>>> ETAPA 2: ORGANIZACAO DO MENU (SELECTION SORT) <<<\n\n");
    
    DishComplexity menu[NUM_DISHES] = {
        {"Lasanha a Bolonhesa", 14},
        {"Ovo Frito", 2},
        {"Feijoada Completa", 18},
        {"Salada Caprese", 4},
        {"Risoto de Funghi", 8}
    };

    printf("=== ESTADO INICIAL: Pratos (Por Ordem de Chegada) ===\n");
    for(i = 0; i < NUM_DISHES; i++) { 
        printf(" [ ] %s - %d ingredientes\n", menu[i].name, menu[i].ingredient_count); 
    }
    
    selectionSort(menu, NUM_DISHES);
    
    printf("\n=== ESTADO FINAL: Menu Ordenado (Simples -> Complexo) ===\n");
    for(i = 0; i < NUM_DISHES; i++) { 
        printf(" [x] %s - %d ingredientes\n", menu[i].name, menu[i].ingredient_count); 
    }
    printf("\n");


    // ------------------------------------------------------------------------
    // ETAPA 3: INSERTION SORT RECURSIVO (Fila de Comandas)
    // ------------------------------------------------------------------------
    printf("\n>>> ETAPA 3: FILA DE ATENDIMENTO (RECURSIVE INSERTION SORT) <<<\n\n");
    
    // Vetor de comandas baseado nos dados exatos das imagens de referência
    OrderTicket orders[NUM_ORDERS] = {
        {105, "Frango Xadrez"},
        {102, "Risoto de Fungui"}, // Mantido a grafia exata da imagem ("Fungui")
        {104, "Peixe Grelhado"},
        {101, "Massa Artesanal"},
        {103, "Sushi Combo"}
    };

    // Imprime o estado desordenado chamando a função de interface
    printMonitor(orders, NUM_ORDERS, "Pedidos chegando (Desordenados):");

    // Ordena recursivamente
    recursiveInsertionSort(orders, NUM_ORDERS);

    // Imprime o estado ordenado
    printMonitor(orders, NUM_ORDERS, "Pedidos organizados (Prontos para preparo):");

    return 0;
}
