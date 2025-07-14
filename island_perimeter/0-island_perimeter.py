#!/usr/bin/python3
"""
0-island_perimeter
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid
    """
    if not grid or not grid[0]:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                # Assume 4 sides to start with
                perimeter += 4

                # Check for adjacent land cells to subtract shared edges
                if row > 0 and grid[row - 1][col] == 1:  # Up
                    perimeter -= 2
                if col > 0 and grid[row][col - 1] == 1:  # Left
                    perimeter -= 2

    return perimeter
