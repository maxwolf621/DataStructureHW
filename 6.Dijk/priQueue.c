#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define INFI 9999
#define NEG  -1
#define Vs   6       /*8*/
/* Priority Queue */

typedef struct node *nodeptr;
struct node
{
	int data;
	int priority;
	struct node *next;
};
nodeptr nodeList = NULL;

void Enqueue(nodeptr* nodeList, int NewQueVal, int NewQuePri)
{
    //printf("Enqueue Check \n");
	nodeptr NewQue, curPtr ;
	//initiallize
	NewQue = (nodeptr)malloc(sizeof(nodeptr));
	//printf("\n enter the value and its priority : ");
	//scanf(" %d %d", &val, &pri);
	NewQue->data     = NewQueVal;
	NewQue->priority = NewQuePri;

    // Vergleich curptr mit curptr
	if(!(*nodeList) || NewQuePri <= (*nodeList)->priority)
	{		
		NewQue->next = (*nodeList) ;
        (*nodeList)     = NewQue  ;
	}
    // vergleich newQue mit curptr->next
    else 
	{
		curPtr = (*nodeList)           ;
		while( curPtr->next != NULL && NewQuePri > curPtr->next->priority)
			curPtr = curPtr->next	;
		NewQue->next = curPtr->next;
		curPtr->next = NewQue	    ;
	}
	//return nodeList;
}
int Dequeue(nodeptr* node)
{
	nodeptr temp;
    int vertex  ;
    temp = *node ;
	if(!temp)
	{
		puts("UNDERFLOW \n");
        *node = NULL;	
        return -1 ;
	}
	else
	{
		temp = (*node);
        (*node) = (*node)->next  ;
		vertex = temp->data;
		free(temp);
	}
    return vertex;
}

bool isEmpty(nodeptr nodeList)
{
    if(!nodeList)
        return true;
    else 
        return false;
}
void printQueue(nodeptr* node)
{
	nodeptr ptr;
	ptr = *node  ;
	if(!ptr)
		puts("\nQueue is Empty");
	else
	{
		puts("\n Priority Queue is : ");
		while(ptr)
		{
            printf("data = %d |  pritority = %d ", ptr->data, ptr->priority);
            if(ptr->next) printf("->");
			ptr = ptr->next;
		}
	}
}

/* AdjMatrix Graph */

typedef struct Graph *Graphptr;
struct Graph{
	int Vertices; 
    //int Edges;
    //bool direct ;
	// doppelte Zeiger
	//int **adjmat;
	//int **weight  ;
    int weight[Vs][Vs];
};


Graphptr BuildAdjMat(){
	int e, x, y, weight ;
	Graphptr G;
	//MALLOC(G,sizeof(*G));
	G = (Graphptr)malloc(sizeof(struct Graph));
    G->Vertices = Vs; 


	int cost[6][6]={
     {   0,   50,   10, 1000,   45, 1000},
     {1000,    0,   15, 1000,   10, 1000},
     {  20, 1000,    0,   15, 1000, 1000},
     {1000,   20, 1000,    0,   35, 1000},
     {1000, 1000,   30, 1000,    0, 1000},
     {1000, 1000, 1000,    3, 1000,    0}};


    // von 4 ab
    /*
    int cost[8][8]={
        {   0,   0,   0,   0,  0,   0,   0,   0},
        { 300,   0,   0,   0,  0,   0,   0,   0},
        {1000, 800,   0,   0,  0,   0,   0,   0},
        {   0,   0,1200,   0,  0,   0,   0,   0},
        {   0,   0,   0,1500,  0, 250,   0,   0},
        {   0,   0,   0,1000,  0,   0, 900,1400},
        {   0,   0,   0,   0,  0,   0,   0,1000},
        {1700,   0,   0,   0,  0,   0,   0,   0}
    };
    */

    /*
    // von 0 ab 
    int cost[6][6] ={
        { 0,50,10, 0,45, 0},
        { 0, 0,15, 0,10, 0},
        {20, 0, 0,15, 0, 0},
        { 0,20, 0, 0,35, 3},
        { 0, 0, 0,30, 0, 0},
        { 0, 0, 0, 3, 0, 0}
    };
    */
	/*
    printf("Num of Vertices:");
	scanf("%d",&G->Vertices);
	printf("Numb of Edges :");
	scanf("%d",&G->Edges);
    G->direct = true         ;
	G->adjmat=(int**) malloc(sizeof(int*) * G->Vertices);
    G->weight=(int**) malloc(sizeof(int*) * G->Vertices);
    
    for (int i = 0; i < G->Vertices; ++i)
		G->adjmat[i] = (int*) malloc (sizeof(int) * G->Vertices);
    for (int i = 0; i < G->Vertices; ++i)
        G->weight[i] = (int*) malloc (sizeof(int) * G->Vertices);
	for( x = 0 ; x < G->Vertices ; x++)
        for(y = 0 ; y < G->Vertices ; y++)
            G->adjmat[x][y] = 0;
    */
    for(x = 0 ; x < G->Vertices ; x++)
        for(y = 0; y < G->Vertices ; y++)
            G->weight[x][y] = cost[x][y];
    /*
    for( e = 0 ; e < G->Edges ; e++){
		printf("Enter Row and Col: ");
		scanf("%d %d", &x, &y);
		printf("Enter Cost: ");
		scanf("%d", &weight);
		//printf("Processing Graph[%d][%d] and Grapg[%d][%d] \n", x, y, y,x);
		
        G->adjmat[x][y] = 1;
        G->weight[x][y] = weight;
        if(!(G->direct))
        {
            G->adjmat[y][x] = 1;
            G->weight[y][x] = weight; 
	    }
    }
    */
    

    for(x = 0 ; x < G->Vertices ; x++)
        printf("%6d", x);
    printf("\n");
    for(x = 0 ; x  < G-> Vertices ; x++)
    {   
        printf("%1d ", x);
        for(y = 0 ; y < G->Vertices ; y++)
         {
           //printf("Weight[%d][%d] = %d \n",x,y,G->weight[x][y]);
           printf("%5d ", G->weight[x][y]);
	     }
        printf("\n");
    }
    puts("");
    return G;
}

