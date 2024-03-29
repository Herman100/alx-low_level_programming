#!/usr/bin/python3
"""
This module contains a function that calculates the perimeter of an island
represented in a grid.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid.
    :param grid: list of list of integers where
    0 represents water and 1 represents land
    :return: perimeter of the island
    """
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                if row == 0 or grid[row-1][col] == 0:
                    perimeter += 1
                if row == rows-1 or grid[row+1][col] == 0:
                    perimeter += 1
                if col == 0 or grid[row][col-1] == 0:
                    perimeter += 1
                if col == cols-1 or grid[row][col+1] == 0:
                    perimeter += 1

    return perimeter
