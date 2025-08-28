
# C Notes

## Basics & Fundamentals

### **1. What is C?**

C is a **procedural**, **compiled**, general-purpose programming language developed in the early 1970s by Dennis Ritchie at Bell Labs. It's known for its efficiency, flexibility, and low-level memory access capabilities.

### **2. Why is C called a "middle-level" language?**

C is considered middle-level because it bridges the gap between low-level (like Assembly) and high-level (like Python or Java) languages. It provides high-level abstractions like functions and data types while also allowing direct memory manipulation through pointers, which is a low-level feature.

### **3. What is the difference between a compiler and an interpreter?**

A **compiler** (which C uses) translates the entire source code into machine code (an executable file) in one go. You then run the resulting executable file. An **interpreter** reads the source code line by line, translating and executing it on the fly.

- **Compiler:** Scans the whole program first, then executes. Faster execution.
- **Interpreter:** Executes line-by-line. Slower execution, but easier for debugging.

### **4. What are the basic data types in C?**

The primary data types are:

- `int`: For integer values (e.g., 10, -50).
- `char`: For single characters (e.g., 'a', 'Z').
- `float`: For single-precision floating-point numbers (e.g., 3.14).
- `double`: For double-precision floating-point numbers (more precise than `float`).
- `void`: Represents the absence of a type, primarily used for functions that don't return a value or for generic pointers.

These can be modified with qualifiers like `short`, `long`, `signed`, and `unsigned`.

### **5. What is the purpose of the `main()` function?**

The `main()` function is the **entry point** of every C program. When you run a C program, the operating system starts execution from the first line of code inside the `main()` function.

### **6. What is the difference between `#include <stdio.h>` and `#include "myheader.h"`?**

- `#include <stdio.h>`: Angle brackets tell the preprocessor to search for the header file in the **system directories** (standard library locations).
- `#include "myheader.h"`: Quotation marks tell the preprocessor to search for the header file in the **current directory first**, then in system directories if not found.

### **7. What are keywords in C? Can you name some?**

Keywords are **reserved words** that have special meaning in C and cannot be used as variable names or identifiers. Examples include: `int`, `char`, `if`, `else`, `while`, `for`, `return`, `struct`, `union`, `typedef`, `static`, `extern`, `const`, `volatile`, `sizeof`, `break`, `continue`, `switch`, `case`, `default`.

### **8. What is the difference between `=` and `==` in C?**

- `=`: **Assignment operator** - assigns a value to a variable (`x = 5;`).
- `==`: **Equality operator** - compares two values for equality and returns true (1) or false (0) (`if (x == 5)`).

---

## Control Flow

### **9. What is the difference between a `while` loop and a `do-while` loop?**

The key difference is when the condition is checked.

- A **`while` loop** is an **entry-controlled loop**. It checks the condition _before_ executing the loop body. If the condition is false initially, the loop will never execute.
- A **`do-while` loop** is an **exit-controlled loop**. It executes the loop body _at least once_ and then checks the condition at the end.

### **10. When should you use a `switch` statement instead of an `if-else if` ladder?**

You should use a `switch` statement when you are comparing a **single variable** against a list of discrete **constant integer or character values**. It can be more readable and sometimes more efficient than a long chain of `if-else if` statements. An `if-else if` ladder is more flexible and can handle complex conditions, ranges, and non-constant expressions.

### **11. What do the `break` and `continue` keywords do?**

- **`break`**: Immediately terminates the innermost loop (`for`, `while`, `do-while`) or a `switch` statement it is in. Execution continues at the statement immediately following the loop or switch.
- **`continue`**: Skips the remaining code inside the current iteration of a loop and proceeds to the next iteration.

### **12. What is the difference between `++i` and `i++`?**

Both increment the value of `i` by 1, but they differ in when the increment happens:

- `++i` (pre-increment): Increments `i` **first**, then returns the new value.
- `i++` (post-increment): Returns the current value of `i` **first**, then increments it.

In standalone statements, there's no difference. The difference matters when used in expressions: `x = ++i;` assigns the incremented value, while `x = i++;` assigns the original value.

### **13. What is the ternary operator in C?**

The ternary operator (`? :`) is a **conditional operator** that provides a shorthand way to write simple `if-else` statements.

Syntax: `condition ? expression1 : expression2`

If the condition is true, `expression1` is evaluated and returned; otherwise, `expression2` is evaluated and returned.

Example: `max = (a > b) ? a : b;`

### **14. What is the difference between `goto` and function calls?**

- `goto`: An **unconditional jump** statement that transfers control to a labeled statement within the same function. It's generally discouraged as it can make code difficult to read and debug.
- **Function calls**: Transfer control to a separate function, which can be in the same file or a different file. They provide better code organization, reusability, and maintainability.

---

## Functions

### **15. What's the difference between a function declaration and a function definition?**

