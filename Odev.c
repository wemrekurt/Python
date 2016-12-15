#include <stdio.h>
#include <stdlib.h>

struct Vertex {
  int key;
  char val;
  struct AdjList* adjs;
};

struct AdjList {
  struct Vertex* vertex;
};

struct VertexList {
  struct Vertex* vertex;
};

struct Graph {
  int size;
  struct VertexList* array;
};

void addEdge(struct Graph* graph, int src, int dest){

  int i;
  for(i = 0; i < graph->size; i++)
    if(graph->array[src].vertex->adjs[i].vertex == NULL){
      graph->array[src].vertex->adjs[i].vertex = graph->array[dest].vertex;
      break;
    }

  for(i = 0; i< graph->size; i++)
    if(graph->array[dest].vertex->adjs[i].vertex == NULL){
      graph->array[dest].vertex->adjs[i].vertex = graph->array[src].vertex;
      break;
    }

  printf("%c ve %c arasinda kenar olusturuldu \n", graph->array[src].vertex->val, graph->array[dest].vertex->val);
}

struct Vertex* addVertex(struct Graph* graph, int key, char val){
  struct Vertex* newNode = (struct Vertex*) malloc(sizeof(struct Vertex));
  newNode->key = key;
  newNode->val = val;
  newNode->adjs = (struct AdjList*) malloc(graph->size * sizeof(struct AdjList));

  int i;
  for (i = 0; i < graph->size; ++i)
    newNode->adjs[i].vertex = NULL;

  graph->array[key].vertex = newNode;
  return newNode;
}

struct Graph* createGraph(int size){
  struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
  graph->size = size;

  graph->array = (struct VertexList*) malloc(size * sizeof(struct VertexList));

   // tüm komşuları null yaparak her bir ilişki durumunu boş olarak ilkliyoruz
  int i;
  for (i = 0; i < size; ++i)
    graph->array[i].vertex = NULL;

  return graph;
}

void printVertex(struct Graph* graph){
  int v;
  for (v = 0; v < graph->size; ++v) {
    struct Vertex* pCrawl = graph->array[v].vertex;
    printf("Key: %d Value: %c  \n", v, pCrawl->val);
  }
}

void listNeighbors(struct Graph* graph, int key){
  int i;
  printf("%c 'den gidilebilecek yerler: \n", graph->array[key].vertex->val);
  for(i = 0; i < graph->size; i++){
    if(graph->array[key].vertex->adjs[i].vertex != NULL){
      printf("%c | ",graph->array[key].vertex->adjs[i].vertex->val);
    }else{
      printf("\n");
      break;
    }
  }

}

/*
  Buraya Kadar Graph yapılarını ve fonksiyonlarını gerçekledik. Buradan sonra
  bfs için gerekli fonksiyonları gerçekleyeceğiz.
*/

// Breath First Search
bool bfs(struct Graph* graph, int from, int to){
  int i;
  for(i = 0; graph -> size; i++){

  }
}

int main(){
  int sizeOfCities = 18;
  struct Graph* graph = createGraph(sizeOfCities);

  for(int i = 0; i < sizeOfCities; i++)
    addVertex(graph, i, i+65);


  addEdge(graph, 3, 5);
  addEdge(graph, 3, 7);

  listNeighbors(graph,3);
  listNeighbors(graph,5);

  printVertex(graph);

}
