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
    
    printf("\n\nBem vindo ao jogo de adivinha��o!!! \n\n");

    printf("Selecione o n�vel de dificuldade desejado: \n");
    printf("(1) F�cil   (2) M�dio   (3) Dif�cil \n");
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
        printf("Digite um n�mero maior ou igual zero: ");
        scanf("%d",&chute);
        if (chute < 0)
        {
            printf("\nVoc� n�o pode digitar n�meros negativos.\n");
            continue;
        }

        if (chute == numerosecreto)
        {
            break;
        }
        else if (chute < numerosecreto)
        {
            printf("\nVoc� errou.\nO n�mero secreto � maior.\n");
        }
        else
        {
            printf("\nVoc� errou.\nO n�mero secreto � menor.\n");
        }

        tentativa++;
    }    

    if (tentativa <= numerotentativas)
    {
        printf("\n\nParab�ns, voc� ganhou!!!\n\n");
    }
    else 
    {
        printf("\n\nVoc� perdeu, tente mais uma vez.\n\n");
    }

}