- **Declaration (or Prototype)**: Tells the compiler about a function's name, return type, and the types of its parameters. It's like a function's signature. Example: `int add(int a, int b);`.
- **Definition**: Provides the actual body of the function, i.e., the code that will be executed when the function is called.

### **16. Explain "pass by value" and "pass by reference." Which method does C use?**

C is strictly **pass by value**. This means that when you pass an argument to a function, a _copy_ of the argument's value is made and sent to the function. Any changes the function makes to this copy do not affect the original variable in the calling function.

To simulate **pass by reference**, you pass the **address** of a variable (i.e., a pointer) to the function. This allows the function to modify the original variable's value by dereferencing the pointer.

### **17. What is function overloading? Does C support it?**

Function overloading is the ability to define multiple functions with the same name but different parameter lists (different number or types of parameters). **C does not support function overloading** - each function must have a unique name. Languages like C++ support function overloading.

### **18. What is recursion? What are its advantages and disadvantages?**

Recursion is a programming technique where a function calls itself to solve a problem by breaking it down into smaller, similar subproblems.

**Advantages:**

- Elegant and simple code for problems that have recursive structure (like factorial, Fibonacci)
- Natural fit for tree and graph traversals

**Disadvantages:**

- Can lead to stack overflow for deep recursions
- Generally slower than iterative solutions due to function call overhead
- Uses more memory due to function call stack

### **19. What is the difference between actual parameters and formal parameters?**

- **Formal parameters**: Variables declared in the function definition. They are placeholders that receive values when the function is called.
- **Actual parameters (arguments)**: The real values or expressions passed to a function when it is called.

Example: In `int add(int a, int b)` - `a` and `b` are formal parameters. In `result = add(5, 10);` - `5` and `10` are actual parameters.

---

## Arrays & Strings

### **20. What is an array?**

An array is a collection of a fixed number of elements of the **same data type** stored in **contiguous memory locations**. Elements are accessed using an index, starting from 0.

### **21. How are strings handled in C?**

In C, a string is a **one-dimensional array of characters** that is terminated by a special character called the **null character (`\0`)**. All standard library string functions (like `strlen()`, `strcpy()`) rely on this null terminator to know where the string ends.

### **22. What is the difference between `strlen()` and `sizeof()` for a character array?**

- **`strlen()`**: A library function from `<string.h>` that returns the **number of characters** in a string, _not_ including the null terminator (`\0`).
- **`sizeof()`**: A compile-time operator that returns the **total memory size** allocated to the array in bytes, which _includes_ the space for the null terminator and any other unused space in the array.

### **23. What is the difference between `char str[] = "Hello";` and `char *str = "Hello";`?**

- `char str[] = "Hello";`: Creates a **character array** in memory and copies the string "Hello" into it. The string is modifiable, and `str` is the name of the array (not a pointer variable).
- `char *str = "Hello";`: Creates a **pointer** that points to a string literal stored in the program's read-only memory section. Attempting to modify this string leads to undefined behavior.

### **24. How do you find the length of an array in C?**

C doesn't store array length information. For static arrays declared in the same scope, you can use: `int length = sizeof(array) / sizeof(array[0]);`. However, this doesn't work for arrays passed to functions (they decay to pointers). The common practice is to pass the array size as a separate parameter to functions.

- `sizeof(array)` → total bytes used by the array.
- `sizeof(array)/sizeof(array[0])` → number of elements in the array.
- Examples:

```c
char c[20];
double d[20];

printf("%zu\n", sizeof(c));  // 20  (1 byte each)
printf("%zu\n", sizeof(d));  // 160 (8 bytes each)

// But number of elements:
printf("%zu\n", sizeof(c) / sizeof(c[0])); // 20
printf("%zu\n", sizeof(d) / sizeof(d[0])); // 20

```

### **25. What are multidimensional arrays? How are they stored in memory?**

Multidimensional arrays are arrays of arrays. A 2D array like `int arr[3][4]` can be visualized as a table with 3 rows and 4 columns. In memory, multidimensional arrays are stored in **row-major order** - all elements of the first row, then all elements of the second row, and so on.

### **26. What is array decay in C?**

Array decay refers to the **implicit conversion** of an array to a pointer to its first element when the array is used in most expressions. When you pass an array to a function, what actually gets passed is a pointer to the first element, not the entire array. This is why `sizeof()` doesn't work as expected for arrays inside functions.

---

## Pointers

### **27. What is a pointer?**

A pointer is a special variable that stores the **memory address** of another variable. It "points" to the location where data is stored rather than storing the data itself.

### **28. Why are pointers used in C?**

Pointers are one of C's most powerful features. They are used for:

- **Dynamic memory allocation** (allocating memory on the heap).
- **Efficiently passing large data structures** to functions (to avoid copying).
- Simulating pass by reference.
- Creating complex data structures like linked lists, trees, and graphs.
- Directly interacting with hardware memory addresses.

### **29. What is a `NULL` pointer?**

