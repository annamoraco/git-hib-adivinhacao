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
    int nivel;
    
    printf("Selecione o n�vel de dificuldade desejado: \n");
    printf("(1) F�cil   (2) M�dio   (3) Dif�cil \n");
    scanf("%d",&nivel);

    printf("%d \n",numerosecreto);

    printf("Digite um n�mero maior que zero: ");
    scanf("%d",&chute);

    if (chute == numerosecreto)
    {
        printf("Parab�ns, voc� ganhou!!!");
    }
    

    


}