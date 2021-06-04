/* 1041236157 knight tour with stack ref Datastructure in C by Horowitz */
#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 64
#define maxRow 8
#define maxCol 8

/* stack */
typedef struct {
    short int row, col, dir;
} element;

/* the direction which you can move */
typedef struct {
    short int vert, horiz;
} offsets;

/* global */
int mark[maxRow][maxCol]={0};
int top = -1;
int full = 0;
int count = 1;
int endpoint =0;
int maze[maxRow][maxCol]={0}; 		
element stack[MAXSTACK];
offsets move[8] = {{1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-2,-1},{-1,-2}};


/* prototype */
void push(element item);
element pop(void);
void path(int startRow, int startCol, int exitRow, int exitCol);
void print(int arr[maxRow][maxCol]);

int main(void)
{
    /* Set the entrance and exit 	  */
    /* Eingang und Ausgang einsetzen      */ 
    int startRow=0, startCol=0, exitRow=7, exitCol=2;
    
    /* Druck die Landkarte aus */
    /* Print The maze          */
    print(maze);
    path(startRow, startCol, exitRow, exitCol);
    return 0;
}

void print(int arr[maxRow][maxCol]){
    puts("-----------------------------------------------------------------");
    for(int row =0 ;row < maxRow ;row++) {
	for(int col = 0 ;col < maxCol ;col++) {
            printf("%d\t",arr[row][col]);
	}
        puts("\n");
     }
}

void push(element item){
    if (top >= MAXSTACK) {
        puts("pathStack is full\n");
	full = 1;
    }
    else {
        stack[++top] = item;
    }
}
element pop(void){
    if (top > -1 ) {
	/* take out the position */
        return stack[top--];
    }
    else {
        puts("pathStack is empyt\n");
    }
}

void path(int startRow, int startCol, int exitRow, int exitCol){
    /***********************************
     * row, col : current position     *
     * dir : direction you will move   *
     * found : do ya find the exit ?   *
     **********************************/
    int row, col, nextRow, nextCol, dir, found = 0;
    /* stack */
    element position;
    top = 0;
    mark[startRow][startCol] = 1;
    /* push the current position into stack[] for marking down */
    stack[0].row = startRow;
    stack[0].col = startCol;
    stack[0].dir = 0; 

    while (top > -1 && !found) {
	/* pop out the position (record at the stack[]) where you are now */
        position = pop();       
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !full) {
	    /****************************************************************************************************
            *  try 8 different directions where you stand for searching the path.                               *
            *  This gives you 3 results								                *
	    *	1. find the way out.									        *
            *   2. find the path which you can pass by specific dir and never been before			*
            *   3. the direction among 8 which it's not working so you change the other dir to find the way out *
	    *****************************************************************************************************/
	    nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if (nextRow == exitRow && nextCol == exitCol){
    		/**********************
                 *1. Find the way out *
		 *********************/
                found = 1;
		mark[nextRow][nextCol] = 945;
		print(mark);
		printf("Find maze[%d][%d]\n",exitRow,exitCol);
		break;
            }
            else if ( nextRow >=0 && nextCol >=0 && nextRow < 8 && nextCol < 8 && !mark[nextRow][nextCol] ){
		/**************************************************************
                * the position of coordinate (nextRow,nextCol) can be pass    *
		* and ya haven't been (nextRow,nextCol) before                *
                * die Lage der Koordinate (nextRow,nextCol) durchgehen könnte *
                * und du bist nicht da durchgegangen                          *
	        ***************************************************************/
                /* push last one position into the position */
                position.row = row;
                position.col = col;
                position.dir = ++dir;  /*to move the next (x,y) */
		push(position);
		mark[nextRow][nextCol] = 1;
		row = nextRow;
		col = nextCol;
		dir = 0;
            }
	    /**********************************************************************
	    * one of 8 directions is not working so find the other one             *
            * eine der Richtungs läuft nicht , ein anderes zwischen 8 herausfinden *
            ***********************************************************************/
            else ++dir;
        }
    }
    if(!found)
        printf("Knigt cant walk to maze[%d][%d]\n", exitRow, exitCol);
}
