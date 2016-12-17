#include <stdio.h>
#include <stdlib.h>


// Graph için her bir düğüme Vertex dedik.
struct Vertex {
  int key;
  char val;
  char color;
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
        break;
      }
    }
    printf("%c ve %c arasinda kenar olusturuldu \n", graph->array[src].vertex->val, graph->array[dest].vertex->val);
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

// Tüm düğümlerin key-value görebilmek için printVertex fonksiyonu
void printVertex(struct Graph* graph){
  int v;
  for (v = 0; v < graph->size; ++v) {
    struct Vertex* pCrawl = graph->array[v].vertex;
    printf("Key: %d Value: %c  \n", v, pCrawl->val);
  }
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

/**
  Buraya Kadar Graph yapılarını ve fonksiyonlarını gerçekledik. Buradan sonra
  bfs için gerekli fonksiyonları gerçekleyeceğiz.

  BFS için bize bir kuyruk yapısı gerek. Temel kuyruğa ekle ve kuyruktan çıkar
  işlemleri için basitçe kuyruk yapısı gerçekleyeceğiz.
*/

struct VertList{
  struct Vertex* vertex;
};

struct Queue {
  int size;
  struct VertList* elements;
};

struct Queue* createQueue(){
  int len = sizeof(struct VertexList) * sizeof(struct VertexList);
  struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->size = len;
  queue->elements = (struct VertList*) malloc(len);

  printf("uzunluk: %d \n",len);
  int i;
  // Tüm vertex türündeki elemanları NULL yaparak kuyruğu ilkliyoruz.
  for (i = 0; i < len; ++i)
    queue->elements[i].vertex = NULL;

  return queue;
}

// Kuyruk elemanlarini ekrana yazmak istiyoruz.
void printQueue(struct Queue* queue){
  int i;
  for(i=0; i < queue->size; i++){
    if(queue->elements[i].vertex != NULL){
      printf("%c - ", queue->elements[i].vertex->val);
    }else{
      printf("\n");
      break;
    }
  }
}

// Kuyruktan eleman cikarma islemi.
struct Vertex* dequeue(struct Queue* queue){
  struct Vertex* vert = queue->elements[0].vertex;
  int i;
  // Kuyrukta kaydirma islemi.
  for(i = 0; i < queue->size - 1; i++){
    queue->elements[i].vertex = queue->elements[i+1].vertex;
    if(queue->elements[i].vertex == NULL){
      break;
    }
  }
  return vert;
}

// Kuyruga eleman ekleme islemi
struct Vertex* enqueue(struct Queue* queue, struct Vertex* vert){
  int i;
  for(i = 0; i < queue->size; i++){
    if(queue->elements[i].vertex == NULL){
      queue->elements[i].vertex = vert;
      break;
    }
  }

  return vert;
}

// Breath First Search
// bool bfs(struct Graph* graph, int from, int to){
//   int i;
//   for(i = 0; graph -> size; i++){
//
//   }
//   return false;
// }

int main(){
  int sizeOfCities = 18;
  struct Graph* graph = createGraph(sizeOfCities);

  for(int i = 0; i < sizeOfCities; i++)
    addVertex(graph, i, i+65);


  // addEdge(graph, 3, 5);
  // addEdge(graph, 3, 7);
  // addEdge(graph, 8, 5);
  //
  // listNeighbors(graph,3);
  // listNeighbors(graph,5);

  struct Queue* queue = createQueue(10);
  enqueue(queue, graph->array[0].vertex);
  enqueue(queue, graph->array[3].vertex);
  enqueue(queue, graph->array[1].vertex);
  printQueue(queue);
  dequeue(queue);
  printQueue(queue);
  


  // printVertex(graph);

}
