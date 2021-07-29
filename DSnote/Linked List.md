###### tags: `Data Structure`
# Linked List

Arten
1. Single Link List
2. Circular Link List
3. Double Link List

[TOC]

## Review of Typedef
```c=
//The definition will make ptr an alias for struct node *.
typedef struct node *ptr;
//Afterwards you can do either
struct node *some_pointer;
ptr some_pointer;
```

```c=
typedef struct Node {
    int data;
    struct Node *nextptr;
} node, *node_ptr;
/*
  This is arguably hard to understand, 
  but it has a lot to do with 
  why C's declaration syntax works the way it does 
  (i.e. why int* foo, bar ; 
  declares bar to be an int rather than an int* 
*/

/*
 build on your existing typedef
 */
typedef struct Node {
    int data;
    struct Node *nextptr;
} node;
typedef node* node_ptr;
//Or you can do it from scratch, 
//the same way that you'd typedef anything else:
typedef struct Node* node_ptr;
```

## A Node
![](https://i.imgur.com/L2Rb78D.png)


```c=
//  define struct listNOde* as listPtr
typedef struct listNode *listPtr;
struct listNode{
    char data[4];
    listPtr link;
};
```

![](https://i.imgur.com/RneAEeP.png)
```c=
MALLOC(first,sizeof(*first)
strcpy(first->data, "BAT");
first->link = NULL
```

## Insert A Node
![](https://i.imgur.com/hHCZm6o.png)

```c=
//using pointer to pointer 
/* trail : A pointer to Node before indesting/deleting */
void insert(listPtr *first, listPtr trail, int insertNum)
{
    listPtr temp;    
    MALLOC(temp,sizeof(*temp)); // temp->| char data[4] | link |
    // insert data to New Node
    temp->data = insertNum;
    if(*first)  // we have head node
    {   // record insertPtr's tail
        temp->link = trail->link;
        // link x's trail to the temp's front
        trail->link = temp;
    }
    else{
        temp->link = NULL;
        *first = temp; 
    } 
}
```

## Delete A Node

![](https://i.imgur.com/aJF2cr7.png)


Require:
- Node before Deleting Node
- Fist Node in the Linked-List
- Delete Node

```c=
void delete(listPtr *first,listPtr trail, listPtr delNode){
    
    /* Link Node before deleting Node \
       to the trail of Node after deleting node
    */
    if(trail)
    {
        trail->link = delNode->link ;
    }
    /* if trail is the first then change the first int data */
    else 
    {
        *first = (*first)->link;
    }
    free(delNode);
}
```

## Circulary Linked Lists

Last Node pointer to the First Node not NULL
![](https://i.imgur.com/WZT5udN.png)


![](https://i.imgur.com/sEtlBZm.png)

![](https://i.imgur.com/eurFUcy.png)


```c=
void insertFront(list_pointer *last, list_pointer node)
{
// last pointer to new Node , new Node pointer to first head 
 if (!(*last)) {
    /* list is empty, change last to point to new entry*/
    *last= node;
    node->link = node;
    }
    else {
        node->link = (*last)->link;  // 1 
        (*last)->link = node;        // 2
}
```

## Dobuly Linked List

A node in a doubly linked list has at least two fields (e.g., left link and right link).
Usually, each node will have a data field as well.

![](https://i.imgur.com/7VWU3I6.png)
 

```c=
typedef struct node* nodePtr;
struct node{
    element data;
    nodePtr llink,rlink;
}
```

**A header Node normally doesn't have the Data**
![](https://i.imgur.com/NRaVUCb.png)



A Doubly Link List
![](https://i.imgur.com/jFL8W6q.png)
More Readable
![](https://i.imgur.com/AUVgyyl.png)

It may or may not be a **circulary** and may or may not have **a header** 


### Insertion (Left links Left node, Right links Right node)

We need
- The node before the insertion

![](https://i.imgur.com/t4pdDmX.png)

![](https://i.imgur.com/32rYqfX.png)


```c=
void dinsert(nodePtr node, nodePtr newNode)
{
    // combine the newNode with Left one
    newnode->link = node;
    newnode->rlink = node->rlink; 
    // combine the Node after newNode to newNode
    node->rlink->llink = newNode;
    node->rlink = newNode;
}
```

### Deletion
What we need
- only the delete node

![](https://i.imgur.com/LsGt4n4.png)

```c=
void ddelete(nodePtr node,nodePtr deleted)
{
    if(node==deleted)
        printf("Deletion of header node not permitted. 
        \n");
    else{
        // left one of the deleted NOde
        (deleted->llink)->rlink = deleted->rlink;
        // right one of the deleted Node
        (deleted->rlink)->llink = deleted->llink;
        free(deleted);
    }
}
```

#### Deletion with Header


![](https://i.imgur.com/7prYgE9.png)



## Linked List Length, Concatenate, Invert

### Length

Single Linked List T(n)
![](https://i.imgur.com/S3OdNqq.png)
```c=
count = 0;
new(p)
p = listptr;
while (p≠ nil) do
    count++;
    p = p->link;
return count;
```

Circulary Linked List T(n)
![](https://i.imgur.com/2X7nwGV.png)
```c=
int length(list_pointer last)
{
list_pointer temp;
int count = 0;
if (last) {
    temp = last; // last a pointer to head Node
    do {
    count++;
    temp = temp->link;
    } while (temp!=last); // last node will pointer to Head node 
}
return count;
}

```

### Invert

Single Linked List
![](https://i.imgur.com/a9XANzQ.png)

```c=
list_pointer invert(list_pointer p)
{
list_pointer q, r;
q = NULL;
while (p) {
    r = q;
    q = p; 
    p = p->link;
    // reverse the link (pointer of next node to former node)
    q->link = r;
    }
return q; // pointer p to null 
}
```

Circular Linked List
![](https://i.imgur.com/TfNkmMG.png)

```c=
list_pointer invert(list_pointer C)
{
p = C->link;
q = C;
list_pointer q, r;
while (p) {
    r = q; 
    q = p; 
    p = p->link;
    
    // reverse the link (pointer of next node to former node)
    q->link = r;
    }
C->link = q; // pointer p to null 
C = q // Pointer C to q 
}
```


### Concatenate Two List T(M)
```c=
list_pointer concatenate(list_pointer ptr1, list_pointer ptr2)
{
   list_pointer temp;
   if (IS_EMPTY(ptr1)) return ptr2;
   else {
       if (!IS_EMPTY(ptr2)) {
        for (temp=ptr1; temp->link ; temp=temp->link);
        /*find end of first list*/
        temp->link = ptr2;
        }
        return ptr1;
    }
}

// O(m) where m is # of elements in the first list
```



