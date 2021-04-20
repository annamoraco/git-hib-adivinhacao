#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include "advinhacao.h"

void cabecalho(){
    printf("\n\n*******************************************\n");
    printf("*                                         *\n");
    printf("*   Bem vindo ao jogo de adivinha��o!!!   *\n");
    printf("*                                         *\n");
    printf("*******************************************\n\n");
}

int seleciona_dificuldade(){
    int x = 0;
    char nivel;
    int numerotentativas = 0;

        while (x == 0){

        printf("Selecione o n�vel de dificuldade desejado: \n");
        printf("(1) F�cil   (2) M�dio   (3) Dific�l \n\n");
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
            printf("\nEntrada inv�lida: %c\n\n",nivel);
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
        printf("Digite um n�mero maior ou igual zero: ");
        scanf("%s",&schute);

        if (schute[0] == '-' )
            {
                printf("\nVoc� n�o pode digitar n�meros negativos.\n");
                continue;
            } else {
                for (int i=0;schute[i]!='\0';i++)
                {
                    x = 0;
                    if(schute[i]>='0' && schute[i]<='9')
                    {
                        x = 1;

                    } else {
                        printf("\nValor inv�lido.\n");
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
        printf("\nVoc� errou.\nO n�mero secreto � maior.\n");
    }
    else
    {
        printf("\nVoc� errou.\nO n�mero secreto � menor.\n");
    }
    (*tentativa)++;
}

void analisaresultado(int tentativa , int numerotentativas){
    if (tentativa <= numerotentativas)
    {
        printf("\n\nParab�ns, voc� ganhou!!!\n\n");
        printf("\\m/_(>_<)_\\m/\n");
    }
    else 
    {
        printf("\n\nVoc� perdeu, tente mais uma vez.\n\n");
        printf(".���`(>__<)��`�. \n");
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