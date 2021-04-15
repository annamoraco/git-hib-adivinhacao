#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    int s = time(NULL);
    srand(s);
    int numerosecreto = rand()%100;
    int numerotentativas = 20;
    int chute = -1;
    int nivel, tentativa = 1;
    
    printf("\n\nBem vindo ao jogo de adivinhação!!! \n\n");

    printf("Selecione o nível de dificuldade desejado: \n");
    printf("(1) Fácil   (2) Médio   (3) Difí­cil \n");
    scanf("%d",&nivel);
    switch(nivel)
    {
        case 1:
        numerotentativas = 50;
        break;

        case 2:
        numerotentativas = 25;
        break;

        default:
        numerotentativas = 10;
    }

    printf("%d \n",numerosecreto);

    while (tentativa <= numerotentativas)
    {
        printf("\nTentativa %d de %d\n",tentativa,numerotentativas);
        printf("Digite um número maior ou igual zero: ");
        scanf("%d",&chute);
        if (chute < 0)
        {
            printf("\nVocê não pode digitar números negativos.\n");
            continue;
        }

        if (chute == numerosecreto)
        {
            break;
        }
        else if (chute < numerosecreto)
        {
            printf("\nVocê errou.\nO número secreto é maior.\n");
        }
        else
        {
            printf("\nVocê errou.\nO número secreto é menor.\n");
        }

        tentativa++;
    }    

    if (tentativa <= numerotentativas)
    {
        printf("\n\nParabéns, você ganhou!!!\n\n");
    }
    else 
    {
        printf("\n\nVocê perdeu, tente mais uma vez.\n\n");
    }

}