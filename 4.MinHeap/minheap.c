// 1041236157 , Bezug auf "Algorithm" 
#include <stdio.h>
// Macro fuer Groesse von array, Rechtes Kind, Linkes Kind
#define LENGTH(n)  (sizeof(n) / sizeof(n[0]))
#define RIGHT(r) (2*r+1)
#define LEFT(r)	(2*r)

/*
	DIE LAGE DER WURZEL : ab A[1] NICHT ab A[0]
	EHREN : LEN / 2
	KINDER : LEN/ 2 + 1 , LEN
*/

void printarr(int arr[], int len)
{
	for( int i = 1 ; i < len ; i++)
		printf("%d | ",arr[i]);
	puts("\n");
}

void delen(int *p)
{
	*p -= 1 ;
}

// Austauschen
void Swap(int *x, int *y)
{
	int temp  ;
	temp = *x ;
	*x = *y   ;
	*y =  temp;
}

// Einschaft von minHeap instand halten
void MinHeapify(int arr[],int parent)
{
	int min ;
	// wir muss es ueberpruefen dass l oder r ist ungültige Grenze
	int l = LEFT(parent);
	int r = RIGHT(parent);
	// wer ist am Kleinsten l, parent , r ?
	if(l < arr[0] && arr[l] < arr[parent] && arr[l] < arr[r])
		min = l;
	else if(r < arr[0] && arr[r] < arr[parent])
		min = r;
	else 
		min = parent;
			
	// wenn parent nicht an dem kleinsten ist, eine Vorgang des Austausches mach ! 
	if(min != parent){	
		//tausch element um
		Swap(&arr[parent],&arr[min]);
		// die Eigenschaft von MinHeap instand hlaten
		MinHeapify(arr,min);
	}
}

// Anbauen
void BuildHeap(int arr[], int len)
{
	for(int i = arr[0]/2 ; i >= 1 ; i--)
	{
		MinHeapify(arr,i);
	}
	puts("Build A Heap");
	printarr(arr, len);
	puts("\n");
}

// Sortieren
void HeapSort(int arr[], int len)
{
	for(int node = arr[0] - 1 ; node >= 2  ; node--){
		//letztes Knot und die Wurzel umtauchen
		printf("arr[1] %d and arr[node] %d \n", arr[1], arr[node]);
		Swap(&arr[1],&arr[node]);
		delen(&arr[0])          ;
		MinHeapify(arr,1)  		;
		printarr(arr,len)		;
	}
}

int main()
{
	int arr[] = {0,4,1,3,2,16,9,10,14,8,7};
	int arrlen = LENGTH(arr)	;
	arr[0] = arrlen		    	; // speicher arrlen in die Array[0]
	BuildHeap(arr,arrlen)		;
	HeapSort(arr,arrlen)		;
	printarr(arr,arrlen)	    ;
	return 0 ;
}
