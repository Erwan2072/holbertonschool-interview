#!/usr/bin/python3
import sys

def is_safe(queens, row, col):
    for r in range(row):
        c = queens[r]
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True

def solve_nqueens(n, row=0, queens=[], solutions=[]):
    if row == n:
        solutions.append([[i, queens[i]] for i in range(n)])
        return

    for col in range(n):
        if is_safe(queens, row, col):
            queens.append(col)
            solve_nqueens(n, row + 1, queens, solutions)
            queens.pop()

def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    solve_nqueens(n, 0, [], solutions)

    for solution in solutions:
        print(solution)

if __name__ == "__main__":
    main()