A `NULL` pointer is a pointer that does not point to any valid memory address. It's a special value (`0`) used to indicate that a pointer is intentionally empty. It's good practice to initialize pointers to `NULL` to prevent them from pointing to random memory locations.

### **30. What is a dangling pointer?**

A dangling pointer is a pointer that points to a memory location that has already been **deallocated or freed**. Accessing a dangling pointer leads to undefined behavior and can cause your program to crash. This often happens if you `free()` memory but don't set the pointer back to `NULL`.

### **31. What is pointer arithmetic?**

Pointer arithmetic involves performing arithmetic operations (addition, subtraction, increment, decrement) on pointers. When you add 1 to a pointer, it doesn't add 1 byte - it adds the size of the data type it points to. For example, if `int *p` points to an integer, `p + 1` points to the next integer (4 bytes ahead on most systems).

### **32. What is the difference between `*p++`, `(*p)++`, and `++*p`?**

- `*p++`: Due to operator precedence, this is equivalent to `*(p++)`. It dereferences the current pointer value, then increments the pointer (not the value).
- `(*p)++`: Dereferences the pointer first, then increments the value it points to.
- `++*p`: Equivalent to `++(*p)`. Increments the value that the pointer points to.

### **33. What is a wild pointer?**

A wild pointer is an uninitialized pointer that contains a random memory address. Using a wild pointer can lead to unpredictable behavior because it might point to any location in memory. Always initialize pointers before using them.

---

## Memory Management

### **34. What is the difference between the stack and the heap?**

- **Stack**: A region of memory where local variables and function call information are stored. Memory is managed automatically by the compiler (LIFO - Last In, First Out). It's fast but has a limited, fixed size.

- **Heap**: A region of memory used for **dynamic memory allocation**. The programmer is responsible for manually allocating (`malloc`, `calloc`) and deallocating (`free`) memory. It's larger and more flexible than the stack but slightly slower to access.

### **35. What is the difference between `malloc()` and `calloc()`?**

Both functions allocate memory on the heap.

- `void* malloc(size_t size)`: Allocates a single, contiguous block of memory of the specified size. The allocated memory is **not initialized**; it contains garbage values.

- `void* calloc(size_t num, size_t size)`: Allocates memory for an array of `num` elements, each of size `size`. The allocated memory is **initialized to zero**.

### **36. What is the purpose of the `free()` function?**

The `free()` function deallocates memory that was previously allocated using `malloc()`, `calloc()`, or `realloc()`. It returns the memory block back to the heap so it can be reused. Failing to call `free()` leads to **memory leaks**.

### **37. What is `realloc()` and when is it used?**

`void* realloc(void* ptr, size_t new_size)` changes the size of a previously allocated memory block. It can:

- Expand the existing block if there's adjacent free space
- Allocate a new block, copy the data, and free the old block if expansion isn't possible
- Free the memory if `new_size` is 0
- Act like `malloc()` if `ptr` is `NULL`

### **38. What are memory leaks and how can they be prevented?**

Memory leaks occur when dynamically allocated memory is not freed, causing the program to gradually consume more memory over time. Prevention strategies:

- Always pair `malloc()/calloc()` with `free()`
- Set pointers to `NULL` after freeing them
- Use tools like Valgrind to detect memory leaks
- Follow consistent memory management patterns

### **39. What is segmentation fault?**

A segmentation fault (segfault) occurs when a program tries to access memory that it's not allowed to access, such as:

- Dereferencing `NULL` or uninitialized pointers
- Accessing memory outside array bounds
- Accessing freed memory
- Writing to read-only memory
This results in the operating system terminating the program.

---

## Structures & Unions

### **40. What is the difference between a `struct` and a `union`?**

This is a classic C question. 💡

- **`struct` (Structure)**: A user-defined data type that groups related variables of different data types. Memory is allocated for **all** its members, and the size of the struct is the sum (or more, due to padding) of the sizes of its members.

- **`union` (Union)**: A user-defined data type where all members share the **same memory location**. Memory is allocated for the **largest member** only. You can only use one member of the union at a time.

Analogy: A `struct` is a toolbox with different compartments for each tool. A `union` is a single compartment where you can only place one tool at a time.

### **41. What is `typedef` and why is it used?**

`typedef` is a keyword used to create **aliases** (alternative names) for existing data types. It makes code more readable and portable.

Example: `typedef unsigned int uint;` allows you to use `uint` instead of `unsigned int`.

Common use with structures: `typedef struct { int x, y; } Point;` allows you to declare variables as `Point p;` instead of `struct Point p;`.

### **42. What is structure padding and alignment?**

Structure padding is the insertion of unused bytes between structure members to ensure proper memory alignment. Most processors access data more efficiently when it's aligned to specific byte boundaries (usually multiples of the data type's size). The compiler automatically adds padding to achieve this alignment, which is why `sizeof(struct)` might be larger than the sum of its members' sizes.

### **43. Can you have a structure within a structure?**

Yes, C supports **nested structures**. You can declare a structure as a member of another structure. This is useful for organizing related data hierarchically.

