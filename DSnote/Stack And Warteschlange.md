<style>
html, body, .ui-content {
    background-color: #333;
    color: #ddd;
}

body > .ui-infobar {
    display: none;
}

.ui-view-area > .ui-infobar {
    display: block;
    color: #999;

}

.markdown-body h1,
.markdown-body h2,
.markdown-body h3,
.markdown-body h4,
.markdown-body h5{
    color: #d1f1a9;
}

.markdown-body h6{
    color: yellow;
}

.markdown-body h1,
.markdown-body h2 {
    border-bottom-color: #ffffff69;
}

.markdown-body h1 .octicon-link,
.markdown-body h2 .octicon-link,
.markdown-body h3 .octicon-link,
.markdown-body h4 .octicon-link,
.markdown-body h5 .octicon-link,
.markdown-body h6 .octicon-link {
    color: #fff;
}

.markdown-body img {
    background-color: transparent;
}

.ui-toc-dropdown .nav>.active:focus>a, .ui-toc-dropdown .nav>.active:hover>a, .ui-toc-dropdown .nav>.active>a {
    color: white;
    border-left: 2px solid white;
}

.expand-toggle:hover, 
.expand-toggle:focus, 
.back-to-top:hover, 
.back-to-top:focus, 
.go-to-bottom:hover, 
.go-to-bottom:focus {
    color: white;
}


.ui-toc-dropdown {
    background-color: #333;
    /*background-image: linear-gradient(90deg, #111, #333;*/
}

.ui-toc-label.btn {
    background-color: #444;
    color: white;
    /*background-image: linear-gradient(10deg, #333, #333);*/
}

.ui-toc-dropdown .nav>li>a:focus, 
.ui-toc-dropdown .nav>li>a:hover {
    color: white;
    border-left: 1px solid white;
    
}


.markdown-body table tr {
    background-color: #2a4a5f;
    color: #66cccc;

}
.markdown-body strong{
    color: #cc6666;
}


.markdown-body blockquote {
    color: #bcbcbc;
    background: ;
}

.markdown-body table tr:nth-child(2n) {
    background-color: #4f4f4f;
}


.markdown-body table tr:hover {
    background-color: #ebaa;
}

.markdown-body code,
.markdown-body tt {
    color: #eee;
    background-color: rgba(230, 230, 230, 0.36);
}

a,
.open-files-container li.selected a {
    color: #5EB7E0;
}

.markdown-body mark{
    color:#d54e53;
    background: #ffeead;
}

.markdown-body pre{
    background: #E1FCFF;
    color: #243C5A;
}

</style>

###### tags: `Data Structure`



# Stack And Warteschlange
[TOC]

