#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int s = time(NULL);
    srand(s);
    int numerosecreto = rand()%10;
    int numerotentativas = 20;
    
    printf("%d \n",numerosecreto);


}