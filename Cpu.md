Building an os with custom launguage dex

learning about the cpu working and c


There are many layers of memory space in the cpu which have many functions 

The main types of memory are Stack, Heap, data, bss, text


1.) stack : it stores the local variables in lifo order , fast, recursion, it is temporary and stores the return address of variables 

2.) Heap : it stores the the variables which space will be allocated during runtime or by user using malloc() and it stores in the memory and it should be freed with free() because it is not automated leaving it cause memory leak and os crash

3.) Data : it stores the initialised variables eg a = 20 its a is initialised to 20

4.) BSS : it stores the uninitialised variables and static data variables i will not killed 
until the program ends eg int a,b; or static a 

5.) Text : it stores the other syntax it is readable only 
