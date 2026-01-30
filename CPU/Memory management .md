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
