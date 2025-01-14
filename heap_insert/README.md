# Binary Trees and Max Binary Heap

This project involves working with binary trees and implementing a Max Binary Heap. It focuses on creating and manipulating binary tree nodes while adhering to specific constraints.

---

## Table of Contents

- [General Requirements](#general-requirements)
- [Data Structures](#data-structures)
- [Tasks](#tasks)
  - [Task 0: New Node](#task-0-new-node)
  - [Task 1: Heap Insert](#task-1-heap-insert)
- [Compilation and Testing](#compilation-and-testing)
- [Usage](#usage)
- [License](#license)

---

## General Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All code will be compiled on **Ubuntu 14.04 LTS** using `gcc` 4.8.4 with flags `-Wall -Werror -Wextra -pedantic`.
- All files must end with a new line.
- Code must adhere to the **Betty style guide**.
- No global variables allowed.
- A maximum of **5 functions per file**.
- The standard library is allowed.
- Prototypes of all functions should be included in `binary_trees.h`.
- Header files should be include-guarded.

---

## Data Structures

The following structure is used to represent nodes in the binary tree:

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
```

---

## Tasks

### Task 0: New Node

Write a function that creates a binary tree node.

#### Prototype
```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

#### Description
- `parent`: Pointer to the parent node of the node to create.
- `value`: Value to store in the new node.
- A new node does not have any children initially.

#### Return
- Pointer to the newly created node, or `NULL` on failure.

---

### Task 1: Heap Insert

Write a function to insert a value into a **Max Binary Heap**.

#### Prototype
```c
heap_t *heap_insert(heap_t **root, int value);
```

#### Description
- `root`: Double pointer to the root node of the heap.
- `value`: Value to insert into the heap.

#### Rules
- If `root` is `NULL`, the created node becomes the root node.
- Respect Max Binary Heap properties (parent ≥ child).

#### Return
- Pointer to the inserted node, or `NULL` on failure.

---

## Compilation and Testing

### Compilation

Compile the project using the following command:
```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-heap_insert.c 0-binary_tree_node.c -o 1-heap_insert
```

### Testing
Run the compiled programs:
```bash
./0-node
./1-heap_insert
```

Compare outputs with the provided examples.

---

## Usage

Include the header file `binary_trees.h` in your source files:

```c
#include "binary_trees.h"
```

### Example

Creating a binary tree node:
```c
binary_tree_t *root;
root = binary_tree_node(NULL, 98);
root->left = binary_tree_node(root, 12);
```

Inserting values into a Max Binary Heap:
```c
heap_t *root = NULL;
heap_insert(&root, 98);
heap_insert(&root, 402);
```

---

## License

This project is part of the Holberton School curriculum and is provided for educational purposes.

