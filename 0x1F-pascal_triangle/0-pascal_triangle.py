#!/usr/bin/python3
"""Pascal Triangle.

Answer file for Algorithm Project 0x1F.
"""


def pascal_triangle(n):
    """pascal_triangle.

    Return a pascal tirangle of depth n.

    Args:
        n: Depth of the Pascal triangle.

    Return: List of lists of integers representing the Pascal triangle.
    """
    pascal = []

    for i in range(0, n):
        pascal.append([])
        for j in range(0, i + 1):
            if j == 0 or j == i:
                pascal[i].append(1)
            else:
                pascal[i].append(pascal[i - 1][j] + pascal[i - 1][j - 1])
    return pascal
