#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct no {

  int dado;
  struct no *prox;

};

typedef struct no *No;

No Lista;

void mostrarLista(No Lista);
void inserirLista(No *Lista);
void removeLista(No *Lista);
void desempilhar(No *Lista);
void desenfileirar(No *Lista);


int main(){
setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  Lista = NULL;
  int opcao;
  do{
    system ("cls");
    mostrarLista(Lista);
    printf("\n1 - Inserir na Lista\n2 - Remover da lista\n3 - Desempilhar\n4 - Desenfileirar\n5 - Sair");

    printf("\nEscolha uma das opções acima: ");
    scanf("%d", &opcao);

    switch (opcao){
      case 1:

        inserirLista(&Lista);

        break;

        case 2:

            removeLista(&Lista);

        break;

        case 3:

            desempilhar(&Lista);

        break;

        case 4:

            desenfileirar(&Lista);

        break;

        case 5:

            free(Lista);
            return 0;

        break;

        default:

            printf("\nOpção inválida");
              printf("\nPressione qualquer tecla para continuar...");
            getchar();
            getchar();

        break;
    }

  } while (opcao !=5);

}

void mostrarLista(No Lista){

  if (Lista == NULL){
    printf("\nA lista está vazia");
  }else{
    printf("Lista:");
    while(Lista != NULL){
      printf("%d ", Lista->dado);
      Lista = Lista->prox;

    }
  }

}
void inserirLista(No *Lista){

  No novoNo = (No) malloc(sizeof(struct no));
  novoNo->dado = rand()%100;
  novoNo->prox = NULL;  
  if (*Lista == NULL){
    *Lista = novoNo;

  }else{
    No atual = *Lista;
    while(atual->prox != NULL){
      atual=atual->prox;
    }
    atual->prox = novoNo;
  }    
};

void removeLista(No *Lista){

  if (*Lista == NULL){
    printf("\n lista está vazia");
    return;
  }
    int dado;
    printf("Digite o dado a ser removido: ");
    scanf("%d", &dado);

    No atual = *Lista;
    No anterior = NULL;

    while (atual != NULL && atual->dado != dado) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {

        printf("O dado %d não foi encontrado na lista.\n", dado);
        return;
    }

    if (anterior == NULL) {
        *Lista = atual->prox;
    }else {

        anterior->prox = atual->prox;
    }

    free(atual);

}

void desempilhar(No *Lista) {
    if (*Lista == NULL) {
        printf("\nA lista está vazia");
        return;
    }
    No atual = *Lista;
    No anterior = NULL;
    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior == NULL) {
        free(*Lista);
        *Lista = NULL;
    } else {
        free(atual);
        anterior->prox = NULL;
    }
}



void desenfileirar(No *Lista) {
    if (*Lista == NULL) {
        printf("\nA lista está vazia");
        return;
    }

    No primeiro = *Lista;
    *Lista = primeiro->prox;

    free(primeiro);
}
