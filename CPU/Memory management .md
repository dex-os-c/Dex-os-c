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

Contains machine code
Read-only → prevents self-modifying code
Data
Global / static variables with initial values
BSS
Global / static variables without initialization
Initialized to 0 automatically
Heap
Dynamic memory (malloc, free)
Manual control → powerful but dangerous
Stack
Local variables
Function calls
Return addresses
Fast, automatic, limited size
