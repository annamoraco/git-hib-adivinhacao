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
    
    printf("%d \n",numerosecreto);


}