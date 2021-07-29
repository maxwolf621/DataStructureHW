###### tags: `Data Structure`
# Sort
[TOC]



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

### Merge (No Recursion)
![](https://i.imgur.com/1uz4cw8.png) 
1. Consider that each element in array as an array that contains only one element `{26},{5},{77},{1},{61},{11},...` for first iteration 
2. Merge each array that contains only one element like this 
   > ![](https://i.imgur.com/dnIWKwl.png)
3. each iteration for each sub-array can be called a run
   > merge `{26}` with `{5}` we can say Merge two runs `{26}` and `{5}` into one new run `{5,26}`


```c
/**
 *  Sort Run and Merge Runs into One new Sorted Run
 */
void Merge(int List[], int mergeList[], int start, int mid, int end)
{
    /**
     *  1. (SORT) Compare List[start:mid] (sub-arrLeft) 
     *     with List[mid+1:end] (sub-arrRight) 
     *  2. Merge the right element fetching 
     *     from sub-arrLeft or sub-arrRight  
     *     in into mergeList[]
     */
    int index  = start;  
    
    int leftsubindex = start;     
    int rightsubindex= mid + 1 ;
    
    int rest /* rest elements in sub-array */;
    
    while(leftsubindex <= end && rightsubindex <= end )
    {
        /**
         * Compate Left sub-array with Right sub-array
         * put the small one into mergList 
         */
        if(List[leftsubindex] <= List[rightsubindex]) 
            mergeList[index++] = List[leftsubindex];
        else
            mergeList[index++] = List[rightsubindex];
    }
    
    // Rests 
    if ( leftsubindex > mid) 
        for(rest = rightsubindex ; rest <= end ; rest++) 
            mergeList[index++] = List[rest];
    else
        for(rest = leftsubindex ; rest <= mid ; rest++)
            mergeList[inde++] = List[lefsubindex];
}
```


#### Merge Each Pass 
> Wie funktioniert MergPass()  
> ![](https://i.imgur.com/5ZYzrLu.png)  

**Pass** means iterate the runs 
- For each pass it will do multiple time `merge` method.
For example 
```diff
- For First Pass,We know each run's size(lenSec = 1) is one 
- And we start a iteration via a ptr to list[1](current = 1)
- so we got mid = 10 - 2 * 1 + 1 = 9
- {26},{5},{77},{1},{61},{11},{59},{15},{48},{19}
                                          '-mid
+ 1. call Merge method 
+ 2. call Merge method {77},{1} start from element {77}   
+ 3. call Merge method {61},{11} starting from element {61}
+ 4. call Merge method {59},{15} starting from element {59}
```
![](https://i.imgur.com/WzqgmWf.png)


```c
/**
 * <p> Merge adjacent pairs of sorted segments(sub-arrays)
 *     From {@code List[]} to sorted {@cpde mergeList[]} </p>
 * <p> lenSec : the size of each SORTED array for this pass, e.g. merge {5,26} with {1,77} => lenSec = 2 </p>
 * <p> lenList: len of {@code list[]} </p>
 */
void mergePass(element List[], element mergeList[], int lenList, int lenSec)

/**
 * {@code current} : first element of first array
 * {@code rest}  : rest element that haven't been merged 
 * {@code midList} 
 *     middle element of {@code List[]}
 *     For first Pass 
 *     lenList : 1 
 *     lenSec : 1 (one run) {26},{5},{77},{1},{61},{11}
 *     mid : 1 - 2 + 1 = 0       
 */
int current ;    
int rest    ;    
int middle = lenList - 2*lenSec + 1 ;    
                    
/**
 * Each Pass merges sub-array in pairs (Each Section has length of 2 )
 * e.g.
 * Iterative Pass i= 1        :  {5,26} ,{1,77}, ... , ....
 * Iterative Pass i = 1 + 2*2 :  {1,5,26,77} , {11,61} {14,59}
 */
for(current=1; current<= middle; current+=2*lenSec)  
    /**********************************************************
     * Assume lenSec = 2 則要merge {x1,x2} with {x3,x4}  
     *  -> index of (end)x4 would be [2*lenSec - 1]
     *  -> index of mid in {x1,x2,x3,x4} 
     *     would be [current + lenSec - 1]
     * Think : warum (lenSec) -1 muss
     **********************************************************/
    int mid = current + lenSec   -1;
    int end = current + 2*lenSec -1;
    Merge(List, mergeList, current, mid, end);
if ( mid < n) 
    Merge(List,mergeList,current,current+lenSec,lenList);
else// there are no others can pair e.g. sub-array {19,48}
    for(rest = current ; rest <= lenList ; rest++ )
        mergeList[rest] = List[rest] ;
```

#### mergeSort
> wie functioniert mergeSort  
> ![](https://i.imgur.com/mtFP5JT.png)  

```c=
void mergeSort(element List, int lenList)
{
    /**
     * Do Iteration (Pass)
     * Pass = 1 -> merge each sub-array 
     *             whose size == 1 in pair
     * Pass = 2 -> merge each sub-array 
     *             whose size == 2 in pair
     * Pass = 3 -> merge each sub-array
     *             whose size == 4 in pair
     * Pass = 4 -> merge each sub-array 
     *             whose size == 8 in pair
     * If there are no pairs existing 
     * Then merge rest sub-array
     */
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


### Method 2
[Reference](http://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html)
```cpp
const int Max = 1000;

void Merge(std::vector<int> &Array, int front, int mid, int end){

    // 利用 std::vector 的constructor, 
    // 把array[front]~array[mid]放進 LeftSub[]
    // 把array[mid+1]~array[end]放進 RightSub[]
    std::vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1),
                     RightSub(Array.begin()+mid+1, Array.begin()+end+1);

    LeftSub.insert(LeftSub.end(), Max);      // 在LeftSub[]尾端加入值為 Max 的元素
    RightSub.insert(RightSub.end(), Max);    // 在RightSub[]尾端加入值為 Max 的元素

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++) {

        if (LeftSub[idxLeft] <= RightSub[idxRight] ) {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else{
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(std::vector<int> &array, int front, int end){
                                         // front與end為矩陣範圍
    if (front < end) {                   // 表示目前的矩陣範圍是有效的
        int mid = (front+end)/2;         // mid即是將矩陣對半分的index
        MergeSort(array, front, mid);    // 繼續divide矩陣的前半段subarray
        MergeSort(array, mid+1, end);    // 繼續divide矩陣的後半段subarray
        Merge(array, front, mid, end);   // 將兩個subarray做比較, 並合併出排序後的矩陣
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
