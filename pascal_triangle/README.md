## Tasks

### 15.

Create a function `def pascal_triangle(n):` that returns a list of lists of integers representing the Pascal’s triangle of `n`:

*   Returns an empty list if `n <= 0`
*   You can assume `n` will be always an integer
```
guillaume@ubuntu:~/$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
pascal\_triangle = \_\_import\_\_('0-pascal\_triangle').pascal\_triangle

def print\_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("\[{}\]".format(",".join(\[str(x) for x in row\])))

if \_\_name\_\_ == "\_\_main\_\_":
    print\_triangle(pascal\_triangle(5))

guillaume@ubuntu:~/$
guillaume@ubuntu:~/$ ./0-main.py
\[1\]
\[1,1\]
\[1,2,1\]
\[1,3,3,1\]
\[1,4,6,4,1\]
guillaume@ubuntu:~/$
```