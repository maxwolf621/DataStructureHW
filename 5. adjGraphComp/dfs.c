#include <stdio.h>
#define vertrex 12

/**************************************
* {0,2,4,7,11} , {1,3,5} , {6,8,9,10} *
**************************************/

int adj[vertrex][vertrex] = {
	/* 0  1  2  3  4  5  6  7  8  9 10 11 */ 
/*0*/     {0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
/*1*/     {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
/*2*/     {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
/*3*/     {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
/*4*/     {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
/*5*/     {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
/*6*/     {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
/*7*/     {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
/*8*/     {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0 },
/*9*/     {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0 },
/*10*/    {0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0 },
/*11*/    {1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
};

// weg aufnehmen
int visiteddfs[vertrex] = {0} ; 
int visitedbfs[vertrex] = {0} ;

void dfs(int adjMat[][vertrex],int x)
{
	//col
	int y; 
	// gebesucht hat
	visiteddfs[x] = 1;
	printf("%d-", x);
	for(y = 0 ; y < vertrex ; y++){
		if(!visiteddfs[y] && adjMat[x][y])
			dfs(adjMat,y);
	}
}


/*
void bfs(int adjMat[][vertrex], int v)
{
    int rear = -1, front = -1;
    int y ;
    int queue[vertrex];
    //enqueue 
    queue[++rear] = v ;
    while(rear != front)
    {
	int x;
	x = queue[++front]; // dequeue
	visitedbfs[x] = 1 ; 
	printf("%d-", x);
	for( y = 0 ; y < vertrex ; y++)
	    if(!visitedbfs[y] && adjMat[v][y])
		queue[++rear] = y   ;
    }

}
*/


void Componentdfs(int adjMat[][vertrex])
{
	// vertrex
	int v; 
	int count = 0 ;
	// ab vertrext 0 besuchen 
	for( v = 0 ; v < vertrex ; v++)
	{
		if(!visiteddfs[v])
		{
		    dfs(adjMat,v);
		    
		    printf("-> Component No.%d", ++count);
		    puts("\n");
		}
	}
}


/*
void Componentbfs(int adjMat[][vertrex])
{
	// vertrex
	int v; 
	
	// ab vertrext 0 besuchen 
	for( v = 0 ; v < vertrex ; v++)
	{
		if(!visitedbfs[v])
		{
		    bfs(adjMat,v);
		    puts("\n");
		}
	}
}
*/

int main()
{
	Componentdfs(adj);
	//Componentbfs(adj);
	return 0;
}
