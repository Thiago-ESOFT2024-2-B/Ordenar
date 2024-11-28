#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif


// Declaração da função imprimirVetor
void imprimirVetor(int vetor[], int tamanho);

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Ordena o vetor usando Bubble Sort
void bubbleSort(int vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                troca(&vetor[j], &vetor[j + 1]);
                printf("Passo %d-%d: ", i + 1, j + 1);
                imprimirVetor(vetor, tamanho);
            }
        }
    }
}

// Ordena o vetor usando Selection Sort
void selectionSort(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            troca(&vetor[i], &vetor[menor]);
            printf("Passo %d: ", i + 1);
            imprimirVetor(vetor, tamanho);
        }
    }
}

// Esta função é para inserir elemento em ordem
void inserir(int vetor[], int posicao, int valor) {
    int i;
    for (i = posicao; i > 0 && vetor[i - 1] > valor; i--) {
        vetor[i] = vetor[i - 1];
    }
    vetor[i] = valor;
}

// Ordena o vetor usando Insertion Sort
void insertionSort(int vetor[], int tamanho) {
    int i;
    for (i = 1; i < tamanho; i++) {
        inserir(vetor, i, vetor[i]);
        printf("Passo %d: ", i);
        imprimirVetor(vetor, tamanho);
    }
}

// Esta função imprime o vetor!
void imprimirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para limpar a tela()
void limparTela() {
        system("cls");
        system("clear");
   
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int vetor[] = {5, 2, 8, 3, 1, 4, 6};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int opcao;

    do {
        limparTela();
        printf("========================================\n");
        printf("Escolha o método de ordenação:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Sair\n");
        printf("========================================\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 4) {
            printf("Saindo do programa.\n");
            break;
        }

        limparTela();
        printf("\nVetor desordenado:\n");
        imprimirVetor(vetor, tamanho);

        switch(opcao) {
            case 1:
                printf("\nUsando Bubble Sort:\n");
                printf("Bubble Sort funciona comparando repetidamente os elementos adjacentes e trocando-os se estiverem na ordem errada.\n");
                bubbleSort(vetor, tamanho);
                printf("\nVetor ordenado usando Bubble Sort:\n");
                imprimirVetor(vetor, tamanho);
                break;
            case 2:
                printf("\nUsando Selection Sort:\n");
                printf("Selection Sort funciona encontrando repetidamente o menor elemento de uma lista não ordenada e movendo-o para o início.\n");
                selectionSort(vetor, tamanho);
                printf("\nVetor ordenado usando Selection Sort:\n");
                imprimirVetor(vetor, tamanho);
                break;
            case 3:
                printf("\nUsando Insertion Sort:\n");
                printf("Insertion Sort funciona construindo gradualmente a lista ordenada, comparando cada novo elemento com os elementos já ordenados e inserindo-o na posição correta.\n");
                insertionSort(vetor, tamanho);
                printf("\nVetor ordenado usando Insertion Sort:\n");
                imprimirVetor(vetor, tamanho);
                break;
            default:
                printf("\nOpção inválida!\n");
        }

        printf("========================================\n");
        printf("Pressione Enter para continuar...\n");
        getchar(); 
        getchar(); 

    } while (opcao != 4);

    return 0;
}
