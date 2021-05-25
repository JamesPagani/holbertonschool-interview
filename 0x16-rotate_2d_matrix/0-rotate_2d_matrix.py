#!/usr/bin/python3
"""Rotate 2D Matrix.

Given an nxn 2D matrix, rotate it 90 degrees clockwise.
"""


def rotate_2d_matrix(matrix):
    """rotate_2d_matrix.

    Rotate a matrix to the right.

    Args:
    - matrix: A list of lists.
    """
    n = len(matrix)
    perim = 4 * (n - 1)

    for offset in range(0, n // 2):
        #print("Offset: {}".format(offset))
        #print("Perim: {}".format(perim))
        for shifts in range(0, perim + 1 - (n - 2 * offset)):
            #print("Shift no.: {}".format(shifts))
            i = 0 + offset
            j = 0 + offset
            while j < n - 1 - offset:
                matrix[i][j], matrix[i][j + 1] = matrix[i][j + 1], matrix[i][j]
                j += 1
            while i < n - 1 - offset:
                matrix[i][j], matrix[i + 1][j] = matrix[i + 1][j], matrix[i][j]
                i += 1
            while j > 0 + offset:
                matrix[i][j], matrix[i][j - 1] = matrix[i][j - 1], matrix[i][j]
                j -= 1
            while i > 1 + offset:
                matrix[i][j], matrix[i - 1][j] = matrix[i - 1][j], matrix[i][j]
                i -= 1
        perim -= 8
