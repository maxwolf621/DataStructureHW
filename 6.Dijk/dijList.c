#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXV 100
#define INFI 9999

typedef struct edgenode* edgeptr;
struct edgenode
{
	int vertex   ;
    int weight   ; 
	edgeptr next ;
};

typedef struct graph* graphptr;
struct graph
{
	int vertices ;
    int edges    ;
    edgeptr *edgesof ;
};

void insertNode(graphptr g,int weight, int v1, int v2)
{
    edgeptr temp;
    temp = (edgeptr)malloc(sizeof(struct edgenode));
    temp->vertex = v2;
    temp->weight = weight;
    temp->next   = g->edgesof[v1];
    g->edgesof[v1] = temp        ;
}

void printGraph(graphptr g)
{
    int v ;
    edgeptr temp;
    for(v = 0 ; v < g->vertices ; v++)
    {
        temp = g->edgesof[v];
        printf("Node: %d ", v);
        while(temp)
        {
            printf("%d ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

graphptr initializeGraph()
{
    graphptr g = (graphptr)malloc(sizeof(struct graph));
    g->vertices = 0;
    g->edges    = 0;
    printf("vertices and edges :");
    scanf("%d %d",&(g->vertices),&(g->edges));
    g->edgesof      =malloc( (g->vertices)*sizeof(struct edgeptr*));
    
    // Nodelist
    int vertex;
    for(vertex = 0 ; vertex < g->vertices ; vertex++){
        //g->edgesof[vertex] = (edgeptr)malloc(sizeof(struct edgenode));
        //g->edgesof[vertex]->vertex = vertex   ;
        //printf("%d : \n",g->edgesof[vertex]->vertex);
        //g->edgesof[vertex]->weight = 0        ;
        //g->edgesof[vertex]->next   = g->edgesof[vertex];
        g->edgesof[vertex] = NULL;
    }
    int edge, weight, x, y;
    edgeptr temp  ;
    for(edge = 0 ; edge < g->edges ; edge++)
    {
        printf("Edges of Vx to Vy :");
        scanf("%d %d",&x,&y );
        printf("Weight :");
        scanf("%d",&weight);
        insertNode(g, weight, x,y);
        insertNode(g, weight, y,x);
    }
    return g;
}


void dijkstra(graphptr g, int s_node){
    int i;                 /* counter */
    edgeptr ptr;         /* temporary pointer */
    bool intree[MAXV+1];   /* is the vertex in the tree yet? */
    int distance[MAXV+1];  /* cost of adding to tree */
    int parent[MAXV+1]  ;
    int v;                 /* current vertex to process */
    int w;                 /* candidate next vertex */
    int newdist;           /* cheapest cost to enlarge tree */
    int weight = 0;        /* tree weight */

    for (i = 0; i < g->vertices; i++) {
        intree[i] = false;
        distance[i] = INFI;
        parent[i] = -1;
    }

    //Eerstes Knot
    distance[s_node] = 0;
    parent[s_node] = s_node;
    v = s_node;
    
    //Knot de Baum traversieren
    while (!intree[v]) {
        intree[v] = true;
        if (v != s_node) {
            printf("edge (%d,%d) in tree \n",parent[v],v);
            weight = weight + newdist;
        }

        // Knot de Baume travvenieren
        ptr = g->edgesof[v];    // Kanten de Knot v
        while (ptr != NULL) {
            w = ptr->vertex  ;  
            if (distance[w] > (distance[v]+ptr->weight))
            {
                distance[w] = distance[v]+ptr->weight;   
                parent[w] = v;                        
            }
            ptr = ptr->next;
        }
        newdist = INFI;
        for (i = 0; i < g->vertices; i++) {
            if ((!intree[i]) && (newdist > distance[i])) {
                newdist = distance[i];
                v = i;
            }
        }
    }
    for(i = 0 ; i < g->vertices ; i++)
    {
        printf("Best Path of %d is : %d costing %d \n",i,parent[i],distance[i]);
    }
}

int main()
{
  graphptr g = initializeGraph();
  printGraph(g);
  dijkstra(g,0) ;
}