```c
struct Address {
    char street[50];
    char city[30];
};

struct Person {
    char name[30];
    struct Address addr;  // Nested structure
    int age;
};
```

### **44. What is a bit field in C?**

A bit field allows you to specify the exact number of bits a structure member should occupy. This is useful for memory optimization when you need to store small integer values.

```c
struct Flags {
    unsigned int flag1 : 1;  // 1 bit
    unsigned int flag2 : 2;  // 2 bits  
    unsigned int flag3 : 5;  // 5 bits
};
```

---

## Miscellaneous Intermediate Concepts

### **45. What does the `static` keyword do?**

The `static` keyword has two main uses depending on its context:

1. **Inside a function**: A `static` local variable retains its value between function calls. It is initialized only once.

2. **Outside a function (at the global level)**: A `static` global variable or function is only visible within the file it is declared in. This is called **internal linkage**.

### **46. What is the purpose of the `volatile` keyword?**

The `volatile` keyword tells the compiler that a variable's value may be changed at any time by something outside of the program's control (e.g., the operating system, hardware, or another thread). This prevents the compiler from applying optimizations that might assume the variable's value is constant.

### **47. What are preprocessor directives?**

Preprocessor directives are commands that are processed by the C preprocessor **before** the actual compilation begins. They start with a `#` symbol. Common examples include:

- `#include`: To include the contents of another file (like a header file).
- `#define`: To create macros (symbolic constants or function-like macros).
- `#if, #else, #endif`: For conditional compilation.

### **48. What is the difference between a macro and a function?**

- **Macro (`#define`)**: A preprocessor directive that performs simple text substitution before compilation. It's faster as there is no function call overhead, but it has no type checking and can lead to unexpected side effects if not written carefully.
- **Function**: A compiled block of code. It involves a function call overhead (pushing/popping from the stack), but it is type-safe and generally easier to debug.

### **49. What are command line arguments in C?**

Command line arguments allow you to pass information to your program when it's executed. The `main()` function can accept two parameters:

- `int argc`: The number of command line arguments (including the program name)
- `char *argv[]`: An array of strings containing the arguments

Example: `int main(int argc, char *argv[])`

### **50. What is the difference between local and global variables?**

- **Local variables**: Declared inside a function or block. They have limited scope (visible only within that function/block) and automatic storage duration (destroyed when the function ends).
- **Global variables**: Declared outside all functions. They have file scope (visible throughout the file) and static storage duration (exist for the entire program execution).

### **51. What are header guards and why are they important?**

Header guards prevent the same header file from being included multiple times in the same compilation unit, which would cause redefinition errors. They are implemented using preprocessor directives:

```c
#ifndef MYHEADER_H
#define MYHEADER_H
// Header content here
#endif
```

Alternatively, many compilers support `#pragma once` as a simpler solution.

---

## File I/O In-Depth

### **52. What are the different file opening modes in C?**

When using `fopen()`, you can specify a mode to determine how the file will be accessed:

- `"r"`: **Read** - Opens an existing text file for reading. Fails if the file doesn't exist.
- `"w"`: **Write** - Creates a text file for writing. If the file exists, its contents are erased.
- `"a"`: **Append** - Opens a text file for writing at the end. Creates the file if it doesn't exist.
- `"r+"`: Opens a text file for both **reading and writing**.
- `"w+"`: Creates a text file for both **reading and writing**. Erases existing content.
- `"a+"`: Opens a text file for both **reading and appending**.

You can also add a `b` to any mode (e.g., `"rb"`, `"wb"`) to open the file in **binary mode**, which prevents any translation of special characters like newline sequences.

### **53. What do the `fseek()` and `ftell()` functions do?**

These functions are used for random file access.

- `int fseek(FILE *stream, long offset, int whence)`: Sets the file position indicator for the given stream.
  - `stream`: The file pointer.
  - `offset`: The number of bytes to move from the `whence` position.  
  - `whence`: The starting position (`SEEK_SET` for the beginning, `SEEK_CUR` for the current position, `SEEK_END` for the end of the file).

- `long ftell(FILE *stream)`: Returns the current value of the file position indicator for the given stream. This tells you how many bytes you are from the beginning of the file.

### **54. What is the difference between `fgetc()` and `getchar()`?**

- `int fgetc(FILE *stream)`: Reads a single character from the specified file stream.
- `int getchar()`: Reads a single character from the standard input (stdin). It's equivalent to `fgetc(stdin)`.

Both return the character as an `int` (not `char`) to accommodate the `EOF` value.

### **55. What is the difference between text mode and binary mode in file I/O?**

- **Text mode**: The default mode where the system may perform character translations (like converting `\n` to `\r\n` on Windows). Used for human-readable text files.
- **Binary mode**: No character translations are performed. The data is read/written exactly as it appears in memory. Essential for non-text files like images, executables, or when you need exact byte-for-byte copying.

