#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó do grafo
typedef struct Node {
    int data;
    struct Node* next;
} Node;

int dequeue(Node** queue) {
    if (*queue == NULL) {
        return -1;  // Fila vazia
    }
    int data = (*queue)->data;
    Node* temp = *queue;
    *queue = (*queue)->next;
    free(temp);
    return data;
}

// Função para adicionar um elemento à fila
void enqueue(Node** queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*queue == NULL) {
        *queue = newNode;
    } else {
        Node* temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


// Função de busca em largura (BFS)
void BFS(int start, int n, Node* graph[]) {
    // Array para marcar os nós visitados
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Fila para armazenar os nós a serem visitados
    Node* queue = NULL;

    visited[start] = 1;
    printf("Visitando o nó %d\n", start);
    enqueue(&queue, start);

    while (queue != NULL) {
        int current = dequeue(&queue);
        Node* temp = graph[current];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                printf("Visitando o nó %d\n", temp->data);
                enqueue(&queue, temp->data);
            }
            temp = temp->next;
        }
    }
}

// Função de busca em profundidade (DFS)
void DFS(int start, int n, Node* graph[], int visited[]) {
    visited[start] = 1;
    printf("Visitando o nó %d\n", start);

    Node* temp = graph[start];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFS(temp->data, n, graph, visited);
        }
        temp = temp->next;
    }
}

// Função para adicionar uma aresta ao grafo
void addEdge(Node* graph[], int src, int dest) {
    // Adiciona uma aresta do nó src para o nó dest

    // Cria um novo nó para o nó dest
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph[src];
    graph[src] = newNode;

    // Como o grafo é não-direcionado, também adicionamos uma aresta do nó dest para o nó src
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = src;
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

int main() {
    int n = 4;  // Número de nós do grafo
    Node* graph[n];
    int visited[n];
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    // Adicionar arestas ao grafo (exemplo)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    int choice;
    printf("Escolha o tipo de busca:\n");
    printf("1. Busca em Largura (BFS)\n");
    printf("2. Busca em Profundidade (DFS)\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            BFS(2, n, graph);  // Exemplo: inicia a BFS a partir do nó 2
            break;
        case 2:
            
            for (int i = 0; i < n; i++) {
                visited[i] = 0;
            }
            DFS(2, n, graph, visited);  // Exemplo: inicia a DFS a partir do nó 2
            break;
        default:
            printf("Escolha inválida\n");
    }

    return 0;
}
