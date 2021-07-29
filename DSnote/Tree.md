###### tags: `Data Structure`
# Tree
[TOC]

## Binary Tree 
![](https://i.imgur.com/Ih18MDm.png)

A binary Tree is a finite set of nodes that is either **empty**  or **consists of a root and two disjoint binary trees called the left subtree and the right subtree**

### Property Of Binary Tree
The Proof is by induction on i

1. Induction Base:
The root `is the only` node on level i = 1. Hence, the max number of nodes on level i is 
    :::success
    2<sup>1-1</sup> = 2<sup>0</sup> = 1
    :::
2. Induction Hypothesis:
Let i be an arbitrary positive integer greater than 1.
Assume that the max number of nodes on level i-1 is 2<sup>(i-1)-1</sup>

3. Induction Step:
The max number of nodes on level i-1 is 2^i-2 by the induction hypothesis.
`since` each node in a binary tree has a max degree of 2,the max number of nodes on level i is two times the max number of nodes on level **i-1, or 2<sup>i-1</sup>**
### Theorem 
![](https://i.imgur.com/OqLOAjv.png)

### Die Arten
- Skewed Binary Tree (sucks)
    - Height == Total number of Nodes
- FUll Binary Tree
    - Total Nodes == 2^H - 1
    - Height == Log2(Nodes+1)
- Complete Binary Tree

#### Skewed Binary Tree
Left-Skewed Binary Tree && Right-Skewed Binary Tree
![](https://i.imgur.com/Ng2c9LG.png)

#### Full Tree
![](https://i.imgur.com/t7cw6CZ.png)

#### Complete Binary Tree 
A complete binary tree is a binary tree in which every level, `except possibly the last`, is completely filled, and all nodes are as far left as possible.


- A binary Tree with `sequence node` (from left to right)
    - left child  : 2i but if 2i > n => L.child doesnt exist
    - right child : 2i + 1 but if 2i+1 > n => R.child doesn't exist
    - Parent      : $\frac{i}{2}$; but if $\frac{i}{2} < {1}$ => Parent doesn't exist 

## Binary Tree Structure

### Array Representation


| 1  | 2 | 3 | 4 | 5 |
| -- | --| --| --| --|
| A  | B | C | D | E |
![](https://i.imgur.com/KTzaYXR.png)

- Array of Skewed B.T (suck)
    `Waste the MemoryPlatz` as following.

    ![](https://i.imgur.com/SXCvRul.png)


- Lemma :
    --- 
    If a complete binary tree with n nodes is represented `sequentially`, then for any node[i], **$1 \le i \le n$**, we have
    1. parent (i) is at `i/2` floor if $i \ne 1$,
        - if parent(i) is Root => 0
    3. leftChild(i) is at `2i` if $2i \le n$. 
        - If $2i>n$,then i (which you pick up) has no left child
    5. rightChild(i) is `2i+1` if $2i+1 \le n$. 
        - If $2i+1 > n$, then i ( which you pick up) has no right child

### Linked Representation

```c=
typedef struct node* treePtr;
struct node{
    int data;
    treePtr leftChild,rightChild;
}
```

- A node 
![](https://i.imgur.com/bV3yMIq.png)

- Combining Each Nodes
![](https://i.imgur.com/WEKleva.png)


## Binary Tree Traversal and Tree Iterators
- Using Recursion to handle Inorder,Preorder and Postorder
![](https://i.imgur.com/onn1QbO.png)


### Inorder Traversal `L->V->R`
![](https://i.imgur.com/a9kFkTe.png)


1. Moving down the tree toward the left ***until you can go no farther (`meets NULL`).***
2. Then you `vist(print)` the node, ***move one node to the right*** and continue
3. If you can not move to the right, ***go back one more node***

```c
void inorder(treePtr ptr)
{
    if(ptr){
        inorder(ptr->leftChild);     // L 
        printf("%d", ptr->data);     // V 
        inorder(ptr->rightChild);    // R
    }
}
```
![](https://i.imgur.com/Ci8A8hb.png)

### Preorder Traversal `LRV`
1. `visit(print)` the node, traverse left, and continue
2. when you can not continue, move right and begin again or move back until you can move right and resume

```c=
void preoder(treePtr ptr)
{
    if(ptr){
        printf("%",ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
```
### Postorder Traversal `VLR`

```c=
void preoder(treePtr ptr)
{
    if(ptr){
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
        printf("%",ptr->data);
    }
}
```

## Using Stack do Iterative Inorder Traversal 
( there are also Pre-,Postorder Traversal)
![](https://i.imgur.com/YpnkJ2F.png)
    
```c=
// Using Stack
void iterInorder(treePtr node)
{
    int top = -1;
    treePtr stack[maxStackSize];
    for(;;){
    
        // IF NODE != NULL THEN DO FOR LOOP
        for(; node ; node = node->leftChild)
            push(node);
        node = pop(); // first Pop is A, /, ...
        if(!node) break;
        printf("%d", node->data);
        node = node->rightChild;
    }
}
```

## Level-Order Traversal Using Queue

![](https://i.imgur.com/fVINzgy.png)

Begin by 
1. Visiting the root and adding it's children to the queue
2. The next node to visit is obtained from the front of the queue(A node's children are at the next lower level,so adding the left.C before the Right.C)
3. print all the node at same level 

```c=
void levelOrder(treePtr node)
{
    int front = 0, rear = 0;
    treePtr queue[maxStackSize];
    if(!ptr) return;
    addq(ptr);  // add "the Root" into queue
    for(;;){
        ptr = deletq();
        if(ptr){
            printf("%d",ptr->data);
            if(ptr->leftChild) addq(ptr->leftChild);
            if(ptr->rightChild)addq(ptr->rightChild)
        }else break;
    }
}
```




## Predecessor and Sucessor
Predecessor : Max(leftchild)
Sucessor    : Min(rightchild) 
![](https://i.imgur.com/Efv7ylQ.png)

## B.T Insert,Search and Deletion


### Search using Recursion
![](https://i.imgur.com/1bf3W8F.png)
### Search using Iterative
![](https://i.imgur.com/iALwPsk.png)

### Insertion using Recursion  
```c=
nodeptr Insert(nodeptr node, int data)
{
    if(!node)
        node = (nodeptr) malloc(sizeof(struct node));
        if(!node)
        {
            puts("Memory Error");
            return node;
        }
        else
        {
            tree->data  = data;
            tree->left  = NULL;
            tree->right = NULL;
        }
    // Tree-Traversal
    else{
        if(data < node->data) Insert(node->left,data)
        else                  Insert(node->right,data)
    }    
    return node;
}
```
![](https://i.imgur.com/D3h5R4t.png)

### Deletion

![](https://i.imgur.com/Bc7FALR.png)


```c
nodeptr delete(nodeptr tree, int val)
{
    nodeptr cur, parent, suc, psuc, ptr ;
    if(!tree->left)
    {
        printf("\n The Tree is Empty");
        return(tree);
    }
    parent = tree;
    cur    = tree->left ; 
    
    
    while(cur != NULL && val != cur->data)
    {
        parent = cur    ;
        cur    = (val < cur->data) ? cur->left : cur->right;
   }
   if ( cur == NULL)
   {
       printf("\n The value to be delete is not present in the tree");
       return(tree)
   }
   
   // 3 cases
   if( cur->left == NULL)       ptr = cur->right    ;
   else if(cur->right == NULL)  ptr = cur->left     ;
   else
       psuc = cur          ;
       cur = cur->left     ;
       while(suc->left != NULL)
       {
           psuc = suc;
           suc  = suc->left;
       }
       if(cur == psuc)
       {
           suc->left = cur->right;
       }
       else
       {
           suc->left = cur->left;
           psuc->left = suc->right;
           suc->right = cur->right
       }
       if(parent->left == cur)
           parent->left = ptr;
       else
           parent->right = ptr;
       free(cur)
       return tree
}
```
```c
Delete (TREE, VAL)
 IF TREE = NULL
     Write "VAL not found in the tree"
 // Find Out The Value
 ELSE IF VAL < TREE -> DATA
        Delete(TREE->LEFT, VAL)
 ELSE IF VAL > TREE -> DATA
        Delete(TREE -> RIGHT, VAL)
 ELSE IF 
     TEMP TREE = findLargestNode(TREE LEFT AND TREE -> RIGHT -> LEFT)
     TREE -> DATA = TEMP -> DATA
     Delete(TREE -> LEFT, TEMP -> DATA)
 ELSE
     SET TEMP = TREE
 IF TREE -> LEFT = NULL AND TREE -> RIGHT = NULL
     SET TREE = NULL
 ELSE IF TREE -> LEFT != NULL
 ELSE
     SET TREE = TREE -> LEFT
     SET TREE = TREE -> RIGHT
 FREE TEMP
```

```c=
/* recursivly */
nodeptr delete(nodeptr parentNode, int val)
{
    nodeptr presuc, deleteptr;
    if(!parentNode) printf("Element not there in tree");
    // Tree-Travel to find the Node to be deleted
    else if(val < parentNode->data)    delete(parentNode->left) ;
    else if(val > parentNode->data)    delete(parentNode->right);
    
    // check the deleted Node if children exit
    else
        // Node to be deleted has two children
        if(parentNode->left && parentNode->right){
            // Find Presuc
            presuc = findMax(parentNode->left);
            parentNode->data = presuc->data   ;
            // update the parentNode's left Child
            parentNode->left = delete(parentNode->left,parentNode->data)
        }
        // if deleted_node has one child or no children
        else{
            deletptr = parentNode ;
            // check the child and link it 
            if(!parentNode->left)  parentNode = parentNode->right;
            if(!parentNode->right) parentNode = parentNode->left ;
            free(deletptr)                                       ;                                            ;
        }
    return paretNode;
}
```