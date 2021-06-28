<h1 align="center">Double Circular Linked List</h1>
<p align="center">26th project of the Interview Preparation projects</p>

## The challenge
Create a file that can perform the following operations on a *Double **Circular** Linked List*:
- Add a new node at **the beginning** of the list.
- Add a new node at **the end** of the list.

### Functions
- `List *add_node_end(List **list, char *str)`
  - Adds a new node at the end of a linked list of type `List`
    - `list`: The list to modify.
    - `str`: String to copy into the new node.
    - *Returns*: Address of the new node on success, `NULL` on failure.
- `List *add_node_begin(List **list, char *str)`
  - Adds a new node at the beginning of a linked list of type `List`
    - `list`: The list to modify.
    - `str`: String to copy into the new node.
    - *Returns*: Address of the new node on success, `NULL` on failure.

## Running the file
This project was made on a (virtual) machine running on **Ubuntu 14.04 LTS**, but it should have no problems running on any recent Linux OS, **as long as it can compile the code with *gcc***.

### Compilation
1. Copy `0-add_node.c` and `list.h`.
2. Create a file that ends with `.c` (for this document, the name will be `main.c`).
3. In `main.c`, include `list.h`:
```c
#include "list.h"
```
4. Add nodes using either `add_node_end` or `add_node_begin`.
5. Compile with the following command:
```c
gcc -Wall -Wextra -Werror -pedantic main.c 0-add_node.c -o [OUTPUT NAME HERE]
# Default output name is a.out
```
6. Run the binary
```bash
./[OUTPUT NAME HERE]
```

***

## Contact info
***Jaime Andrés Gálvez Villamarin***
- Twitter: [@JaimeAndresGlve1](https://twitter.com/JaimeAndrsGlve1)
- LinkedIn: [Jaime Andrés Gálvez Villamarin](https://www.linkedin.com/in/jaime-andr%C3%A9s-g%C3%A1lvez-villamarin-434472192/)
