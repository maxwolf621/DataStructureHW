<style>

html,
body, 
.ui-content,
/*Section*/
.ui-toc-dropdown{
    background-color: #1B2631;
    color: #9BCBFC;
}

body > .ui-infobar {
    display: none;
}

.ui-view-area > .ui-infobar {
    display: block ;
    color: #5D6D7E ;
}

.markdown-body h1,
.markdown-body h2,
.markdown-body h3,
.markdown-body h4,
.markdown-body h5,
/*> first 
 *>> second
 */
.markdown-body blockquote{	
    /*#7FFFD4*/
    /*#59FFFF*/
    color: #7FFFD4;
}

.markdown-body h6{
    color: gold;
}
.markdown-body h1,
.markdown-body h2 {
    border-bottom-color: #5D6D7E;
    border-bottom-style: ;
    border-bottom-width: 3px;
}

.markdown-body h1 .octicon-link,
.markdown-body h2 .octicon-link,
.markdown-body h3 .octicon-link,
.markdown-body h4 .octicon-link,
.markdown-body h5 .octicon-link,
.markdown-body h6 .octicon-link {
    color: yellow;
}

.markdown-body img {
    background-color: transparent;
}

.ui-toc-dropdown .nav>.active:focus>a, .ui-toc-dropdown .nav>.active:hover>a, .ui-toc-dropdown .nav>.active>a {
    color: gold;
    border-left: 2px solid white;
}

.expand-toggle:hover, 
.expand-toggle:focus, 
.back-to-top:hover, 
.back-to-top:focus, 
.go-to-bottom:hover, 
.go-to-bottom:focus {
    color: gold;
}

/*dropdown Bar*/
.ui-toc-label.btn {
    background-color: #191919;
    color: #eee;
}

/*tests inside the bar*/
.ui-toc-dropdown .nav>li>a:focus, 
.ui-toc-dropdown .nav>li>a:hover {
    color: gold;
    border-left: 1px solid white;
}


/*for table*/
.markdown-body table tr {
    background-color: #5f5f5f;
}
.markdown-body table tr:nth-child(2n) {
    background-color: #4f4f4f;
}


.markdown-body code,
.markdown-body tt {
    color: #eee;
    background-color: rgba(200, 230, 230, 0.36);
}


a,.open-files-container li.selected a {
    color: #5EB7E0;
}


/*für == == , <mark>*/
.markdown-body mark {
  background-color:  ;
  color: #E74C3C ;
  font-family: Helvetica;
}
  

.markdown-body pre
 {
  display: block;
  font-family: monospace;
  white-space: pre;
  margin: black;
  color : #026C5D;
  background-color: ;
}


</style>

###### tags: `Data Structure`

# Hash 
[TOC]


## Internal Search and External Search
- Intrnal Search
    ---
    1. 處理Data較少
    2. All Data can speichern in Memory
- External Search
    ---
    - 處理Data較少
    - Data無法一次全部存在Memory當中需要外部硬體協助(z.B. Disk)

