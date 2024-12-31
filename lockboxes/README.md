# Lockboxes

## Description
The **Lockboxes** project aims to determine if all boxes can be opened using keys found within the boxes themselves. Each box is sequentially numbered and may contain keys to other boxes.

## Objective
You must implement a method that determines if all boxes can be opened.

## Technical Details
- **Prototype**: `def canUnlockAll(boxes)`
- `boxes` is a list of lists.
- A key with the same number as a box opens that box.
- You can assume all keys are positive integers.
- There may be keys that do not correspond to any box.
- The first box `boxes[0]` is unlocked.
- Returns **True** if all boxes can be opened, otherwise returns **False**.

## Requirements
- **Environment**: Ubuntu 14.04 LTS
- **Interpreter**: Python 3.4.3
- **Code Style**: PEP 8 (version 1.7.x)
- **Allowed Editors**: `vi`, `vim`, `emacs`
- Each file must end with a new line.
- The first line of all files must be `#!/usr/bin/python3`.
- All files must be executable.
- A `README.md` file is mandatory at the root of the project.

## Files
- **0-lockboxes.py**: Contains the main method `canUnlockAll`.
- **main_0.py**: Test script to verify the implementation.

## Usage
```bash
$ ./main_0.py
True
True
False
```

## Test Examples
```python
#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))  # False
```

## Author
**Carrie Ybay** - Software Engineer at Holberton School
[Erwan Lebreton](https://github.com/Erwan2072/holbertonschool-interview/tree/main/lockboxes) student Holberton School Laval

## Repository
- **GitHub repository**: `holbertonschool-interview`
- **Directory**: `lockboxes`
- **File**: `0-lockboxes.py`