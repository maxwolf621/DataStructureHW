/*  *******************************************************************************
 *  Hw3 1041236157 																  *
 *  source code ref by horowitz chap4 , Modern C approach pointer to pointer	  *
 *  Comments with German
 *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
		if(!(p = malloc(s))){ \
			fprintf(stderr,"Insufficient Memory"); \
			exit(EXIT_FAILURE); \
		}
		
#define COMPARE(x) \
		((x < 0) ? -1 : 1)

		
typedef struct polyNode *polyPtr;
struct polyNode{
	int coef, expon;
	polyPtr link;
};



void printList(polyPtr firstNode);
polyPtr createNode(int coef, int expon);
void attach(int coef,int expon, polyPtr *firstNode);
void sort(polyPtr *firstNode);
void polyMul(polyPtr a,polyPtr b,polyPtr *c);

int main(void)
{
	polyPtr a = NULL, b = NULL, c = NULL; 
    puts("c(x) = a(x) * b(x)");
    attach( 3, 2, &a); 
    attach( 3, 1, &a); 
    attach( 1, 0, &a); 

    attach( 2, 2, &b); 
    attach( 1, 1, &b); 
    attach( 2, 0, &b);
  
	printf("Polynomial a : ");
	printList(a);
    printf("Polynomial b : ");
    printList(b);
    polyMul(a,b,&c);  
    printf("Polynomial c : ");
    printList(c); 
    return 0; 
}
void printList(polyPtr firstNode)
{
	for( ; firstNode ; firstNode = firstNode->link)
	{
		switch(COMPARE(firstNode->coef))
		{ // wir ueberpruefen dass,ob der Koeffizient des Knotens postiven oder negativen Integer ist 
			case -1:
				printf("%dx^(%d)",firstNode->coef,firstNode->expon);
				break;
			case 1 :	
				printf("+%dx^(%d)",firstNode->coef,firstNode->expon);
				break;
		}
	}
	puts("");
} 


/* Zeiger Auf Zeiger
void attach(int coef, int expon, polyPtr *currPtrC)
{
	polyPtr temp = NULL, ptrCp = NULL;
	MALLOC(temp,sizeof(*temp));
	temp->coef  = coef        ;
	temp->expon = expon       ;
	temp->link  = NULL   	  ;
    ptrCp = *currPtrC		  ;
	ptrCp->link = temp  ;  // schluss mit temp an
	*currPtrC   = temp 		  ;  // ptr zeigt auf temp
}
*/


polyPtr createNode(int coef,int expon)
{
	polyPtr temp;
	MALLOC(temp, sizeof(*temp));
	temp->coef   = coef;
	temp->expon  = expon;
	temp->link   = NULL;
	return temp;
}

void attach(int coef, int expon,polyPtr *firstNode) 
{ 
	polyPtr temp,currPtr;
	temp =  createNode(coef, expon);
	currPtr = *firstNode; 			//*firstNode immer zeigt auf ERSTEM KNOTEN
	if(!*firstNode)
	{
		 *firstNode = temp;
	}
	else
	{
		while(currPtr->link !=NULL) // bis currPtr zeigt auf NULL
		{ 
		  currPtr = currPtr->link; 
		}
	 currPtr->link = temp; 			// Verkettet einen neuen Knoten
	}
}

/*
void sort(polyPtr *firstNode)
{
	// Eine Odernung des Coefs mach
	polyPtr poly, polyNext, del;
	int count ;
	for(poly = *firstNode,count = 0; poly && poly->link ; poly = poly->link)
	{
		printf("%d\n",count++);
		printList(*firstNode);
		polyNext = poly->link;
		while(polyNext != NULL) // naechstes von poly
		{
			printf("-polyNext's expon: %d\n", polyNext->coef); 
			if(poly->expon == polyNext->expon)
			{
				poly->coef = poly->coef + polyNext->coef ;
				printf(" new poly coef %d on poly expon %d \n",poly->coef, poly->expon);				
				// Befrei nutzloser Knoten
				del = polyNext;
				// Zeig auf naechstem Knoten
				polyNext = polyNext->link;
				free(del);  
			}
			else
			{
				//polyNext = polyNext->link;
				printf("polyNext->coef: %d\n",polyNext->coef);
				break;
			}
	    }
	    printf("---\n");
	 }
	printf("END poly: ");
	printList(*firstNode);
}
*/

void sort(polyPtr *firstNode) 
{ 
    polyPtr poly,polyCp, extra; 
    int count = 0; //ueberprufung
    poly = *firstNode; 
	//printList(*firstNode);
    while (poly && poly->link) 
    { 
		count++;
        polyCp = poly; 
        while (polyCp->link != NULL) 
        {
            if (poly->expon == polyCp->link->expon) { 
                // Zusammen zur Rechnung 
                poly->coef += polyCp->link->coef; 
                
                // Befrei nutzloser Knoten
                extra = polyCp->link         ;
                polyCp->link = polyCp->link->link;  
                free(extra)					 ; 
            } 
            else
                polyCp = polyCp->link; 
        } 
        poly = poly->link; 
    }
    //printf("count : %d \n", count);
} 

void polyMul(polyPtr a,polyPtr b, polyPtr *c) 
// Pass Auf a und b sind lokale Variabeln ( gültig nur in dieser Funktion polyMul ) so wir brauchen ein REUTRN VALUE
{ 
    polyPtr b1thNode,currPtrC, temp;
    int coef, expon			    	   ;
    b1thNode = b					   ;
    while (a) 
    { 
        while (b) 
        {  
            coef   = a->coef  * b->coef; 
            expon  = a->expon + b->expon; 
			if(coef) attach(coef, expon, &currPtrC);  
			//printList(currPtrC);
            b = b->link;  	// bx^(k-1) 
        } 
			b = b1thNode ; 	// reset 
        a = a->link  ;		//   
    }
    
    // sort reuslt's polynomial and delete extra node 
    sort(&currPtrC); 
    *c = currPtrC; 
   	//printList(currPtrC);
}