## Stack with Array
![](https://i.imgur.com/OknuUaz.png)
```c
int top = 0; // To Check if stack is voll
int S[top] = {0}; //stack
```

### Push and Pop
Push
```c 
if top = n
    printf("stack is full");
else
    S[top++] = item;
```
Pop
```c
if top < 0;
    printf("stack is empty");
else
    // herausnehmen
    type item = 0 ; // initialize
    item = S[top--];
```
## Stack with Linked List
- Warum mit der Verkettete Listen nutzet statt Array
    - Wenn es ein Speicherplatz gibt, O.S wird push() druchsetzen.
    - Mit Array markiert O.S immer darauf ob es voll beleibt.


![](https://i.imgur.com/9ovP6LF.png)
- Was du brauchst
    1. A set of data Item 
    2. Top : Pointer to the Top of the Stack
    3. Size: Größe der Stack 
- Function
    1. Create(Stack)
    2. Push(Stack,item) 
    4. Pop(Stack) 


### Push and Pop
![](https://i.imgur.com/wXMQpvq.png)

### Push 

##### Perseudo Code
```c
new(t) // malloc
pNew->data = item;
/* 1 */
pNew->link = top;  // new item always  on Top of stack
/* 2 */
top = pNew ;
```

```c=
void push(int i /* index */, element item /* is pushed into */){
    stackPtr temp;
    MALLOC(temp,sizeof(*temp));
    temp->data = item;
    temp->link = top[i];
    // top[i] pointer to temp
    top[i] = temp; 
}
```

### Pop
![](https://i.imgur.com/i5MSDHk.png)


##### Perseudo Code
```c=
if(top = null)
    Stack empty;
else 
    /* 1 */
    delPtr = top      ;  
    /* 2 */
    item = top->data  ;
    /* 3 */
    top = delPtr->link;
    /* 4 */
    free(delPtr)      ;
```

```c=
element pop(int i){
    element item;             // Get the element in Stack
    stackPtr temp = top[i];  // Pointer to Top[i]
    item =  temp->data;      // get the data 
    top[i] = temp->link;    // pointer to last satck
    free(temp);             //delete
    return item;           
}
```

## Queue  
![](https://i.imgur.com/7bhQyMc.png)


##### Zugriff
- FIFO
##### Operationen: 
1. create()
2. AddQ()
3. DeleteQ()
##### Implementierung:
1. Sequentiell (Array, ggf. zyklisch!)
    - Problematisch bei Größenänderungen 
3. Verkettete Liste (s.u.)
##### Anwendung: Prioritätswarteschlangen
- Used when Applications with the same Priority

##### Statement
```c=
typedef struct queue *queuePtr;
struct queue{
    element data;
    queuePointer link;
};
queuePtr front[maxQueues], rear[maxQueues];
//initialize
front[i] = rear[i] = NULL 
```

### AddQ
##### perseudo Code
Case 1 : Front und Rear zeigen der selben speichernplatz (Queue ist leer)
    ![](https://i.imgur.com/KMtUBjj.png)
Case 2 : Wartenschlangen ist nicht leer
    ![](https://i.imgur.com/yVWvlgD.png)

```c=
/* A new Element to be added */

AddQ(){
    new(newPtr);
    newPtr->data = item;
    newPtr->link = NULL ;
    /* Case 1 or Case 2 decided by rear */
    if(!rear) // case 1 if es gibt kein rear (rear == null)
    front = newPtr;
    else // case 2
    rear->link= newPtr;
}
```


```c=
void Addq(int i, element item){
    queuePtr temp;
    MALLOC(temp,size(*temp));
    temp->data = item;
    temp->link = NULL;
    if(front[i]) // if font is not null
        rear[i]->link = temp;
    else
        front[i] = temp;
    rear[i] = temp;    // pinter tto temp
}
```

### DeleteQ
![](https://i.imgur.com/M2CvvBJ.png)
```c
if(!front)
    print("Queue is empty");
else
    deleteLoc = front; // A pointer to the Node (front)
    item = front->data;
    fron = front->link;
    free(deleteLoc);
    if(!front)  // check if front would be a last Node in queue
        rear = null;
```

### Queue with Array

#### Statement
```c=
int queue[n];  // array
int *front ,*rear = null;
```

#### AddQueue
```c=
void addq(int *rear, element item)
{
 /* add an item to the queue */
 if (*rear == MAX_QUEUE_SIZE_1) {
 queue_full( );
 return;
 }
 queue [++*rear] = item;
}
```
#### DeQueue
```c=
element deleteq(int *front, int rear)
{
/* remove element at the front of the queue */
if ( *front == rear)
return queue_empty( ); /* return an error key */
return queue [++ *front];
}
```

#### Algorithm of queue
![](https://i.imgur.com/Rt1DBrw.png)


### Circular queue
![](https://i.imgur.com/ccDUp3j.png)

```c=

addq()
rear = (rear+1) mod n;        //rear指標先前進
if (rear = front) QueueFull; //表示Queue滿了
rear = rear-1 mod n;
else Q[rear]=item;          //將rear重設回前一格
deleteq()
if front=rear //先檢查
QueueEmpty;
 else begin
front = (front+1) mod n;
item = Q[front];
 

```


![](https://i.imgur.com/zzGS7iS.png)



## Stack with Infix, Prefix and Postfix

Infix轉Postfix的演算法 (利用1個Stack)
![](https://i.imgur.com/Avr0nim.png)
Postfix之計算的演算法
![](https://i.imgur.com/XcsWg3E.png)

![](https://i.imgur.com/1aAIkj3.png)

Infix轉Prefix的演算法 (利用2個Stack)
![](https://i.imgur.com/JvU3Q4R.png)

Prefix之計算的演算法
![](https://i.imgur.com/aLCTOAx.png)


### Compileer and User
![](https://i.imgur.com/mP6c703.png)


### Exxample

![](https://i.imgur.com/cloqlfr.png)

![](https://i.imgur.com/3UQy8Tk.png)

![](https://i.imgur.com/fY4UCC2.png)

![](https://i.imgur.com/yliUb6Z.png)

### Postfix EVAL

 ```c=
 
#define MAX_STACK_SIZE 100 /* maximum stack size */
#define MAX_EXPR_SIZE 100 /* max size of expression */
typedef enum{lparan, rparen, plus, minus, times, divide,
mod, eos, operand} precedence;
int stack[MAX_STACK_SIZE]; /* global stack */
char expr[MAX_EXPR_SIZE]; /* input string */

// eval a postfix expression
int eval(void)
{
/* evaluate a postfix expression, expr, maintained as a
global variable, ‘\0’ is the the end of the expression.
The stack and top of the stack are global variables.
get_token is used to return the token type and
the character symbol. Operands are assumed to be single
character digits */

    precedence token;
    char symbol     ;
    int op1,op2     ;
    int n = 0     //counter for the expression string 
    int top = -1 //for the stack
    token = getToken(&symbol, &n) ;
    
    while(token != eos){
        if(token == operand)
            push(&top,symbol-'0');
        else{
            op2 = pop();
            op1 = pop();
            switch(token){
             case plus: add(&top, op1+op2); break;
             case minus: add(&top, op1-op2); break;
             case times: add(&top, op1*op2); break;
             case divide: add(&top, op1/op2); break;
             case mod: add(&top, op1%op2);                                                
            }
        }
        tonken = getToken(&symbol, &n);
    } 
    return pop();
}

precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++]
    switch(*symbol){
    case '(' : return lparen  ;
    case ')' : return rparen  ;
    case '+' : return plus    ;
    case '-' : return minus   ;
    case '*' : return times   ;
    case '/' : return divide  ;
    case '%' : return mod     ;
    case '\0' : return eos     ; 
    default  : return operand ;
    }
}
```

## Rule and algo of Infix to Postfix
1. Operators are taken out of the stack as long as their
**in-stack precedence is higher than or equal to the
incoming precedence** of the new operator.
2. ( has low in-stack precedence, and high incoming
precedence.
![](https://i.imgur.com/NmirYBY.png)

![](https://i.imgur.com/ooa9xtI.png)

![](https://i.imgur.com/3QSEXJ8.png)

![](https://i.imgur.com/yXGLy0q.png)

### Push symbol `()`,`+,-,*,/,%` into stack 
![](https://i.imgur.com/kyrVYJ5.png)


Concept
- stack push/pop the symbol not character and integer
- isp and icp arrays == index is value of precedence lparen,rparen,plus, minus,times,divid,mod,eos

```
a*(b+c)*d  ==  abc+*d*
```

```c=
precedence stack[MAX_STACK_SIZE];
/* isp and icp arrays -- index is value of precedence
lparen, rparen, plus, minus, times, divide, mod, eos */
static int isp [ ] = {0, 19, 12, 12, 13, 13, 13, 0}; // in-stack
static int icp [ ] = {20, 19, 12, 12, 13, 13, 13, 0}; // in-coming

void postfix(void)
{
    // symbol = "a*(b+c)*d"
    char symbol;
    precedence token;
    int n = 0, top = 0 
    stack[0] = eos /*place eos on stack*/;
    for((token = getToken(&symbol,  &n);
        token ! = eos; 
        token = getToken(&symbol, &n)){
            if(token == operand) printf("%c", symbol);
            else if (token == rparen){
            //meet ')' unstack all the operand in stack until meets '('
               while(stack[top] != lparen) printfToken(pop());
               pop(); /* discard the left parenthesis */
            }else {
            /* remove and printf symbols 
             * whose isp is greater 
             * than or equal to the current token's icp */
         while(isp[stack[top]] >= icp[token]) printToken(pop());
         push(token)
        }
    }
}
```


## Mutiple Stacks and Queues

Two Stacks
![](https://i.imgur.com/VOkM7wW.png)

memory is divided into n equal segments
boundary[stack_no] : 0 < stack_no < MAX_STACKS
top[stack_no]      : 0 < stack_no < MAX_STACKS
Initially, boundary[i]=top[i].

![](https://i.imgur.com/LH8ewF3.png)

```c=
#define MEMORY_SIZE 100 /* size of memory */
#define MAX_STACK_SIZE 100
/* max number of stacks plus 1 */
/* global memory declaration */
element memory[MEMORY_SIZE];
int top[MAX_STACKS];
int boundary[MAX_STACKS];
int n; /* number of stacks entered by the user */
top[0] = boundary[0] = -1;
for (i = 1; i < n; i++)
    top[i] =boundary[i] =(MEMORY_SIZE/n)*i;
    boundary[n] = MEMORY_SIZE-1;

void add(int i, element item)
{
/* add an item to the ith stack */
if (top[i] == boundary [i+1])
stack_full(i);   //may have unused storage
memory[++top[i]] = item;
}

element delete(int i)
{
/* remove top element from the ith stack */
if (top[i] == boundary[i])
return stack_empty(i);
return memory[top[i]--];
}
```