MEMORY LAYOUT OF AN PROGRAM 
-----
    
    High Address
    ┌─────────────┐
    │   Stack     │  ↓ grows downward
    ├─────────────┤
    │   Heap      │  ↑ grows upward
    ├─────────────┤
    │   BSS       │  (uninitialized  globals/statics)
    ├─────────────┤
    │   Data      │  (initialized globals/statics)
    ├─────────────┤
    │   Text      │  (code, read-only)
    └─────────────┘
    Low Address
---------

1.)Text :
----------------------

*) Contains machine code
*)Read-only → prevents self-modifying code

2.)Data :
----

*)Global / static variables with initial values

3.)BSS :
------

*) Global / static variables without initialization
*) Initialized to 0 automatically


4.) Heap :
----
*)Dynamic memory (malloc, free)
*)Manual control → powerful but dangerous

5.)Stack :
----

*)Local variables
*)Function calls
*)Return addresses
*)Fast, automatic, limited size



/*
 * ============================================================================
 * MEMORY LAYOUT OF A C PROGRAM - Complete Reference
 * ============================================================================
 */

/*
 * Memory Layout Visualization:
 * 
 * HIGH ADDRESS 0xFFFFFFFF
 * ┌─────────────────────────────────┐
 * │ Command-line arguments & env    │
 * ├─────────────────────────────────┤
 * │            STACK                │ ↓ Grows DOWNWARD
 * │ • Function frames               │
 * │ • Local variables               │
 * │ • Return addresses              │
 * │ • Parameters                    │
 * ├─────────────────────────────────┤
 * │            ↓↓↓                  │
 * │        (free space)             │
 * │            ↑↑↑                  │
 * ├─────────────────────────────────┤
 * │            HEAP                 │ ↑ Grows UPWARD
 * │ • malloc/calloc/realloc         │
 * │ • Free store                    │
 * │ • Dynamic memory                │
 * ├─────────────────────────────────┤
 * │     Uninitialized Data (BSS)    │
 * │ • Zero-initialized globals      │
 * │ • Static variables (no init)    │
 * ├─────────────────────────────────┤
 * │     Initialized Data (DATA)     │
 * │ • Initialized globals           │
 * │ • Static variables with init    │
 * │ • String literals               │
 * ├─────────────────────────────────┤
 * │        TEXT/CODE SEGMENT        │
 * │ • Machine code                  │
 * │ • Read-only                     │
 * │ • Executable instructions       │
 * └─────────────────────────────────┘
 * LOW ADDRESS  0x00000000
 */

/*
 * ============================================================================
 * EXAMPLE PROGRAM DEMONSTRATING ALL SEGMENTS
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---------------------------------------------------------------------------*/
/* 1. TEXT SEGMENT - Code goes here                                          */
/*    Read-only, executable machine instructions                             */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* 2. DATA SEGMENT - Initialized global/static variables                     */
/*    Read-write, persists throughout program                                */
/*---------------------------------------------------------------------------*/
int initialized_global = 100;               // DATA segment
const int read_only_global = 200;           // DATA (read-only portion)
static int initialized_static = 300;        // DATA segment
char *string_literal = "Hello, World!";     // String literal in DATA

/*---------------------------------------------------------------------------*/
/* 3. BSS SEGMENT - Uninitialized global/static variables                    */
/*    Zero-initialized at program start                                      */
/*---------------------------------------------------------------------------*/
int uninitialized_global;                   // BSS segment
static int uninitialized_static;            // BSS segment
char buffer[1024];                          // BSS (all zeros)

/*---------------------------------------------------------------------------*/
/* Helper function to demonstrate stack behavior                             */
/*---------------------------------------------------------------------------*/
void stack_demo(int param1, char param2) {  // Parameters on stack
    /* Local variables - allocated on STACK */
    int local_var = 10;                     // Stack frame
    char local_array[50];                   // Stack
    int *local_pointer;                     // Pointer itself on stack
    
    printf("\n=== STACK FRAME ===\n");
    printf("Address of param1:   %p\n", (void*)&param1);
    printf("Address of param2:   %p\n", (void*)&param2);
    printf("Address of local_var: %p\n", (void*)&local_var);
    printf("Address of local_array: %p\n", (void*)local_array);
    printf("Address of local_pointer: %p\n", (void*)&local_pointer);
    
    /* Nested function call creates new stack frame */
    if (local_var > 0) {
        int nested_local = 20;              // New stack frame
        printf("Address of nested_local: %p\n", (void*)&nested_local);
    }
}

