#!/usr/bin/python3
"""0x1C - Island Perimeter."""


def island_perimeter(grid):
    """island_perimeter.

    Calculate the perimeter of an island.

    Args:
        - grid: A list of lists of ones (land) and zeroes (water)

    Return:
        An integer representing the perimeter of the island.
    """
    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                # North
                if i - 1 >= 0:
                    perimeter += 1 if grid[i - 1][j] == 0 else 0
                else:
                    perimeter += 1
                # East
                if j + 1 < len(grid[i]):
                    perimeter += 1 if grid[i][j + 1] == 0 else 0
                else:
                    perimeter += 1
                # South
                if i + 1 < len(grid):
                    perimeter += 1 if grid[i + 1][j] == 0 else 0
                else:
                    perimeter += 1
                # West
                if j - 1 >= 0:
                    perimeter += 1 if grid[i][j - 1] == 0 else 0
                else:
                    perimeter += 1

    return perimeter