void Dijkstra(Graphptr G,nodeptr *List, int s_node /*start node*/)
{
    int dist[Vs]   ;
    int newdist    ;
    int path[Vs]   ;
    bool intrees[Vs];
    int vx ; // vertex 
	//nodeList = 
    Enqueue(&nodeList,s_node,1);
    int i;
    for(i = 0; i< G->Vertices ; i++)
		dist[i] = INFI;
    for(i = 0; i< G->Vertices ; i++)
        path[i] = -1    ;
    
    dist[s_node] = 0;
    path[s_node] = s_node;
    int v; 
    v = s_node;
    while((!intrees[v])){
        vx  = Dequeue(&nodeList);
        intrees[vx] = true      ;
        printf("Dequeue %d \n", vx);
        int vy ;
        int enV;
        newdist = INFI ;


        for ( vy = 0 ; vy < G->Vertices ; vy++){
            if(G->weight[vx][vy] != 0) {   
                printf("to node %d weight %d \t",vy ,G->weight[vx][vy]);
                if(dist[vy] > dist[vx]+ G->weight[vx][vy])
                {
                    dist[vy] = dist[vx] + G->weight[vx][vy];
                    path[vy] = vx  ;
                }

                 /* wenn dist[] is -1 oder newdist ist grosser als die
                     es laeuft dist[]-update  */
                /*
                if(dist[vy] == -1)
                {
                 //puts("do 1");
                 dist[vy] = newdist[vy];
                 Enqueue(&nodeList,vy,1);
                 printf("enqeue %d \n", vy);
                 // jetzt es wird am Besten von wegX zu wegY sei
                 path[vy] = vx;
                }
                */
                /*
                if(dist[vy] > newdist[vy])
                {
                  //puts("do 2");
                  dist[vy] = newdist[vy];
                  Enqueue(&nodeList,vy,1);
                  path[vy] = vx;
                }
                */

                // Wahl naechstes Knot aus ( Am Kleinsten )
                if(newdist > dist[vy] && (!intrees[vy]))
                {
                    newdist = dist[vy]  ;
                    v = vy  ;
                }
            }
        
        }
        if( v != vx ) printf("\nProcessing Next Node : %d \n", v);
        else printf("Trversal Complete \n"); 
        Enqueue(&nodeList,v,1);
    }
    // bestPath schritt zu schrittz ausdurcken
    for(i = 0 ; i < G->Vertices ; i++) printf("dist[%d] : %5d |  Pathto[%d] : %5d \n",i, dist[i], i ,path[i]);
}
int main()
{
    // bau matrix ab
    Graphptr G = BuildAdjMat() ;
    // Dijkstra traversierung von node 0 ab mach 
    Dijkstra(G,&nodeList,0); 
}

