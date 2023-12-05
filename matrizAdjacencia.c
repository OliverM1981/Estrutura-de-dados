#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

int size = 0;
int graph[MAX];
int adjacencyMatrix[MAX][MAX];
int option = 1;

// Prototipação
int graphSize();
void drawGraph();
void drawAdjacencyMatrix();
void insertEdge();
void removeEdge();
void showMenu();

int main() {
	setlocale(LC_ALL, "Portuguese");
	int i;
    while (size <= 0 || size > MAX) {
        size = graphSize();
        if (size <= 0 || size > MAX) {
            system("cls");
            printf("Escolha um valor entre 1 e %d!\n\n", MAX);
        } else {
            for (i = 0; i < size; i++) {
                graph[i] = i;
            }
        }
    }
    while (option != 0) {
        system("cls");
        drawGraph();
        drawAdjacencyMatrix();
        showMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                insertEdge();
                break;
            case 2:
                removeEdge();
                break;
        }
    }
    system("Pause");
    return 0;
}

// Define o número de vértices do Grafo
int graphSize() {
    int size;
    printf("Escolha a quantidade de vértices do grafo: ");
    scanf("%d", &size);
    return size;
}

// Função para desenhar o vetor de vértices
void drawGraph() {
	int i;
    printf("Listas de vértices\n[ ");
    for ( i = 0; i < size; i++) {
        printf("%d ", graph[i]);
    }
    printf("]");
}

// Função para desenhar a matriz de arestas
void drawAdjacencyMatrix() {
	int i, j;
    printf("\n\n  ");
    for (i = 0; i< size ; i++) {
    	
		printf(" %d", i);	
    	
	} 
	printf("\n", i);  
    for ( i = 0; i < size; i++) {
    	printf("%d|", i);
        for ( j = 0; j < size; j++) {
            printf(" %d", adjacencyMatrix[i][j]);
        }
        printf("|\n");
    }
    printf("\n\n");
}

// Inserir aresta
void insertEdge() {
    int vertex1, vertex2;
    system("cls");
    printf("Escolha o vértice de origem entre 0 a %d: ", size - 1);
    scanf("%d", &vertex1);
    printf("Escolha o vértice de destino entre 0 a %d: ", size - 1);
    scanf("%d", &vertex2);
    if (vertex1 > size - 1 || vertex2 > size - 1 || vertex1 < 0 || vertex2 < 0) {
        printf("\nOs valores precisam estar entre 0 e %d\n\n", size - 1);
        system("pause");
    } else {
        adjacencyMatrix[vertex1][vertex2] = 1;
       
    }
}

// Remover aresta
void removeEdge() {
    int vertex1, vertex2;
    system("cls");
    printf("Escolha o vértice de origem entre 0 a %d: ", size - 1);
    scanf("%d", &vertex1);
    printf("Escolha o vértice de destino entre 0 a %d: ", size - 1);
    scanf("%d", &vertex2);
    if (vertex1 > size - 1 || vertex2 > size - 1 || vertex1 < 0 || vertex2 < 0) {
        printf("\nOs valores precisam estar entre 0 e %d\n\n", size - 1);
        system("pause");
    } else {
        adjacencyMatrix[vertex1][vertex2] = 0;
        
    }
}

// Mostrar o menu de opções
void showMenu() {
    printf("\n***Matriz de Adjacências***\n");
    printf("1 - Inserir aresta\n");
    printf("2 - Remover aresta\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}
