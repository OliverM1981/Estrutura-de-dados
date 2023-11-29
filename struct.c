#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Pessoa{

    char nome [50];
    int idade;
    float altura;

};



int main(int argc, char *argv[]) {
    
     
    struct Pessoa pessoa1;
    struct Pessoa pessoa2;
    struct Pessoa pessoa3;
    struct Pessoa pessoa4;

   
    
    strcpy(pessoa1.nome, "Mauricio");
    pessoa1.idade = 35;
    pessoa1.altura = 1.82;
    
    printf("%s\n", pessoa1.nome);
    printf("%d\n", pessoa1.idade);
    printf("%.2f", pessoa1.altura);
 
	return 0;
}