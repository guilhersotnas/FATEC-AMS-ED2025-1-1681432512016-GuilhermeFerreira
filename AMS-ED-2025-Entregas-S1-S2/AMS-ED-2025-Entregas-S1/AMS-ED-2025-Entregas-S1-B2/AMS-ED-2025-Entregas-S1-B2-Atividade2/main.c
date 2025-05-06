/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B2-2                          */
/*                                  Objetivo: Bubble Sort                           */
/*                                                                                  */
/*                                              Autores: Guilherme Santos           */
/*                                                                  Data:06/05/2025 */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

int lerQuantidade() {
    int n;
    printf("Digite a quantidade de números: ");
    scanf("%d", &n);
    return n;
}

void lerArray(int array[], int n) {
    printf("Digite os %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void bubbleSort(int array[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void exibirArray(int array[], int n) {
    printf("Array ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n = lerQuantidade();      
    int array[n];                 

    lerArray(array, n);         
    bubbleSort(array, n);        
    exibirArray(array, n);      

    return 0;
}