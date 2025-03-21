/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B1-3                          */
/*             Objetivo: Sistema de Gerenciamento de Pedidos para um Restaurante    */
/*                                                                                  */
/*                                  Autor: Guilherme dos Santos Ferreira            */
/*                                                                  Data:12/03/2025 */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pedido{
    int num;
    char nomeCliente[30];
    char prato[30];
    int quant;
    char status[10];
    struct Pedido *prox;
};

void inserirPedido(struct Pedido **inicio, int num, char nomeCliente[], char prato[], int quant, char status[]){
    struct Pedido *novoPedido = (struct Pedido*)malloc(sizeof(struct Pedido));
    if(novoPedido == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }
    novoPedido->num = num;
    strcpy(novoPedido->nomeCliente, nomeCliente);
    strcpy(novoPedido->prato, prato);
    novoPedido->quant = quant;
    strcpy(novoPedido->status, status);
    novoPedido->prox = *inicio;
    *inicio = novoPedido;
}

void obterPedido(struct Pedido *inicio, int num){
    struct Pedido *ptr = inicio;
    while(ptr != NULL)
    {
        if(ptr->num == num)
        {
            system("clear");
            printf("==================================\n");
            printf("          Pedido #%d \n", num);
            printf("==================================\n");
            printf("Número do Pedido: %d\nNome do Cliente: %s\nDescrição do prato: %s\nQuantidade: %d\nStatus: %s\n", 
            ptr->num, ptr->nomeCliente, ptr->prato, ptr->quant, ptr->status);
            return;
        }
        ptr = ptr->prox;
    }
    printf("Produto com número do pedido %d não encontrado.\n", num);
}

void atualizarStatus(struct Pedido *inicio, int num){
    struct Pedido *ptr = inicio;
    while(ptr != NULL)
    {
        if(ptr->num == num)
        {
            printf("===============================\n");
            printf("Status atual do Pedido: %s\n", ptr->status);
            printf("Atualize o Status do Pedido (pendente, em preparo, pronto, entregue): ");
            scanf(" %[^\n]", ptr->status);
            system("clear");
            printf("Status do pedido atualizado com sucesso!\n");
            return;
        }
        ptr = ptr->prox;
    }
    system("clear");
    printf("Produto com número do pedido %d não encontrado.\n", num);
}

void deletarPedido(struct Pedido **inicio, int num){
    struct Pedido *atual = *inicio;
    struct Pedido *anterior = NULL;
    
    while (atual != NULL && atual->num != num) {
        anterior = atual;
        atual = atual->prox;
    }
    
    if (atual == NULL) {
        system("clear");
        printf("Pedido com número %d não encontrado.\n", num);
        return;
    }
    
    if (anterior == NULL) {
        *inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    system("clear");
    printf("Pedido #%d deletado com sucesso!\n", num);
}

void liberarLista(struct Pedido **inicio){
    struct Pedido *atual = *inicio;
    struct Pedido *prox;

    while (atual != NULL) {
        prox = atual->prox;  
        free(atual);         
        atual = prox;        
    }

    *inicio = NULL;
    system("clear");
    printf("Lista de pedidos liberada com sucesso!\n");
}

int main()
{
    int opcao=0;
    int listaCriada = 0; 
    struct Pedido *inicio = NULL;
    
    while(opcao != 7){
        printf("==================================\n");
        printf("     Gerenciamento de Pedidos  \n");
        printf("==================================\n");
        printf("1- Criar Lista de Pedidos: \n");
        printf("2- Inserir Pedido: \n");
        printf("3- Obter Pedido: \n");
        printf("4- Atualizar status do pedido: \n");
        printf("5- Deletar Pedido: \n");
        printf("6- Liberar Lista: \n");
        printf("7- Encerrar: \n");
        printf("==================================\n");
        printf("Insira o número da opção desejada: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                if(listaCriada == 0)
                {
                    listaCriada = 1;
                    system("clear");
                    printf("Lista de pedidos criada com sucesso!\n");
                }
                else
                {
                    system("clear");
                    printf("A lista já foi criada anteriormente.\n");
                }
                break;
            case 2:
                if (listaCriada == 0)
                {
                    system("clear");
                    printf("Erro: Você precisa criar a lista primeiro (Opção 1)!\n");
                }
                else
                {
                    int num;
                    char nomeCliente[30], prato[30], status[10];
                    int quant;
                    
                    system("clear");
                    printf("==========================\n");
                    printf("     Inserir um Pedido \n");
                    printf("==========================\n");
                    printf("Número do Pedido: ");
                    scanf("%d", &num);
                    printf("Nome do Cliente: ");
                    scanf(" %[^\n]", nomeCliente);
                    printf("Descrição do Prato: ");
                    scanf(" %[^\n]", prato);
                    printf("Quantidade: ");
                    scanf("%d", &quant);
                    printf("Status do Pedido (pendente, em preparo, pronto, entregue): ");
                    scanf(" %[^\n]", status);
                    system("clear");
                    
                    inserirPedido(&inicio, num, nomeCliente, prato, quant, status);
                    printf("==================================\n");
                    printf("    Pedido Inserido com Sucesso!\n");
                }
                break;
            case 3:
                if (listaCriada == 0)
                {
                    system("clear");
                    printf("Erro: Você precisa criar a lista primeiro (Opção 1)!\n");
                }
                else
                {
                    int num;
                    system("clear");
                    printf("==========================\n");
                    printf("     Obter um Pedido \n");
                    printf("==========================\n");
                    printf("Número do Pedido: ");
                    scanf("%d", &num);
                    system("clear");
                
                    obterPedido(inicio, num);
                }
                break;
            case 4:
                if (listaCriada == 0)
                {
                    system("clear");
                    printf("Erro: Você precisa criar a lista primeiro (Opção 1)!\n");
                }
                else
                {
                    int num;
                    system("clear");
                    printf("===============================\n");
                    printf(" Atualizar status de um pedido \n");
                    printf("===============================\n");
                    printf("Número do Pedido que deseja atualizar o status: ");
                    scanf("%d", &num);
                    atualizarStatus(inicio, num);
                }
                break;
            case 5:
                if (listaCriada == 0)
                {
                    system("clear");
                    printf("Erro: Você precisa criar a lista primeiro (Opção 1)!\n");
                }
                else
                {
                    int num;
                    system("clear");
                    printf("==========================\n");
                    printf("     Deletar um Pedido \n");
                    printf("==========================\n");
                    printf("Número do Pedido que deseja deletar: ");
                    scanf("%d", &num);
                    
                    deletarPedido(&inicio, num);
                }
                break;
            case 6:
                if (listaCriada == 0) {
                    system("clear");
                    printf("Erro: A lista ainda não foi criada!\n");
                } else {
                    liberarLista(&inicio);
                    listaCriada = 0;
                }
                break;
            case 7:
                system("clear");
                liberarLista(&inicio);
                listaCriada = 0;
                printf("Programa encerrado com sucesso!");
                break;
            default:
                system("clear");
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    
    return 0;
}