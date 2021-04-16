#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    int s = time(NULL);
    srand(s);
    int numerosecreto = rand()%100;
    int numerotentativas = 0;
    char schute[5];
    int chute = 1;
    char nivel; 
    int tentativa = 1;
    int x = 0;
    
    printf("\n\n*******************************************\n");
    printf("*                                         *\n");
    printf("*   Bem vindo ao jogo de adivinhação!!!   *\n");
    printf("*                                         *\n");
    printf("*******************************************\n\n");

    while (x == 0){

        printf("Selecione o nível de dificuldade desejado: \n");
        printf("(1) Fácil   (2) Médio   (3) Dificíl \n\n");
        printf("Escolha: ");
        scanf("%c",&nivel);
        fflush(stdin);

        if(nivel>='0' && nivel<='9')
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


    while (tentativa <= numerotentativas)
    {
        x = 0;

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

        chute = atoi(schute);

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
        printf("\\m/_(>_<)_\\m/\n");
    }
    else 
    {
        printf("\n\nVocê perdeu, tente mais uma vez.\n\n");
        printf(".·´¯`(>__<)´¯`·. \n");
    }

}