### **56. What are the advantages of using `fprintf()` over `printf()`?**

`fprintf()` allows you to specify the output stream, making it more flexible:

- You can write to files using file pointers
- You can write to `stderr` for error messages
- `printf()` is essentially `fprintf(stdout, ...)`
- Better for logging and debugging when you need output to go to different destinations

---

## Pointers (Advanced Topics)

### **57. What is a pointer to a pointer (double pointer)?**

A pointer to a pointer is a variable that stores the memory address of another pointer. It is used in scenarios where you need to change the address stored in a pointer from within a function. A common use case is dynamically allocating a 2D array.

`int **ptr;` declares a pointer `ptr` that can hold the address of a pointer to an `int`.

### **58. What is a function pointer?**

A function pointer is a pointer that stores the memory address of a function. This allows you to treat functions like variables—you can pass them to other functions, store them in arrays, and call them indirectly through the pointer. They are essential for implementing callback mechanisms and plugins.

Declaration: `return_type (*pointer_name)(parameter_types);`

Example: `void (*my_func_ptr)(int);`

### **59. What is a `void` pointer?**

A `void` pointer is a generic pointer that can point to a variable of **any data type**. It is also known as a generic pointer. Because the compiler doesn't know what type of object it points to, you cannot directly dereference a `void` pointer. You must first **cast** it to a specific pointer type (e.g., `int*`, `char*`) before dereferencing it. Functions like `malloc()` return a `void` pointer.

### **60. What is the difference between array and pointer?**

While arrays and pointers are closely related in C, they are not identical:

**Arrays:**

- Represent a fixed-size collection of elements
- Array name is a constant pointer to the first element
- `sizeof(array)` gives the total size of the array
- Cannot be reassigned

**Pointers:**

- Variables that store memory addresses
- Can be reassigned to point to different locations
- `sizeof(pointer)` gives the size of the pointer itself (usually 4 or 8 bytes)
- Can perform pointer arithmetic

### **61. What is pointer to constant vs constant pointer?**

- **Pointer to constant** (`const int *ptr`): The value being pointed to cannot be changed through this pointer, but the pointer itself can be changed to point elsewhere.
- **Constant pointer** (`int * const ptr`): The pointer cannot be changed to point elsewhere, but the value it points to can be modified.
- **Constant pointer to constant** (`const int * const ptr`): Neither the pointer nor the value it points to can be changed.

---

## Data Structures & Memory

### **62. What is a self-referential structure?**

A self-referential structure is a structure that contains a member which is a **pointer to another structure of the same type**. This is the fundamental building block for creating dynamic data structures like linked lists, trees, and graphs.

```c
struct Node {
    int data;
    struct Node* next; // Pointer to another struct of type Node
};
```

### **63. What is memory padding in a structure?**

Memory padding is the practice of adding empty bytes between members of a structure to ensure that each member is aligned on a memory address that is a multiple of its size. This is done by the compiler to improve the CPU's performance when accessing the members, as many CPUs can read data more efficiently from aligned addresses. Because of padding, `sizeof(struct)` may be greater than the sum of the sizes of its individual members.

### **64. What is the difference between a shallow copy and a deep copy?**

This concept is crucial when dealing with structures containing pointers.

- **Shallow Copy**: Copies the values of the members directly. If a member is a pointer, it copies the **address**, not the data being pointed to. Both the original and the copy will point to the same memory location, which can lead to errors (e.g., freeing the same memory twice).

- **Deep Copy**: Copies the values of the members, but if a member is a pointer, it allocates **new memory** and copies the data from the original pointer's location to the new memory location. This ensures the original and the copy are completely independent.

### **65. What is memory fragmentation?**

Memory fragmentation occurs when free memory is broken into small, non-contiguous blocks, making it difficult to allocate large blocks even when total free memory is sufficient. There are two types:

- **External fragmentation**: Free memory exists but is scattered in small chunks
- **Internal fragmentation**: Allocated memory blocks contain unused space due to allocation policies

### **66. What is the difference between stack overflow and buffer overflow?**

- **Stack overflow**: Occurs when the call stack exceeds its maximum size, typically due to infinite recursion or very deep function calls.
- **Buffer overflow**: Occurs when data is written beyond the boundaries of a buffer, potentially overwriting adjacent memory. This is a serious security vulnerability.

---

## Bitwise Operations & Compilation

### **67. What are bitwise operators in C?**

Bitwise operators perform operations on the individual bits of integer-type operands.

- `&` (Bitwise AND): Sets a bit to 1 if both corresponding bits are 1.
- `|` (Bitwise OR): Sets a bit to 1 if at least one of the corresponding bits is 1.
- `^` (Bitwise XOR): Sets a bit to 1 if the corresponding bits are different.
- `~` (Bitwise NOT): Inverts all the bits.
- `<<` (Left Shift): Shifts bits to the left, filling with zeros (equivalent to multiplication by 2).
- `>>` (Right Shift): Shifts bits to the right (equivalent to division by 2).

