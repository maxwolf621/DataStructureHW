###### tags: `Data Structure`
# Additional Binary Tree Operation
[TOC]
## Convert Tree To B.T
- Hinweis : `Leftmost Child (leftChild) Next Right Sibling (Rightchild)`
- Algo
    ---
    ```c
    1.build up links relationship with Sibling
        - Using DFS
    2.delete links btw parent and child of A Tree
    ```
## Convert Forest to B.T
- Algo
    ---
    ```c
    1. Convert each Tree in Forest to B.T
    2. connect Each Tree's Root as Sibling
    3. Each link(Connecting Sibling) rotate degree 45 clockcounter
    ```


## Copying B.T
```c=
treePtr copy(treePtr orginalTree)
{
    treePtr temp;
    if(originalTree){
        MALLOC(temp, sizeof(*temp));
        temp->leftChild  =copy(original->leftChild);
        temp->rightChild =copy(original->rightChild);
        return temp;
    }
    return NULL;
}
```

## Test Equality
```c=
int equal(treePtr first, treePtr second)
{
    return(!first && !second) || 
    (first && second && first->data == second->data && equal(first->leftChild, second->leftChild) &&
    equal(first->rightChild, second->rightChild));
}
```

#### The Statisfiability Problem

The Set of Expressions can be formed using these variables anf operations is defined by the following rules
1. a variable is an expression
2. if x and y are expression then x ^ y, x ˇ y and -| x are expressions
3. parentheses can be used to alter the normal order of evaluation, which is not before `and &&` before `or ||`


## Threads
![](https://i.imgur.com/5kzUo4w.png)

![](https://i.imgur.com/7MMEllR.png)
- Rule
    - ptr->leftChild == NULL is replaced by a pointer to the node that would be visited after p when traversing the Tree in inorder.
That is,it is `replaced by the inorder successor of p`
    - ptr->rightChild == NULL is replaced by a pointer to the node that immediately precedes node p in inorder
    
    
    
```c=
typedef struct threadTree *threadPtr;
struct threadTree{
    char data;
    short int leftThread;
    short int rightTread
    threadPtr leftChild;
    threadPtr rightChild;
};
```


if ptr->leftThread == TRUE => ptr->leftChild contains a thread, or pointer to left child

if ptr->rightThread == TRUE => ptr->rightChild contains a thread, or pointer to right child


![](https://i.imgur.com/JVG2rhO.png)


## Disjoint 
- Def : A set of 互斥
    :::success
    S<sub>1</sub>={1,2,3}
    S<sub>2</sub>={7,8,10}
    S<sub>3</sub>={4,5,6,9}
    :::
    每個set利用Tree表示
    
### By Linked List

```c
struct set{
    int date;
    set * parent;
}
```

### By Array

![](https://i.imgur.com/wJXX5GZ.png)



### Application

- Kruskals 判斷 edge(u,v) 加入 Spanning Tree中是否形成`Cycle`


### Using Function Union(set i, set j) and Find(node x) to connect sets

`Union(i,j)` : Union set i and set j
`Find(node x)` : Find out node x in which set and return to root or root->data


- union
  ----
    ```c=
    // time complexity : O(1)
    Union(i= S1,j = S2)
    {
        j->parent = i;
        // or i->parent =j
        
    }
    ```

    ![](https://i.imgur.com/B5I36qT.png)

- find()
  ---
  Via Bottom-Up eine Wurzel entlang node x's parent ausschen  
  
  ```c
  Find(x)
  {
      temp = x;
      while(temp->parent != null)
      {
          temp = temp -> parent;
      }
      return temp
      
  }
  ```
  
### Note
Union(set i, set j)可能會產生一個Height為O(n)的tree,使得Find(x)'s time complexity become O(n)

![](https://i.imgur.com/fp3I3Fl.png)

## Using Function Union() by height to connect sets

Def : Set which is `Heiger` as New Root, and the other Set as its Child, if Sets with same Height select one of them as New Root

Advantage : es wird ein Balance Tree sein, es meint dass Zeitkomplexitaete von Find() O(logn) ist

:::success
Union() by Weighting, New Root depends on sums of `tree's nodes` , tree with more Nodes as the New Root
:::

![](https://i.imgur.com/SGa1NxA.png)


### Using Function Union() by `Height` and Find() with `path Compression`


Def : Find(x) wird mehre neue Funktion leisten, all parent's pathlinks von X's  wird die Wurzel zeigen

![](https://i.imgur.com/ESFFeKi.png)

- Time Complexity : **O(α(m,n)) &asymp; O(logn)** Amortized Cost concept


## Equivalence Relation (離散數學)
`It muss satisfy`
1. Reflexive
    $x\mathrel{R}x$
3. Symmetric 
    $x\mathrel{R}y$ then $y\mathrel{R}x$
4. Transiive
    $x\mathrel{R}y$ &#8898; $y\mathrel{R}z$ &rarr; $x\mathrel{R}z$	


- Example
  ---
    1&equiv;5, 4&equiv;2, 7&equiv;11, 9&equiv;10, 8&equiv;5, 7&equiv;9, 4&equiv;6, 3&equiv;12, 12&equiv;1

    **tips : i&equiv;j do Union(i,j), i zeigt auf j**
    ```graphviz
    digraph i{
        bgcolor=grey;
        rankdir = RL
        i -> j
    }
    ```


