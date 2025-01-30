# Sandpiles

## Description
This project implements a function that computes the sum of two sandpiles. A sandpile is represented as a 3x3 grid, and a stable sandpile is one where no cell contains more than 3 grains of sand. The function will continue toppling unstable sandpiles until a stable state is reached.

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- Compiled on `Ubuntu 14.04 LTS`
- Compilation command: `gcc 4.8.4 -Wall -Werror -Wextra -pedantic`
- Code must follow the `Betty` style guidelines
- No global variables allowed
- Maximum of `5` functions per file
- A `sandpiles.h` header file must be used
- No dynamic memory allocation

## Prototype
```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

## Usage Example
### Input
```
grid1 =
3 3 3
3 3 3
3 3 3

grid2 =
1 3 1
3 3 3
1 3 1
```
### Output
```
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```