### **68. What are the stages of the C compilation process? ⚙️**

A C program goes through four main stages to become an executable:

1. **Preprocessing**: The preprocessor handles directives like `#include`, `#define`, and removes comments. The output is a `.i` file.
2. **Compilation**: The compiler translates the preprocessed code into assembly language specific to the target processor. The output is a `.s` file.
3. **Assembly**: The assembler converts the assembly code into machine code (object code). The output is a `.o` or `.obj` file.
4. **Linking**: The linker combines the object code from your program with code from libraries (like the standard library) to resolve references and create the final executable file.

### **69. How do you check if a number is even or odd using bitwise operators?**

You can use the bitwise AND operator with 1:

- `if (n & 1)` - the number is odd
- `if (!(n & 1))` - the number is even

This works because the least significant bit of any odd number is 1, and for even numbers it's 0.

### **70. How can you swap two variables without using a third variable?**

Using bitwise XOR:

```c
a = a ^ b;
b = a ^ b;  // b = (a ^ b) ^ b = a
a = a ^ b;  // a = (a ^ b) ^ a = b
```

Or using arithmetic (be careful of overflow):

```c
a = a + b;
b = a - b;  // b = (a + b) - b = a
a = a - b;  // a = (a + b) - a = b
```

---

## Storage Classes & Type System

### **71. What are storage classes in C?**

Storage classes define the **scope** (visibility) and **lifetime** (duration) of variables and functions. There are four storage classes:

- `auto`: The default for local variables. They exist only within the block they are declared in.
- `extern`: Used to declare a global variable or function that is defined in another file. It extends the visibility of the variable/function.
- `static`: As explained before, it gives a local variable a permanent lifetime or limits the scope of a global variable/function to the current file.
- `register`: A hint to the compiler to store the variable in a CPU register instead of memory for faster access. The compiler can ignore this hint.

### **72. What is the difference between `const int* p`, `int const* p`, `int* const p`, and `const int* const p`?**

This is a classic pointer declaration question. Read the declaration from **right to left**.

- `const int* p` or `int const* p`: This is a **pointer to a constant integer**. You cannot change the value of the integer `p` points to (`*p = 10;` is illegal), but you can change the pointer itself (`p = &another_var;` is legal).
- `int* const p`: This is a **constant pointer to an integer**. You cannot change the pointer itself (`p = &another_var;` is illegal), but you can change the value it points to (`*p = 10;` is legal).
- `const int* const p`: This is a **constant pointer to a constant integer**. You can change neither the pointer nor the value it points to.

### **73. What is typecasting?**

Typecasting is the explicit conversion of a variable from one data type to another. For example, you can cast a float to an int to truncate the decimal part.

Syntax: `(target_type) expression;`

Example: `int x = (int)3.14;` // x will be 3

This is different from implicit type promotion, where the compiler automatically converts a smaller type to a larger type in an expression to avoid data loss (e.g., int to float).

### **74. What is the difference between signed and unsigned data types?**

- **Signed**: Can represent both positive and negative numbers. The most significant bit is used as a sign bit (0 for positive, 1 for negative).
- **Unsigned**: Can only represent non-negative numbers (0 and positive). All bits are used for the magnitude, allowing for a larger positive range.

For example, `signed char` ranges from -128 to 127, while `unsigned char` ranges from 0 to 255.

### **75. What is type promotion in C?**

Type promotion is the automatic conversion of smaller integer types to larger types during arithmetic operations. For example:

- `char` and `short` are promoted to `int` in expressions
- If one operand is `float`, the other is converted to `float`
- If one operand is `double`, the other is converted to `double`

This ensures precision is maintained during calculations.

### **76. What is the `size_t` data type?**

`size_t` is an unsigned integer type defined in `<stddef.h>` that represents the size of objects in bytes. It's the return type of the `sizeof` operator and is used for array indexing and loop counting. Its actual size depends on the platform (32-bit or 64-bit).

---

## Advanced C Concepts

### **77. What are enumeration types (`enum`) in C?**

An enumeration is a user-defined data type that consists of a set of named integer constants. It makes code more readable by giving meaningful names to integer values.

```c
enum Color {
    RED,     // 0
    GREEN,   // 1
    BLUE     // 2
};
```

You can also assign specific values: `enum Status { FAILURE = -1, SUCCESS = 1 };`

### **78. What is the difference between `#define` and `enum`?**

- `#define`: Creates simple text substitutions at preprocessing time. No type checking, no scope.
- `enum`: Creates actual integer constants with type checking and proper scope. Preferred for related constants.

### **79. What are variadic functions in C?**

Variadic functions can accept a variable number of arguments. They use the ellipsis (`...`) notation and require the `<stdarg.h>` header for implementation.

```c
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}
```

`printf()` is a famous example of a variadic function.

### **80. What is the difference between `exit()` and `return` in the `main()` function?**

