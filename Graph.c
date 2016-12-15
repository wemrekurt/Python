#include <stdio.h>
#include <stdlib.h>

// Komşuluk için Düğüm yapısı
struct AdjListNode {
  int dest;
	char name;
  struct AdjListNode* next;
};

// Komşuluk listesi
struct AdjList {
  struct AdjListNode *head;  // pointer to head node of list
};

// Graph'ı temsil edecek struct. Komşuluk listesini array içinde tutan bir graph.
// array'in boyutu V'ye bağlı olarak belirlenecek. (V=5 için 5 düğümü olan bir graph)
struct Graph {
  int V;
  struct AdjList* array;
};

// Yeni bir düğüm eklemek için fonksiyon
struct AdjListNode* newAdjListNode(int dest, char name) {
  struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
  newNode->dest = dest;
	newNode->name = name;
  newNode->next = NULL;
  return newNode;
}

// V köşe sayısı olan graph oluşturmak için fonksiyon
struct Graph* createGraph(int V) {
  struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
  graph->V = V;

  // Komşuluk listesinden array oluştur. V kadar olacak.
  graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

   // head'i null yaparak her bir ilişki durumunu boş olarak ilkliyoruz
  int i;
  for (i = 0; i < V; ++i)
    graph->array[i].head = NULL;

  return graph;
}

// Yönlendirilmemiş düğüm için kenar ekliyoruz.
void addEdge(struct Graph* graph, int src, char srcname, int dest, char name) {
    // src'dan dest'e (kaynaktan hedefe) köşe ekliyoruz.  Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, name);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, srcname);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n %c %d düğümünün komşulukları \n", pCrawl->name, v);
        while (pCrawl)
        {
            printf("-> %c", pCrawl->name);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void printGraphEdges(struct Graph* graph, int v) {
	struct AdjListNode* pCrawl = graph->array[v].head;
  printf("\n Adjacency list of vertex %d\n head ", v);
  while (pCrawl)
  {
    printf("-> %d", pCrawl->name);
    pCrawl = pCrawl->next;
  }
    printf("\n");
}

// Driver program to test above functions
int main() {
    // create the graph given in above fugure
    int V = 4;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 'S', 1, 'A');
    addEdge(graph, 0, 'S', 2, 'C');
    addEdge(graph, 0, 'S', 3, 'X');

    // addEdge(graph, 1, 'S', 0, 'A');

    // print the adjacency list representation of the above graph
    printGraph(graph);


    return 0;
}
