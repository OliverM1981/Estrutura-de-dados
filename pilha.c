#include <stdio.h>
#include <stdlib.h>




int soma();



int main (void){
    

   int x, y; 
   printf ( "Insira o valor da variavel A:");
   scanf( "%d", &x);
    printf ( "Insira o valor da variavel B:");
   scanf( "%d", &y);
  
   printf( "O resultado da soma é %d", soma(x,y));
}

int soma ( int a, int b){

    int resultado = a + b;

}

