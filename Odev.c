#include <stdio.h>
#include <stdlib.h>


// Graph için her bir düğüme Vertex dedik.
struct Vertex {
  int key;
  char val;
  char color;
  int distance;
  int adjSize;
  struct Vertex* pred;
  struct AdjList* adjs;
};

// Düğümün komşularını tutacağımız AdjList yapısı
struct AdjList {
  struct Vertex* vertex;
};

// Graph içindeki düğümleri tutacağımız VertexList yapısı
struct VertexList {
  struct Vertex* vertex;
};

// Graph yapısı
struct Graph {
  int size;
  struct VertexList* array;
};

// Düğüm ekleme fonksiyonu (dönüş elemanının türü Vertex)
struct Vertex* addVertex(struct Graph* graph, int key, char val){
  struct Vertex* newNode = (struct Vertex*) malloc(sizeof(struct Vertex));
  newNode->key = key;
  newNode->val = val;
  newNode->color = 'w';
  newNode->distance = 0;
  newNode->adjSize = 0;
  newNode->pred = NULL;
  newNode->adjs = (struct AdjList*) malloc(graph->size * sizeof(struct AdjList));

  int i;
  for (i = 0; i < graph->size; ++i)
    newNode->adjs[i].vertex = NULL;

  graph->array[key].vertex = newNode;
  return newNode;
}

// Komşuluk ilişkisi oluşturmak için yazdığımız fonksiyon.
void addEdge(struct Graph* graph, int src, int dest){

  int i;
  int state = 0;
  // src keyli düğüme dest keyli düğümü komşu olarak ekliyoruz.
  for(i = 0; i < graph->size; i++){
    if(graph->array[src].vertex->adjs[i].vertex == NULL){
      graph->array[src].vertex->adjs[i].vertex = graph->array[dest].vertex;
      graph->array[src].vertex->adjSize = graph->array[src].vertex->adjSize +1;
      break;
    }else{
      // Daha once komsuluk iliskisi kurulmus aynı elemanlar icin tekrar kurulmaması gerekiyor.
      if(graph->array[src].vertex->adjs[i].vertex->key == dest){
        state = 1;
        break;
      }
    }
  }

  // dest keyli düğüme src keyli düğümü komşu olarak ekliyoruz.
  if(state == 0){
    for(i = 0; i < graph->size; i++){
      if(graph->array[dest].vertex->adjs[i].vertex == NULL){
        graph->array[dest].vertex->adjs[i].vertex = graph->array[src].vertex;
        graph->array[dest].vertex->adjSize = graph->array[dest].vertex->adjSize +1;
        break;
      }
    }
    // printf("%c ve %c arasinda kenar olusturuldu \n", graph->array[src].vertex->val, graph->array[dest].vertex->val);
  }else{
    printf("%c ve %c arasinda daha once kenar olusturulmus. O nedenle kenar olusturulmadi. \n", graph->array[src].vertex->val, graph->array[dest].vertex->val);
  }

}

// Graph oluşturduğumuz fonksiyon.
struct Graph* createGraph(int size){
  struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
  graph->size = size;

  graph->array = (struct VertexList*) malloc(size * sizeof(struct VertexList));

   // Tüm değerleri null yaparak her bir düğümü durumunu boş olarak ilkliyoruz
  int i;
  for (i = 0; i < size; ++i)
    graph->array[i].vertex = NULL;

  return graph;
}

// Bir düğümün komşularını listeleyen fonksiyon
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

// Tüm düğümlerin key-value görebilmek için printVertex fonksiyonu
void printVertex(struct Graph* graph){
  int v;
  for (v = 0; v < graph->size; ++v) {
    struct Vertex* pCrawl = graph->array[v].vertex;
    if(pCrawl->pred != NULL){
      printf("Key: %d Value: %c Color: %c Distance: %d Pred: %c \n", v, pCrawl->val, pCrawl->color, pCrawl->distance, pCrawl->pred->val);
    }else{
      printf("Key: %d Value: %c Color: %c Distance: %d Pred: NULL \n", v, pCrawl->val, pCrawl->color, pCrawl->distance);
    }

    listNeighbors(graph, pCrawl->key);
  }
}


/**
  Tüm yolları bulmak için recrusive bir fonksiyon kullanacagiz. Bu fonksiyon
  icinde cikmaz yok oldugunda bir onceki dugumden devam etmesi gerekeceginden
  bir de stack veri yapisina ihtiyac var.
*/