## Different Static Search and Dynamic Search
![](https://i.imgur.com/ISy2ehj.png)


## Linear Search (Sequential Search)
Def : 逐一比較Data Set內的key是否相同
- Data Set不須`事先排序`
- Implementation
    Random Access (e.g Array)
    Sequential Access(e.g Link List)實現
- Time Complexity 
    $O(n)$


## Hashing
- 資料儲存與搜尋的技術
```
x - > H(x) -> slot -> Hashtable
```
- 優點
    - 搜尋資料時,記錄不必要事先排序
    - `Zeitkomplexität von Suchung nur O(1)` wenn es no collision or overflow gibt，
    - 經過`Hash Function`處理後，資料的**保密性以及安全性提高**
    - 作為`Data Compression`之用

![](https://i.imgur.com/QI1aKED.png)

- Bucket: Each Position of Array
- Slot  : Platz in Bucket,Data zu Speichern
- Hash table size : $Bucket×Slot$



### Overflow and Collision
- 「Collision」
出現兩個不同的資料 X、Y，經過「Hashing function」計算後，得到相同的「Hashing address」
Wenn Collison passiert,es gibt kein slot in Bucket,Data zu speichern

- 「Overflow」
當「Collision」發生並且該「Bucket」無「Slot」可儲存
    - 有Collision並不一定有Overflow，反之有Overflow則有Collision發生
    - Es gibt `nur Ein Slot` in Bucket $\Longrightarrow$ Collision = Overflow
    
    ![](https://i.imgur.com/xaf2RDt.png)

### Loading and Identifier Density

- Identifier Density
    - T : Total of num of Identifier
    - n : keys
    - b : Bucket's Size of Hash table 
    - S : num of Slots
    - &alpha; : Hashtable Utilization $\uparrow \  \Longrightarrow$ Probality of Collision and Overflow $\uparrow$
    $$ Identifier \ Density = \frac{n}{T} $$
    $$ Loading \ Density = \alpha = \frac{n}{b \times S} $$
### Funktionsgestaltung
- Choice of hash function 
    - To avoid collision (two different pairs are in the same the same bucket.)
    - Size (number of buckets) of hash table.
- Overflow handling method
- Rechnung möglich vereinfachen
    - minimal number of collisions
- A good hashing function distributes the key values uniformly through the range.


## Hash Function


### Mod
- Def: H(x) = x mod m
- Choice of m
	- $m \neq Even$
    divisor is an even number, odd integers hash into odd home buckets and even integers into even home buckets.
    ```
    20%14 = 6, 30%14 = 2, 8%14 = 8
    15%14 = 1, 3%14 = 3, 23%14 = 9
    ```
    if divisor is an odd number, odd (even) integers may hash into any home.
    ```
    20%15 = 5, 30%15 = 0, 8%15 = 8
    15%15 = 0, 3%15 = 3, 23%15 = 8
    ```
### Folding Addtion
- Def:　
	1.Schlüssel in Abschnitt (x個) unterteilen(Länge jedes Abschnitts ist n)
	2.Abschnitten zusammenfassn   $$\sum_{n=1}^x k$$

- Arten:
	- Shift
	- Folding at the Boundaries
	    - reserve odd Abschnitt 
- Example
	```c
	wenn n = 3 ist
	x = 123,203,241,112,20
	
	By Shift : P1 = 123, P2 = 203, P3 = 241,P4=112,P5 = 020
	h(x) = 123 + 203 + 241 + 112 + 20 = 699
	
	By Boundaries
	123
	203
	241
	112
	020 
	
	h(x) =  123 + 302 + 241 + 211 + 20 = 897;
	```

### Digits Analysis
- Def : `Given Data` => Ein Grundlage `r`	bestimmen und die Spezifische Ziffer auswerten 

- Situation : wenn data ist
	1. Intensive : diese Ziffer aufgeben
	2. Extensive : diese Ziffer aussuchen
	
## Überlaufbehandlung

### Linear Probing(Linear Open Addressing)
- Linear Probing resolves collisions by placing the data into the next open slot in the table.
![](https://i.imgur.com/4DDX8cI.png)

- Der Nachteil
    - Identifiers tend to cluster together
    - Adjacent cluster tend to `coalesce` 
    ![](https://i.imgur.com/3Uent4P.png)
    - Increase the search time `O(n)``
    

### Quadratic Probing
- Die Formel $$H(x) \pm i^2 \ mod \ b \\ 1 \le i \le \frac{b-1}{2}$$
![](https://i.imgur.com/oLgyxZa.png)

- b is a prime number of the form 4j+3, j is an integer
    ![](https://i.imgur.com/vSfzrg8.png)


### Random probing.
### Rehashing
### Link List (Chain)
利用Linked List方式將相同的Home bucket串連在同一Bucket中
![](https://i.imgur.com/iX7tDwR.png)


## Expected Performance

$$loading \ density(\alpha)= \frac{(number \ of \ pairs)}{b}$$

$$\alpha = \frac{12}{17}$$

$S_n$ : expected number of buckets examined in a successful search when n is large

$U_n$ : expected number of buckets examined in a unsuccessful search when n is large

`Time to put and remove governed by` $U_n$.

- Example
  ---
  ![](https://i.imgur.com/I0x5XUq.png)

    $$0\le \alpha \le 1$$
    $$S_n = \frac{1}{2}(1+\frac{1}{1-\alpha})$$
    $$U_n = \frac{1}{2}(1+\frac{1}{(1-\alpha)^2})$$

    Grund : Time to put and remove governed by $U_n$
    Recommended : $\alpha \le 0.75$

- Example (Coalesce Phenomenon)
  ---

![](https://i.imgur.com/8MJz0gZ.png)