- `return`: Normal termination from `main()`. Returns control to the calling environment and passes the return value as the exit status.
- `exit()`: Immediately terminates the program from anywhere in the code. Calls cleanup functions registered with `atexit()` before termination.

Both set the program's exit status, but `exit()` can be called from any function.

### **81. What are inline functions and why are they used?**

Inline functions (using the `inline` keyword) suggest to the compiler to replace function calls with the actual function code at compile time. This eliminates function call overhead but may increase code size. The compiler may ignore the inline suggestion for complex functions.

```c
inline int square(int x) {
    return x * x;
}
```

### **82. What is the difference between `puts()` and `printf()`?**

- `puts()`: Outputs a string followed by a newline character. Simpler and faster for plain string output.
- `printf()`: Formatted output function that can handle various data types and format specifiers. More versatile but has more overhead.

### **83. What are the different ways to initialize an array?**

```c
// Method 1: Initialize with values
int arr1[5] = {1, 2, 3, 4, 5};

// Method 2: Partial initialization (rest filled with 0)
int arr2[5] = {1, 2};

// Method 3: Size determined by initializer
int arr3[] = {1, 2, 3, 4, 5};

// Method 4: Initialize all elements to 0
int arr4[5] = {0};

// Method 5: Designated initializers (C99)
int arr5[5] = {[0] = 1, [4] = 5};
```

### **84. What is the difference between `#include` and forward declaration?**

- `#include`: Physically inserts the entire contents of another file, including all its definitions and declarations.
- **Forward declaration**: Tells the compiler about the existence of a function or structure without providing its complete definition. Used to resolve circular dependencies and reduce compilation time.

```c
// Forward declaration
struct Node;
void process(struct Node* n);

// vs including a header file
#include "node.h"
```

---

## Error Handling & Debugging

### **85. How do you handle errors in C?**

C doesn't have built-in exception handling. Common error handling techniques include:

- **Return codes**: Functions return specific values to indicate success or failure
- **Global `errno` variable**: Set by system calls to indicate error types
- **Assertions**: Using `assert()` macro for debugging
- **Defensive programming**: Checking parameters and return values

```c
FILE *fp = fopen("file.txt", "r");
if (fp == NULL) {
    perror("Error opening file");
    return -1;
}
```

### **86. What is the `errno` variable?**

`errno` is a global variable defined in `<errno.h>` that stores error codes set by system calls and library functions. You can use `perror()` or `strerror()` to get human-readable error messages.

```c
#include <errno.h>
#include <string.h>

if (some_function() == -1) {
    printf("Error: %s\n", strerror(errno));
}
```

### **87. What are assertions in C?**

Assertions are debugging aids that check assumptions in your code. The `assert()` macro from `<assert.h>` terminates the program if the given expression is false. Assertions can be disabled by defining `NDEBUG` before including `assert.h`.

```c
#include <assert.h>

int divide(int a, int b) {
    assert(b != 0);  // Program terminates if b is 0
    return a / b;
}
```

### **88. What are common debugging techniques in C?**

- **Print statements**: Adding `printf()` statements to trace execution
- **Debuggers**: Using tools like GDB to step through code
- **Static analysis**: Tools that analyze code without executing it
- **Memory checkers**: Tools like Valgrind to detect memory errors
- **Assertions**: Checking assumptions during development
- **Logging**: Systematic recording of program execution

---

## Standard Library Functions

### **89. What is the difference between `strcpy()` and `strncpy()`?**

- `strcpy(dest, src)`: Copies the entire source string to destination. Unsafe because it doesn't check buffer bounds.
- `strncpy(dest, src, n)`: Copies at most `n` characters. Safer but doesn't guarantee null termination if the source is longer than `n`.

For safety, always use `strncpy()` and manually add null termination:

```c
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
```

### **90. What is the difference between `strcmp()` and `strncmp()`?**

- `strcmp(str1, str2)`: Compares two entire strings lexicographically. Returns 0 if equal, negative if str1 < str2, positive if str1 > str2.
- `strncmp(str1, str2, n)`: Compares at most the first `n` characters of two strings.

### **91. What are the memory functions in C?**

- `memcpy(dest, src, n)`: Copies `n` bytes from source to destination (no overlap allowed)
- `memmove(dest, src, n)`: Like `memcpy()` but handles overlapping memory regions
- `memset(ptr, value, n)`: Sets `n` bytes of memory to a specific value
- `memcmp(ptr1, ptr2, n)`: Compares `n` bytes of two memory areas

### **92. What is the difference between `getchar()` and `getch()`?**

- `getchar()`: Standard C function from `<stdio.h>`. Reads from stdin, echoes the character, and waits for Enter key.
- `getch()`: Non-standard function (common in older compilers like Turbo C). Reads a single character without echoing and without waiting for Enter.

Note: `getch()` is not part of standard C and is not portable.

---

## Best Practices & Common Mistakes

### **93. What are some common programming mistakes in C?**