struct Stack {
  int size;
  int array[];
};

struct Stack* createStack(int size){
  struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
  stack->size = size;

  int i;
  // Tum vertex turundeki elemanlari NULL yaparak yigini ilkliyoruz.
  for (i = 0; i < size; ++i)
    stack->array[i] = -1;

  return stack;

}

int push(struct Stack* stack, int key){
  int i;
  for(i = 0; i < stack->size; i++){
    if(stack->array[i] < 0 ){
      stack->array[i] = key;
      break;
    }
  }
  return key;
}

int pull(struct Stack* stack){
  int i;
  int j;
  while(stack->array[i] > -1 && i < stack->size){
    j = stack->array[i];
    i++;
  }
  stack->array[i-1] = -1;
  return j;
}

void printWay(struct Graph* graph, struct Stack* stack){
  int i = 0;
  while(stack->array[i] > -1){
    // printf("%c -->",graph->array[stack->array[i]].vertex->val);
    printf("%d | ",stack->array[i]);
    i++;
  }
}

void findAllWay(struct Graph* graph, struct Stack* stack, int from, int to){
  int i = 0;
  int j;
  struct Vertex* v = graph->array[from].vertex;
  v->color = 'g';
  push(stack, from);
  for(j = 0; j < v->adjSize; j++){
    struct Vertex* w = v->adjs[j].vertex;
    printf("%c (%d) nin komsu: %c (%d) renk %c \n", v->val, v->key, w->val, w->key, w->color);

    if(w->color == 'w'){
      if(w->key != to){
        printWay(graph, stack);
        printf("\n");  printf("\n");
        findAllWay(graph, stack, w->key, to);
      }else{
        // printWay(graph, stack);
        printf("%c \n", w->val);
        pull(stack);
      }
    }else{
      i++;
    }
  }


}

int main(){
  // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
  // A B C D E F G H I J K  L  M  N  0  P  Q  R
  int sizeOfCities = 18;
  struct Graph* graph = createGraph(sizeOfCities);
  struct Stack* stack = createStack(sizeOfCities * sizeOfCities);
  int i;
  for(i = 0; i < sizeOfCities; i++)
    addVertex(graph, i, i+65);


  addEdge(graph, 0, 1);   // A-B
  addEdge(graph, 0, 3);   // A-D
  addEdge(graph, 0, 5);   // A-F
  addEdge(graph, 0, 7);   // A-H
  addEdge(graph, 1, 2);   // B-C
  addEdge(graph, 1, 17);  // B-R
  addEdge(graph, 1, 9);   // B-J
  addEdge(graph, 1, 8);   // B-I
  addEdge(graph, 2, 16);  // C-R
  addEdge(graph, 2, 17);  // C-Q
  addEdge(graph, 2, 3);   // C-D
  addEdge(graph, 3, 16);  // D-Q
  addEdge(graph, 3, 15);  // D-P
  addEdge(graph, 3, 4);   // D-E
  addEdge(graph, 4, 15);  // E-P
  addEdge(graph, 4, 13);  // E-N
  addEdge(graph, 4, 5);   // E-F
  addEdge(graph, 5, 13);  // F-N
  addEdge(graph, 5, 12);  // F-M
  addEdge(graph, 5, 6);   // F-G
  addEdge(graph, 6, 12);  // G-M
  addEdge(graph, 6, 11);  // G-L
  addEdge(graph, 6, 7);   // G-H
  addEdge(graph, 7, 11);  // H-L
  addEdge(graph, 7, 10);  // H-K
  addEdge(graph, 7, 8);   // H-I
  addEdge(graph, 8, 10);  // I-K
  addEdge(graph, 8, 9);   // I-J


  listNeighbors(graph,3);
  // printVertex(graph);
   findAllWay(graph, stack, 6, 12);

  // push(stack, 0);
  // push(stack, 12);
  // push(stack, 15);
  // printWay(graph, stack);
  // printf("\n cekilen: %d \n",pull(stack));
  // printWay(graph,stack);
  // printf("\n");



  //
  // listNeighbors(graph,5);

  // struct Queue* queue = createQueue();
  // enqueue(queue, graph->array[0].vertex);
  // enqueue(queue, graph->array[3].vertex);
  // enqueue(queue, graph->array[1].vertex);
  // printQueue(queue);
  // dequeue(queue);
  // printQueue(queue);


  // bfs(graph, 6);
  // printVertex(graph);

}
