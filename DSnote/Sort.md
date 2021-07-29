###### tags: `Data Structure`
# Sort
[TOC]

- [Linked List](/RqSYYsdsTECNUEosiA3Qkw)

## Stable and Unstable(Stabilität und instabilen)
Es gibt gleiche Schlüssel in einer Datensätz  
Input : 5,4,2,6,`4`,7,1  

> Abhaengig von dem Reihenfolgenummer (4 und `4`)   
> 4 is a head of `4`  

- Stabilität    : 1,2,**4**,`4`,5,6,7   
- Instabilität  : 1,2,`4`,**4**,5,6,7 (`4` is a head of **4**)   


## Insert Sort
[Reference](http://alrightchiu.github.io/SecondRound/comparison-sort-insertion-sortcha-ru-pai-xu-fa.html)  
```diff
- Best Case : O(1) , only compare one time , elements in container are increasing

- Worst Case : O(n), elements in container are decreasing   
```
- **當問題的資料量較小時(欲排序的元素之數目較小)，使用Insertion Sort會很有效率**
  > 因為和Quick Sort、Merge Sort、Heap Sort相比，Insertion Sort不具有「遞迴」形式，因此不需要系統的stack，詳情請參考：

- 有些演算法會在Quick Sort中加入Insertion Sort，讓剩下的「接近完成排序」的資料以Insertion Sort處理，使排序更有效率


```diff
! Insertion Sort要求，在處理A[i]時，第A[1,i-1]必須先排好序
```
![image](https://user-images.githubusercontent.com/68631186/127458715-f2608f45-2d39-4918-9ca8-93aca24172c0.png)

```cpp
#include <iostream>
/**
  * @param size : array.size()
  * @param *arr : array to be sorted
  */
void InsertionSort(int *arr, int size){
    for (int i = 1; i < size; i++) {       
        /**
          * key : A unsorted element to be compared with sorted elements
          * j   : sorted section
          */
        int key = arr[i];
        int j = i - 1;
        /**
          * compare {@code key} with {@code arr[j]} 
          *        {a, b, c, d, c}
          *  arr[j]-'  '-- key 
          */
        while (key < arr[j] && j >= 0) {
            /**
              * SHIFT arr[j] backward 
              */
            arr[j+1] = arr[j];
            j--;
        }
        /**
          * put key to the right position
          */
        arr[j+1] = key;
    }
}
```

![](https://i.imgur.com/ukbZnWr.png)


## Select Sort


```diff
arr: 
     {9, 17, 1, 5, 10}
min,i-'   '- j
     {9, 17, 1, 5, 10}
min,i-'      '-j
     {9, 17, 1, 5, 10}
    i-'      '-j, min
!    /** SWAP(9,1) **/ 
     {1, 17, 9, 5, 10}
    i,min-'  '-j 
     {1, 17, 9, 5, 10}
       i-'   '-j,min
     {1, 17, 9, 5, 10}
       i-'      '-j,min
     {1, 17, 9, 5, 10}
       i-'  min-'   '-j
!    /** SWAP(17,5) **/
     {1, 5, 9, 17, 10}
     {1, 5, 9, 17, 10}
             i-'
     {1, 5, 9, 10, 17}
```

```java
/**
  * {@code i} : current ptr
  * {@code j} : next_ptr of current ptr
  * {@code min} : element that will be compared with j
  */
void sort(int arr[])
    {
        int n = arr.length;
 
        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            int min = i;
            for (int j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min = j;
 
            // Swap the found minimum element with the first
            // element
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
```

## Quick Sort
![](https://i.imgur.com/kyMz7e1.png)
- Divide and Conquer  
  > `pivot`可以任意挑選
  > **Divided的Array**則是只是重複相同的步驟(選pivot -> 調整(divide)Array)，利用遞迴(recursion)處理     
- Unstable

```diff
+ Best Case : O(nlogn)
+ Average Case : O(nlogn)
```

> ![image](https://user-images.githubusercontent.com/68631186/127516920-c469e3c6-d578-4f49-8f66-7af187552e4b.png)
> ```diff
> - Worst Case : pivot is MAX or MIN => Tree is Skewed O(n<sup>2</sup>) 
> ```

### Method 1
![image](https://user-images.githubusercontent.com/68631186/127509355-5415f995-792c-4b22-8d73-49c9c8af5755.png)
![image](https://user-images.githubusercontent.com/68631186/127509387-a7f248c7-a97c-400f-b281-7843bcde2ffa.png)
> ![image](https://user-images.githubusercontent.com/68631186/127509433-dc6ecbb7-26db-47cd-838d-ec94c15b12c7.png)
```diff
+ a[j] : 9 > pivot : 5
+ move next element : j++
```
> ![image](https://user-images.githubusercontent.com/68631186/127509447-93f1abd4-3e6c-4e11-b159-3f312e6cf888.png)
```diff
+ a[j] ; 4 < pivot : 5
+ do i++ (pointer to element a[1] : 9 )
+ swap(a[i], a[j]) 
+ j points tp next element : j++
```
![image](https://user-images.githubusercontent.com/68631186/127509465-e3a6c550-986c-4a0c-8d7f-62186d268a5b.png)
![image](https://user-images.githubusercontent.com/68631186/127509490-b40225e7-100d-486c-b599-2d4ee70471a7.png)
![image](https://user-images.githubusercontent.com/68631186/127509508-ba0942f7-2aeb-4b09-a3c9-d3d67cd24aa0.png)
![image](https://user-images.githubusercontent.com/68631186/127514183-254f63ea-8c1d-41e8-8e30-1507aaf51994.png)
![image](https://user-images.githubusercontent.com/68631186/127514471-17ffaf5a-9c50-4517-81c5-9ab39a19e9de.png)
![image](https://user-images.githubusercontent.com/68631186/127514503-a5267db6-3cea-409f-81c6-a8d8dbe555d8.png)
> ![image](https://user-images.githubusercontent.com/68631186/127514517-770e88c5-5f5e-4c09-83f4-a0c9ae3d78a0.png)
```diff
- do parition
```
![image](https://user-images.githubusercontent.com/68631186/127514778-dafaefa2-b93b-4510-8f19-8670f7c9536b.png)
> ![image](https://user-images.githubusercontent.com/68631186/127514793-215bc468-93e2-4068-8bcb-b8fa174e5b05.png)
```diff
- (multiprocessor) we can hadle both left and right array at same time via mutiple cpu 
```


```cpp
/**
  * {@code Partition}
  * {@code QuickSort}
  */
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}

void QuickSort(int *arr, int front, int end){
    if (front < end) {
        /**
          * {@code pivot} would be 5
          */
        int pivot = Partition(arr, front, end);
        /**
          * do <strong> divide and conquer </strong>
          */
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
```

### Method 2 (Howitz)


![](https://i.imgur.com/8U7cpg7.png)
![](https://i.imgur.com/aoSsEsK.png)
![](https://i.imgur.com/NHbZ6wN.png)


## Merge Sort
[Reference](http://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html)
![](https://i.imgur.com/1uz4cw8.png) 

- `Merge()`
    ---
![](https://i.imgur.com/X9z6JNj.png)

![](https://i.imgur.com/dnIWKwl.png)

```c
// do Sorting and Merge 
void Merge(int List[], int mergeList[], int start, int mid, int end)
{
    // to merge sorted List[start:mid] with List[mid+1:end] into mergeList[]
    int leftsubindex = start     /* for int start   */;
    int index  = start;       /* for mergeList's index*/;
    int rightsubindex= mid + 1   /* for rightsubindex of List  */;
    int rest                      /* rest elements in List[] */;
    while(leftsub <= end && rightsub <= end )
    {
        if(List[leftsubindex] <= List[rightsubindex]) 
            mergeList[index++] = Leist[leftsubindex];
        else
            mergeList[index++] = List[rightsubindex];
    }
    if ( leftsubindex > mid)
        for(rest = rightsubindex ; rest <= end ; rest++) 
            mergeList[index++] = List[rest];
    else
        for(rest = leftsubindex ; rest <= mid ; rest++)
        mergeList[inde++] = List[lefsubindex]
}
```


- function MergePass()
    ----
- Was funktioniert MergPass()
![](https://i.imgur.com/5ZYzrLu.png)

```c=
// Pairing 
void mergePass(element List[], element mergeList[], int lenList, int lenSec)
// lenSec : the size of each SORTED segment ex: to stort {1,2} => s = 2
// lenList :  len of list[]
// Merge its adjacent pairs of sorted segments from List[] to mergeList[]

int current ;    /* start from List[current] */
int rest    ;    /* rest elements  */
int midList = lenList - 2*lenSec + 1 ;    /* middle of List[] */
                    
// one Pass pair two Section (Each Section has length of 2 )
// Iterative Pass i= 1        :  {5,26} {1,77}   
// Iterative Pass i = 1 + 2*2 :  {11,61} {14,59}
for(current=1; current<= midList; current+=2*lenSec)  
    /**********************************************************
     * Assume lenSec = 2 
     * {x1,x2} {x3,x4}  
     * ---- position of x4 would be 2*len - 1
     * -----position of mid in {x1,x2,x3,x4} would be  i + len
     * -----Think : warum (lenSec) -1 muss
     **********************************************************/
    int mid = current + lenSec   -1;
    int end = current + 2*lenSec -1;
    Merge(List,mergeList, i, mid, end);
if (current+lenSec-1 < n) 
    // there are no others can pair 
    // as {19,48}
    merge(List,mergeList,current,current+lenSec,lenList);
else// rest elements
    for(rest = current ; rest <= lenList ; rest++ )
        mergeList[rest] = List[rest] ;
```
- mergeSort()
  ---
- wie functioniert mergeSort
![](https://i.imgur.com/mtFP5JT.png)

```c=
void mergeSort(element List, int lenList)
// Iterative
{
    element mergeList[MaxSize];
    int lenSec = 1            ; // iterative 1 , 2 , 4 , 8 
    for( lenSec ; lenSec < lenList ; lenSec*=2 )
    {
        mergePass(List, mergeList,lenList,lenSec);
        lenSec *=2 ;
        mergePass(mergeList, List , lenList,lenSec);
    }
}
```

## Radix Sort

- 分成
    - Most Significant Digit First Sorting
    - Least Significant Digit First Sorting 


### Decker Sort 
K<sup>1</sup> : :clubs: < :diamonds: < :hearts: < :spades:
K<sup>2</sup> : 2 < 3 < 4 < 5 < 6 <7 < 8 < 9 < 10 < J < Q < K < A 

- Sorting Using Bin Sorting
    ---
    1.sort K<sup>1</sup>分成四桶（四花色）
    2.sort L<sup>2</sup> after

```c
// a[] : input dataset from range a[1: end]
// end : index of array
// d : how many digit  ex  123 => 3 digits
// r : num of buckets
int radixSort(element a[],int link[], int d, int r, int end)
int front[r],rear[r]; 

// current : index of current
// i : for loop
int i,bin,current,first,last
first = 1 ;
for(i = 1 ; i<n ; i++) link[i] = i + 1; 
link[n] = 0

//
for(i=d-1 ; i >= ; i++){
    for(bin = 0; bin < r ; bin++) front[bin] = 0;
    for(current = first ; current=link[current]){
        
        // sort the digit 
        bin = digit(a[current],i,r)
        if(front[bin]=0) front[bin] = current;
        else link[rear[bin]] = current       ;
        rear[bin] = current
    }
    for(bin = 0 ; !front[bin] ; bin++);
    first = front[bin] ; 
    last = rear[bin];
    for(bin++ ; bin<r ; bin++){
        if(front[bin]){
            link[last] =front[bin]
            last = rear[bin]
        }
    }
}
```
### LSD
- Time Complexity : O(d*(n+r))
    - d :loop
    - n : distribute
    - r : merge
- Bucket : r
![](https://i.imgur.com/5CWWf06.png)
### MSD

![](https://i.imgur.com/NggldOe.png)
![](https://i.imgur.com/iNubQ14.png)


## Heap

![](https://i.imgur.com/wXoWj2r.png)

- It's A Complete B.T. 
- Every Node has its own sequence.

The number above a node is the corresponding index in the array. Above and below the array are lines showing parent-child relationships; 
parents are always to the left of their children. 
The tree has height three; 
the node at index 4 (with value 8) has height one.


```
Following the Complete Tree rule
- Parent(i)
return [i/2]
- LeftNode(i)
return [2i]
- RightNode(i)
return [2i+1]
```

There are two kinds of binary heap.
In both Kinds,the values in the nodes statisfy a `heap property`
1. max-Heaps (maxNode is at Root) : ${A[parent]\ge A[i]}$ 
2. min-heaps (minNode is at Root) : ${A[parent]\le A[i]}$

![](https://i.imgur.com/d1d6JDS.png)


### Maintaining the heap Property

- Function MAX_HEAPIFY 
    It's inputs are an Array A and an index i (parent node) into the array.

```c
MAX_HEAPIFY(A,parent)
{
// lets the value at A[parent] **float down** in the max-heap so that the subtree rooted at index i obeys the max-heap property

    l = LEFT(parent); // left child of node i
    r = RIGHT(parent); // right child of node i 
    
   /************************************
    *COMPARE WITH LEFT CHILD of I FIRST* 
    ************************************/
    if(l <= A.length && A[l] > A[parent]) // compare left child
        largest = l                   ; 
    else largest = i                  ;   
    if(r <= A.length && A[r] > A[parent]) // compare right child
        larget = r                    ;
    if largest != i                   ;
        swap(A[parent],A[largest])    ;
        MAX_HEAPIFY(A,largest)        ;   // keep comparing child's child
    
}
```

![](https://i.imgur.com/A5EzqpX.png)


- Building a heap
  ---
Using MAX_HEAPIFY() in a bottom-up manner to convert an Array A[1...n], where n = A.length, into a max heap

The Elements in the subarray A[([n/2]+1)...n] are all leves of the tree

```python=
def BUILD_MAX_HEAP(A)
    heapsize = A.length
    for i = [A.length/2] downto 1
        MAX_HEAPIFY(A,i) #Compare each parent of a node (bottom-up)
```


![](https://i.imgur.com/o5pmSAj.png)


- HeapSort
   ----
    1. swap the root (coz it's max) with last node (coz it's min)
2. decrementing Array length 
3. find Max heap(by function of MAX_HEAPIFY) in the decreamented Array

```python=
def heapSort(Array A)
    for i = A.length downto 2
        swap A[1] with A[i] #swap the last node with Root
        A.heapSize = A.heapSize - 1 
        MAX_HEAPIFY(A,1) # kepp the property of maxHeap
```

![](https://i.imgur.com/WEVgdTH.png)
### Insertion
![](https://i.imgur.com/UMZwaXM.png)
```c=
#define maxElement 100;
#define heapFull(n) (n == maxElement-1)
#define heapEmpty(n) (!n)

typedef struct{
    int key
}element
elment heap[maxElement];
int n = 0;

// add the new item at position [last node + 1]
void push(element item, int *n /* pointer to &A[n] */)
{
    // insert item into a max heap of current size *n
    int i;
    if(heapFull(*n)) /* Check the Array*/{
        fprintf(stderr,"The heap is full. \n");
        exsit(EXIT_FAILURE);;
    }
    
    i = ++(*n); // Size of the Array will be Array[n+1]
    
    // keep property of maxHeap (compare with it's parent)
    while( i !=1 && item.key > heap[i/2].key )
    {   // child is larger than parent then swap each other
        
        heap[i] = heap[i/2] // swap 
        
        // bottom-up comparing
        // move next parent node (from i/2 down to 2)
        i /= 2 ; 
    }
    // insert the appropriate position i for the item
    heap[i] = item;
}
```

### Deletion(the Root)

```c=
element pop(int *n /* &Array[n]*/)
{
    int parent, child ; // index of Array 
    element item, temp;
    

    // cheking if array is empty
    if(heapEmpty(*n)){
        fprintf(stderr,"The heap is Empty. \n");
        exsit(EXIT_FAILURE);;
    }
    
    // pop the Max Value from heap[n]
    item = heap[1];
    // use last element in heap to adjust heap
    temp = heap[(*n)--]; 
    
    // Default Comparing Root with its leftChild
    parent = 1;
    child  = 2; 
    
    // Staring Comparing using ``Top Down`` 
    while(child <= *n){
        // find the larger child ( if right > left ) of the current parent
        if(child < *n && heap[child].key < heap[child+1].key)
            child++; //rightChild > leftChild
        
        
        // temp.key is at Root and compare with it's child
        // if parent is >= than it's child then break
        // coz it follows the Property of MaxHeap
        if(temp.key >= heap[child].key) break;
        
       
        //If parent is < than it's child then
        //swap heap[i/2] with heap[2n] or heap[2n+1] 
        heap[parent] = heap[child]; 
        
        // current child may has its own child 
        parent = child; 
        
        // leftChild heap[2*child] RightChild heap[2*child+1]
        child *= 2; 
    }
    heap[parent] = temp; // place the last node at proper position
    return item        ; // pop out the Root
}
```

## Stable and Unstable 
![](https://i.imgur.com/aHsF0wP.png)

![](https://i.imgur.com/rPTfors.png)


![](https://i.imgur.com/Xog9EKw.png)