- **Buffer overflows**: Writing beyond array bounds
- **Memory leaks**: Not freeing dynamically allocated memory
- **Dangling pointers**: Using pointers after freeing memory
- **Uninitialized variables**: Using variables before setting their values
- **Integer overflow**: Arithmetic operations exceeding data type limits
- **Off-by-one errors**: Incorrect loop boundaries or array indexing
- **Format string vulnerabilities**: Using user input directly in printf format strings

### **94. What are some C programming best practices?**

- Always initialize variables before use
- Check return values of functions
- Use `const` for values that shouldn't change
- Prefer `strncpy()` over `strcpy()` for safety
- Free all dynamically allocated memory
- Use meaningful variable and function names
- Comment your code appropriately
- Avoid global variables when possible
- Use static functions for file-local functions
- Validate input parameters in functions

### **95. How do you prevent buffer overflow in C?**

- Use safe string functions (`strncpy()`, `strncat()`, `snprintf()`)
- Always check array bounds
- Use dynamic memory allocation with proper size calculation
- Validate input lengths before processing
- Use tools like static analyzers and runtime checkers
- Consider using safer alternatives or libraries

### **96. What is defensive programming?**

Defensive programming is a practice of writing code that continues to function properly even when used incorrectly or in unexpected ways. Techniques include:

- Input validation
- Null pointer checks
- Error handling for all possible failure cases
- Assertions for debugging
- Clear error messages
- Graceful degradation when errors occur

```c
int divide(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        return -1;  // Or some error code
    }
    return a / b;
}
```

---

## Platform-Specific & Advanced Topics

### **97. What is endianness and why is it important?**

Endianness refers to the order in which bytes are stored in memory for multi-byte data types:

- **Big-endian**: Most significant byte first (network byte order)
- **Little-endian**: Least significant byte first (common in x86 systems)

This matters when:

- Reading binary files created on different systems
- Network programming
- Embedded systems programming

### **98. What are pragma directives?**

`#pragma` directives provide compiler-specific instructions. Common examples:

- `#pragma once`: Prevents multiple inclusions of a header file
- `#pragma pack(n)`: Controls structure padding alignment
- `#pragma warning(disable:xxxx)`: Disables specific compiler warnings

```c
#pragma pack(1)  // No padding
struct PackedStruct {
    char c;
    int i;
};
#pragma pack()   // Restore default padding
```

### **99. What is the difference between a library and a framework?**

- **Library**: A collection of functions and utilities that your code calls. You are in control of the program flow. Examples: C standard library, math library.
- **Framework**: A structure that calls your code. The framework controls the program flow, and you fill in the details. Less common in C compared to higher-level languages.

### **100. What are some popular C libraries and their uses?**

- **Standard C Library (`libc`)**: Basic functions (stdio, stdlib, string, math)
- **POSIX libraries**: System calls and utilities for Unix-like systems
- **OpenSSL**: Cryptography and SSL/TLS
- **SQLite**: Embedded database
- **cURL**: HTTP client library
- **GTK**: GUI toolkit
- **SDL**: Game development and multimedia
- **ncurses**: Terminal-based user interfaces

### **101. What is the difference between compilation and linking?**

- **Compilation**: Translates source code (.c files) into object code (.o files). Each source file is compiled independently.
- **Linking**: Combines object files and libraries into a final executable. Resolves external references and addresses.

### **102. What are external linkage and internal linkage?**

- **External linkage**: Variables and functions can be accessed from other source files. This is the default for global variables and functions.
- **Internal linkage**: Variables and functions are only accessible within the current source file. Achieved using the `static` keyword.

### **103. What is the volatile keyword used for in embedded systems?**

In embedded systems, `volatile` is crucial for:

- Memory-mapped hardware registers that can change independently
- Variables modified by interrupt service routines
- Variables shared between threads
- Preventing compiler optimizations that assume values don't change

### **104. How do you implement a generic function in C?**

C doesn't have built-in generics, but you can simulate them using:

1. **Void pointers with function pointers**:

    ```c
    void sort_array(void* arr, size_t count, size_t size, 
                    int (*compare)(const void*, const void*));
    ```

2. **Macros**:

    ```c
    #define MAX(a,b) ((a) > (b) ? (a) : (b))
    ```

3. **C11 _Generic keyword** (limited support):

    ```c
    #define ABS(x) _Generic((x), \
        int: abs, \
        float: fabsf, \
        double: fabs \
    )(x)
    ```

### **105. What are the key differences between C90, C99, C11, and C18 standards?**

- **C90/C89**: Original ANSI C standard
- **C99**: Added features like:
  - Variable-length arrays
  - `inline` functions  
  - `//` comments
  - New data types (`long long`, `_Bool`)
  - Designated initializers

- **C11**: Added:
  - Multi-threading support
  - `_Generic` selections
  - Anonymous structures and unions
  - Static assertions (`_Static_assert`)

- **C18**: Minor revision with bug fixes and clarifications, no new features
