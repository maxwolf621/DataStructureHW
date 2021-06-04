#include <stdio.h>
#include <stdlib.h> 

#define MAX 20
#define MemCheck(G)\
		if(!G){ \
			printf(stderr,"Insufficient Memory");\
			exit(EXIT_FAILURE);\
		}

#define MALLOC(p,s) \
		if(!(p = malloc(s))){ \
			fprintf(stderr,"Insufficient Memory"); \
			exit(EXIT_FAILURE); \
		}
		
/***************************************************************************
* {0,2,4,7,11} // 5-1 edges , {1,3,5} // 3-1 edges , {6,8,9,10} //4-1 edges*
****************************************************************************/

// Problem Ein
int visited[MAX] = {0} ;

typedef struct Graph *Graphptr;
struct Graph{
	int Vertrex, Edges;  
	// doppelte Zeiger
	int **adjmat;
};

Graphptr BuildAdjMat(){
	int e /* Edge */ , x, y /* Reihe und Kol */ ;
	Graphptr G; 
	MALLOC(G,sizeof(*G)); 
	//G = (Graphptr)malloc(sizeof(struct Graph));
	
	//struct Graph *G;
	//G = (struct Graph*)malloc(sizeof(struct Graph));
	printf("Num of Vertrex:");
	scanf("%d",&G->Vertrex);
	printf("Numb of Edges :");
	scanf("%d",&G->Edges);
	
	G->adjmat=(int**) malloc(sizeof(int*) * G->Vertrex);
    for (int i = 0; i < G->Vertrex; ++i)
		G->adjmat[i] = (int*) malloc (sizeof(int) * G->Vertrex);

	//eroeffnen
	for( x = 0 ; x < G->Vertrex ; x++)
			G->adjmat[x][x] = 0;
	for( e = 0 ; e < G->Edges ; e++){
		printf("Enter Row: ");
		scanf("%d", &x);
		printf("Enter Col: ");
		scanf("%d", &y);
		
		printf("Processing Graph[%d][%d] and Grapg[%d][%d] \n", x, y, y,x);
		G->adjmat[x][y] = 1;
		G->adjmat[y][x] = 1;
	}
	return G;
}

void Dfs(Graphptr G, int x /*Reihe von adjMat*/){
	visited[x] = 1;
	printf("%d ", x);
	int y /*kol*/ ; 
	for(y = 0 ; y < G->Vertrex ; y++)
		if(!visited[y] && G->adjmat[x][y]) Dfs(G,y);
}
void Comps(Graphptr G){
	int v;
	int count = 0;
	// schritt zu schritt
	for(v = 0 ; v< G->Vertrex ; v++) 
		if(!visited[v]) 
		{
			Dfs(G,v);
			printf(" --> Component No%d \n", ++count); 
		}
}

int main()
{
	// Ein Graphen mit Adjazenzmatrix zur Abbildung mach
	Comps(BuildAdjMat());
	return 0;
}

