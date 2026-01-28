huuBuilding an os with custom launguage dex

learning about the cpu working and c


There are many layers of memory space in the cpu which have many functions 

The main types of memory are Stack, Heap, data, bss, text

========================================
1.) stack : it stores the local variables in lifo order , fast, recursion, it is temporary and stores the return address of variables 

2.) Heap : it stores the the variables which space will be allocated during runtime or by user using malloc() and it stores in the memory and it should be freed with free() because it is not automated leaving it cause memory leak and os crash

3.) Data : it stores the initialised variables eg a = 20 its a is initialised to 20

4.) BSS : it stores the uninitialised variables and static data variables i will not killed 
until the program ends eg int a,b; or static a 

5.) Text : it stores the other syntax it is readable only 

=====================================

TYPES OF VARIABLES 
1.) Local variables 
2.) Global variables
3.) Static variables 

----------------------------------------------
LOCAL VARIABLES 

void f() {
    int x = 10;
}

*) x will destroyed after the function ends
*) Local variables can be only used inside an particular function 
*)it leaves in data segment 

----------------------------------------------
GLOBAL VARIABLES 

int g;

*) g will above all the functions and can be used anywhere 
*) G lives in BSS/Data and exsist until the entire program runs

----------------------------------------------
STATIC VARIABLES

void f() {
    static int count;
}

*) count is initialised once an it value never changes per call
*)it lives in BSS segment 

=====================================

POINTERS(HEART OF C) 

int a = 10;
int *p = &a;

*) p stores the value of address
*) *p access the value at the address 

---------------------------------------

MAIN BUGS IN USING THE POINTERS

Dangling pointer - Points to freed memory
Memory leak - Heap memory never freed
Wild pointer - Uninitialized pointer

==============================

STACK MECHANISM 

*) LIFO (Last In First Out)
*) Grows downward (high → low address)
*) Fast because CPU supports it directly

-------------------------------------

FUNCTION CALL FLOW (FLOO EXAMPLE)

1.) call foo
2.) CPU pushes return address
3.) Function sets up stack frame
4.) Executes
5.) ret pops return address
6.) CPU jumps back

--------------------------------------

CALL, RET & RETURN ADDRESS (CPU LOGIC)

Why return address is needed

Without it:
*) CPU won’t know where to go back
*) Program will jump randomly
*) 💥 Crash / exploit


Important truth

1.) call pushes return address
2.) ret pops return address
3.) ret does NOT pop local variables
4.) Stack frame cleanup happens separately

--------------------------------------------

STACK OVERFLOW vs HEAP ISSUES

Stack Overflow

Caused by:
*) Infinite recursion
*) Too many local variables
*) Stack space is small → easy to crash

Heap problems
*) Memory leak → RAM exhaustion
*) Use-after-free → corruption
*) Double free → undefined behavior

---------------------------------------------

WHY STACK & HEAP CAN COLLIDE

Stack grows down
Heap grows up
If both grow too much → 💥 collision
OS stops program for safety

--------------------------------------------

ASSEMBLY MENTAL MODEL (IMPORTANT)

Think like this:
Stack = plate stack 🍽️
push → add plate
pop → remove plate
call → push return address
ret → pop return address & jump

CPU is dumb but fast.
Everything must be explicit.

--------------------------------------------
                        note by @dex.asm