/*---------------------------------------------------------------------------*/
/* Function to demonstrate heap allocation                                   */
/*---------------------------------------------------------------------------*/
void heap_demo() {
    printf("\n=== HEAP ALLOCATION ===\n");
    
    /* Dynamic memory allocation - HEAP segment */
    int *heap_int = (int*)malloc(sizeof(int) * 10);     // Heap
    char *heap_str = (char*)malloc(100 * sizeof(char)); // Heap
    
    if (heap_int && heap_str) {
        printf("Heap int array address: %p\n", (void*)heap_int);
        printf("Heap string address:    %p\n", (void*)heap_str);
        
        /* Demonstrate heap growing upward */
        int *another_heap = (int*)malloc(sizeof(int) * 5);
        printf("Another heap allocation: %p\n", (void*)another_heap);
        
        /* Free heap memory - IMPORTANT! */
        free(heap_int);
        free(heap_str);
        free(another_heap);
    }
}

/*---------------------------------------------------------------------------*/
/* Function to print memory addresses of various segments                    */
/*---------------------------------------------------------------------------*/
void print_memory_layout() {
    printf("\n========================================\n");
    printf("      MEMORY LAYOUT ADDRESSES\n");
    printf("========================================\n");
    
    printf("\n1. TEXT/CODE SEGMENT:\n");
    printf("   Function address (print_memory_layout): %p\n", 
           (void*)print_memory_layout);
    printf("   Function address (main): %p\n", (void*)main);
    
    printf("\n2. DATA SEGMENT (initialized):\n");
    printf("   initialized_global:       %p\n", (void*)&initialized_global);
    printf("   initialized_static:       %p\n", (void*)&initialized_static);
    printf("   read_only_global:         %p\n", (void*)&read_only_global);
    printf("   string_literal pointer:   %p\n", (void*)&string_literal);
    printf("   String literal value:     %p\n", (void*)string_literal);
    
    printf("\n3. BSS SEGMENT (uninitialized):\n");
    printf("   uninitialized_global:     %p\n", (void*)&uninitialized_global);
    printf("   uninitialized_static:     %p\n", (void*)&uninitialized_static);
    printf("   buffer[1024]:             %p\n", (void*)buffer);
    
    printf("\n4. STACK SEGMENT:\n");
    int stack_variable = 999;
    printf("   Local stack variable:     %p\n", (void*)&stack_variable);
    
    printf("\n5. HEAP SEGMENT (will show during heap_demo)\n");
}

/*---------------------------------------------------------------------------*/
/* Demonstrating static variables inside functions                           */
/*---------------------------------------------------------------------------*/
void static_variable_demo() {
    static int function_static = 0;    // DATA segment (initialized)
    static int function_static_uninit; // BSS segment (uninitialized)
    
    function_static++;
    printf("\nStatic variable inside function: %d (address: %p)\n",
           function_static, (void*)&function_static);
}

/*---------------------------------------------------------------------------*/
/* Main function - Entry point                                               */
/*---------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {
    printf("========================================\n");
    printf("   PROGRAM MEMORY LAYOUT DEMONSTRATION\n");
    printf("========================================\n");
    
    /* Print command line arguments (stored above stack) */
    printf("\nCommand-line arguments:\n");
    printf("Address of argc: %p\n", (void*)&argc);
    printf("Address of argv: %p\n", (void*)&argv);
    for (int i = 0; i < argc; i++) {
        printf("  argv[%d] = %s (address: %p)\n", 
               i, argv[i], (void*)argv[i]);
    }
    
    /* Show all memory segments */
    print_memory_layout();
    
    /* Demonstrate stack growth */
    stack_demo(42, 'A');
    
    /* Demonstrate heap allocation */
    heap_demo();
    
    /* Demonstrate static variables */
    printf("\n=== STATIC VARIABLES ===\n");
    static_variable_demo();
    static_variable_demo();  // Value persists between calls
    static_variable_demo();
    
    /* Demonstrate memory layout with arrays */
    printf("\n=== ARRAY MEMORY LAYOUT ===\n");
    int local_array[5] = {1, 2, 3, 4, 5};  // Stack
    printf("Local array address: %p\n", (void*)local_array);
    for (int i = 0; i < 5; i++) {
        printf("  local_array[%d] = %d (address: %p)\n",
               i, local_array[i], (void*)&local_array[i]);
    }
    
    /* Show memory segment ordering */
    printf("\n========================================\n");
    printf("   MEMORY ORDER VERIFICATION\n");
    printf("========================================\n");
    printf("Observations:\n");
    printf("1. Text segment has LOWEST addresses\n");
    printf("2. Data/BSS have MIDDLE addresses\n");
    printf("3. Heap grows UPWARD from Data/BSS\n");
    printf("4. Stack grows DOWNWARD from top\n");
    printf("5. Addresses: Text < Data < BSS < Heap < Stack\n");
    
    return 0;
}

