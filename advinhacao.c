#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include "advinhacao.h"

void cabecalho(){
    printf("\n\n*******************************************\n");
    printf("*                                         *\n");
    printf("*   Bem vindo ao jogo de adivinhação!!!   *\n");
    printf("*                                         *\n");
    printf("*******************************************\n\n");
}

int seleciona_dificuldade(){
    int x = 0;
    char nivel;
    int numerotentativas = 0;

        while (x == 0){

        printf("Selecione o nível de dificuldade desejado: \n");
        printf("(1) Fácil   (2) Médio   (3) Dificíl \n\n");
        printf("Escolha: ");
        scanf("%c",&nivel);
        fflush(stdin);

        if(nivel>='1' && nivel<='3')
        {   
            switch(nivel)
            {
                case '1':
                    numerotentativas = 50;
                    break;

                case '2':
                    numerotentativas = 25;
                    break;

                default:
                    numerotentativas = 10;
                    break;
            }         
            x = 1;
        } else {
            printf("\nEntrada inválida: %c\n\n",nivel);
        }
    }
    return numerotentativas;
}

int recebefiltrachute(int tentativa, int numerotentativas){

    int x = 0; 
    char schute[5];

    while (x == 0)
    {    
        printf("\nTentativa %d de %d\n",tentativa,numerotentativas);
        printf("Digite um número maior ou igual zero: ");
        scanf("%s",&schute);

        if (schute[0] == '-' )
            {
                printf("\nVocê não pode digitar números negativos.\n");
                continue;
            } else {
                for (int i=0;schute[i]!='\0';i++)
                {
                    x = 0;
                    if(schute[i]>='0' && schute[i]<='9')
                    {
                        x = 1;

                    } else {
                        printf("\nValor inválido.\n");
                        break;
                    }            
                }
            }
    }

    return atoi(schute);
}

void analisachute(int chute, int numerosecreto, int* tentativa){
    if (chute < numerosecreto)
    {
        printf("\nVocê errou.\nO número secreto é maior.\n");
    }
    else
    {
        printf("\nVocê errou.\nO número secreto é menor.\n");
    }
    (*tentativa)++;
}

void analisaresultado(int tentativa , int numerotentativas){
    if (tentativa <= numerotentativas)
    {
        printf("\n\nParabéns, você ganhou!!!\n\n");
        printf("\\m/_(>_<)_\\m/\n");
    }
    else 
    {
        printf("\n\nVocê perdeu, tente mais uma vez.\n\n");
        printf(".·´¯`(>__<)´¯`·. \n");
    }
}

int main(){

    setlocale(LC_ALL, "Portuguese");
    int s = time(NULL);
    srand(s);
    int numerosecreto = rand()%100;
    int numerotentativas = 0;
    int chute = 1; 
    int tentativa = 1;
    
    cabecalho();

    numerotentativas = seleciona_dificuldade(); 

    while (tentativa <= numerotentativas )
    {                
        chute = recebefiltrachute(tentativa, numerotentativas);   

        printf("chute: %d",chute);  

        if (chute == numerosecreto) 
        {
            break;
        }
        
        analisachute(chute, numerosecreto,&tentativa);      

    }    

    analisaresultado(tentativa, numerotentativas);

}