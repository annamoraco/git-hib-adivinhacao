#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    int s = time(NULL);
    srand(s);
    int numerosecreto = rand()%10;
    int numerotentativas = 20;
    int chute = 0;
    int nivel, tentativa = 1;
    
    printf("Bem vindo ao jogo de adivinha��o!!! \n\n");

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

    printf("Tentativa %d de %d\n",tentativa,numerotentativas);
    printf("Digite um n�mero maior que zero: ");
    scanf("%d",&chute);

    if (chute == numerosecreto)
    {
        printf("\n\nParab�ns, voc� ganhou!!!\n\n");
    }
    else if (chute < numerosecreto)
    {
        printf("\nVoc� errou.\nO n�mero secreto � maior.\n");
    }
    else
    {
        printf("\nVoc� errou.\nO n�mero secreto � menor.\n");
    }
    

}