/*
 * ============================================================================
 * COMPILATION AND USAGE
 * ============================================================================
 * 
 * Compile:
 *   gcc -o memory_layout memory_layout.c
 * 
 * Run:
 *   ./memory_layout arg1 arg2 arg3
 * 
 * Expected Output:
 *   - Shows addresses in different memory segments
 *   - Demonstrates stack growth downward
 *   - Demonstrates heap growth upward
 *   - Shows static variable persistence
 * 
 * ============================================================================
 * KEY POINTS TO OBSERVE
 * ============================================================================
 * 
 * 1. TEXT SEGMENT:
 *    - Lowest addresses
 *    - Contains function code
 *    - Read-only
 * 
 * 2. DATA SEGMENT:
 *    - Initialized global/static variables
 *    - String literals
 *    - Read-write (except const)
 * 
 * 3. BSS SEGMENT:
 *    - Uninitialized global/static
 *    - All zeros initially
 *    - Adjacent to Data segment
 * 
 * 4. HEAP SEGMENT:
 *    - Dynamically allocated memory
 *    - Grows toward higher addresses
 *    - Manual management required
 * 
 * 5. STACK SEGMENT:
 *    - Highest addresses
 *    - Grows toward lower addresses
 *    - Automatic management
 *    - Contains function frames
 * 
 * 6. NOTE:
 *    - Exact addresses will vary between runs (ASLR)
 *    - Relative ordering remains consistent
 *    - Segment sizes are platform-dependent
 * 
 * ============================================================================
 * COMMON ERRORS AND WARNINGS
 * ============================================================================
 * 
 * Stack Overflow:
 *   - Caused by deep recursion
 *   - Large local arrays
 *   - Solution: Use heap allocation
 * 
 * Heap Fragmentation:
 *   - Many small allocations/deallocations
 *   - Solution: Use memory pools
 * 
 * Memory Leaks:
 *   - Forgetting to free heap memory
 *   - Solution: Always pair malloc with free
 * 
 * Use After Free:
 *   - Accessing freed memory
 *   - Solution: Set pointers to NULL after free
 */

/*
 * ============================================================================
 * ADDITIONAL CODE SNIPPETS FOR REFERENCE
 * ============================================================================
 */

/* Snippet 1: Checking segment sizes */
void check_segment_sizes() {
    /* Text/Data/BSS sizes can be checked with:
     *   size ./executable
     * 
     * Output format:
     *   text    data     bss     dec     hex filename
     */
}

/* Snippet 2: Environment variables location */
void show_environment() {
    extern char **environ;
    printf("\nEnvironment variables (above stack):\n");
    for (int i = 0; environ[i] != NULL && i < 3; i++) {
        printf("  %s\n", environ[i]);
    }
}

/* Snippet 3: Recursion showing stack growth */
void recursive_stack(int depth) {
    int local = depth;
    printf("Recursion depth %d: stack at %p\n", depth, (void*)&local);
    if (depth > 0) {
        recursive_stack(depth - 1);
    }
}

/* Snippet 4: Dynamic memory fragmentation demo */
void fragmentation_demo() {
    void* blocks[10];
    
    /* Allocate and free in pattern to cause fragmentation */
    for (int i = 0; i < 10; i++) {
        blocks[i] = malloc(16 + i * 8);
    }
    
    /* Free alternate blocks */
    for (int i = 0; i < 10; i += 2) {
        free(blocks[i]);
    }
    
    /* Now heap is fragmented */
}
