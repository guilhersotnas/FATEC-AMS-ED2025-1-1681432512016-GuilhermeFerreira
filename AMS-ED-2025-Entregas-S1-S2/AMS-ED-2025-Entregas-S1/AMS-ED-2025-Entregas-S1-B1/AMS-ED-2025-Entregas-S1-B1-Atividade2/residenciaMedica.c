/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B1-2                          */
/*             Objetivo: Seleção para Residência Médica                             */
/*                                                                                  */
/*                                  Autor: Guilherme dos Santos Ferreira            */
/*                                                                  Data:28/02/2025 */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, numCandidatos;
    
    float notasPE[4], notasAC[5], notasPP[10], notasEB[3];
    float somaPE, menorPE, maiorPE;
    float somaAC, menorAC, maiorAC;
    float somaPP, menorPP, maiorPP;
    float somaEB, menorEB, maiorEB;
    
    printf("Insira a quantidade de candidatos: ");
    scanf("%d", &numCandidatos);
    
    if (numCandidatos > 50){
        printf("A quantidade máxima de candidatos é 50.");
        exit(0);
    } else {
        char nomes[numCandidatos][50];;
        float notasFinais[numCandidatos];
        
        for(i = 0; i < numCandidatos; i++){
            system("clear");
            printf("Nome do %dº candidato: ", i+1);
            scanf(" %[^\n]", *(nomes + i));
            
            somaPE = 0;  menorPE = 10;  maiorPE = 0;
            somaAC = 0;  menorAC = 10;  maiorAC = 0;
            somaPP = 0;  menorPP = 10;  maiorPP = 0;
            somaEB = 0;  menorEB = 10;  maiorEB = 0;
                
            for(j=0; j < 4; j++){
                printf("%dª Nota em Prova Escrita de %s: ", j+1, *(nomes + i));
                scanf("%f", (notasPE + j));
                
                if (*(notasPE + j) > maiorPE) maiorPE = *(notasPE + j);
                if (*(notasPE + j) < menorPE) menorPE = *(notasPE + j);
                somaPE += *(notasPE + j);
            }
            somaPE = somaPE - menorPE - maiorPE;
            
            for(j=0; j < 5; j++){
                printf("%dª Nota em Análise Curricular de %s: ", j+1, *(nomes + i));
                scanf("%f", (notasAC + j));
                
                if (*(notasAC + j) > maiorAC) maiorAC = *(notasAC + j);
                if (*(notasAC + j) < menorAC) menorAC = *(notasAC + j);
                somaAC += *(notasAC + j);
            }
            somaAC = somaAC - menorAC - maiorAC;
            
            for(j=0; j < 10; j++){
                printf("%dª Nota em Prova Prática de %s: ", j+1, *(nomes + i));
                scanf("%f", (notasPP + j));
                
                if (*(notasPP + j) > maiorPP) maiorPP = *(notasPP + j);
                if (*(notasPP + j) < menorPP) menorPP = *(notasPP + j);
                somaPP += *(notasPP + j);
            }
            somaPP = somaPP - menorPP - maiorPP;
            
            for(j=0; j < 3; j++){
                printf("%dª Nota em Entrevista em Banca Avaliadora de %s: ", j+1, *(nomes + i));
                scanf("%f", (notasEB + j));
                
                if (*(notasEB + j) > maiorEB) maiorEB = *(notasEB + j);
                if (*(notasEB + j) < menorEB) menorEB = *(notasEB + j);
                somaEB += *(notasEB + j);
            }
            somaEB = somaEB - menorEB - maiorEB;
            
            *(notasFinais + i) = ((somaPE*0.3) + (somaAC*0.1) + (somaPP*0.4) + (somaEB*0.2));

        }
        for (i = 0; i < numCandidatos - 1; i++){
            int maxIdx = i;
            for(j = i+1; j < numCandidatos; j++){
                if (*(notasFinais + j) > *(notasFinais + maxIdx)){
                    maxIdx = j;
                }
            }
            
            float tempNota = *(notasFinais + i);
            *(notasFinais + i) = *(notasFinais + maxIdx);
            *(notasFinais + maxIdx) = tempNota;
            
            char tempNome[50];
            strcpy(tempNome, *(nomes + i));
            strcpy(*(nomes + i), *(nomes + maxIdx));
            strcpy(*(nomes + maxIdx), tempNome);
        }
        
        system("clear");
        printf("Ranking dos 5 melhores candidatos:\n");
        for(i = 0; i < (numCandidatos < 5 ? numCandidatos : 5); i++){
            printf("%dº Lugar: %s - Nota Final: %.2f\n", i+1, *(nomes + i), *(notasFinais + i));
        }
    }
    return 0;
}