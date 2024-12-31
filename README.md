# Interview Preparation - Algorithms

## Overview
This repository contains algorithmic challenges and solutions designed to enhance problem-solving skills and prepare for technical interviews. The exercises focus on key concepts such as data structures, recursion, dynamic programming, graph algorithms, and more.

## Objective
The goal is to practice and master algorithms that are frequently encountered during coding interviews. These problems help improve logic, coding efficiency, and the ability to tackle complex problems within time constraints.

## Requirements
- **Environment**: Ubuntu 14.04 LTS (or later)
- **Interpreter**: Python 3.4.3 (or later)
- **Editors**: `vi`, `vim`, `emacs`
- **Code Style**: PEP 8 (version 1.7.x)
- **Execution**: All files must be executable.

## General Guidelines
- Each challenge must have a corresponding `README.md` file explaining the problem and solution approach.
- Solutions should be well-documented with clear and concise comments.
- Code must follow PEP 8 guidelines and pass basic test cases.
- Test files should be created to validate the functionality of each algorithm.

## Directory Structure
```
interview_prep/
│
├── algorithms/
│   ├── lockboxes/
│   │   ├── 0-lockboxes.py
│   │   └── README.md
│   ├── sorting/
│   │   ├── 0-quick_sort.py
│   │   └── README.md
│   └── dynamic_programming/
│       ├── 0-fibonacci.py
│       └── README.md
│
└── tests/
    ├── test_lockboxes.py
    ├── test_quick_sort.py
    └── test_fibonacci.py
```

## Examples of Challenges
- **Lockboxes**: Determine if all boxes can be opened with the keys inside.
- **Sorting**: Implement various sorting algorithms (QuickSort, MergeSort, etc.).
- **Dynamic Programming**: Solve Fibonacci sequence problems using memoization and tabulation.
- **Graph Algorithms**: Implement BFS, DFS, and shortest path algorithms.

## Usage
To run the solutions, navigate to the desired directory and execute the Python script:
```bash
$ python3 0-lockboxes.py
```

## Testing
Test cases are provided in the `tests/` directory to validate the solutions. Run tests using:
```bash
$ python3 -m unittest tests/test_lockboxes.py
```

## Author
**Erwan Lebreton** - Software Engineer in Training at Holberton School

## Repository
- **GitHub**: [holbertonschool-interview](https://github.com/Erwan2072/holbertonschool-interview)

## Contributions
Contributions are welcome! Feel free to fork the repository and submit pull requests with new challenges or improvements to existing solutions.
