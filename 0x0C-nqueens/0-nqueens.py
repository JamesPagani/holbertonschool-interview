#!/usr/bin/python3

"""N Queens.

The N Queens puzzle is the challenge of placing N non-attacking queens on
an NxN chessboard. This file contains all required functions to solve this
puzzle, given N as a parameter.
"""

import sys


def nonAttackCheck(n, queen, board):
    """Detect if there is any queen capable of attacking another one

    Args:
        n (int): Size of the board nxn
        queen (int): Queen in the board to evaluate
        board (list): The chess board with the coordinates of other Queens

    Returns:
        bool: True if no queen can attack this one, False otherwise
    """

    testQueen = board[queen]
    qRow = testQueen[0]
    qCol = testQueen[1]
    # print(testQueen)
    # Horizontal and vertical check
    for otherQueen in board:
        if testQueen is not otherQueen:
            if qRow == otherQueen[0] or qCol == otherQueen[1]:
                return False

    # Diagonal Check
    # Up Left
    cCordinates = [qRow - 1, qCol - 1]
    while cCordinates[0] >= 0 and cCordinates[1] >= 0:
        if cCordinates in board:
            return False
        cCordinates[0] -= 1
        cCordinates[1] -= 1
    # Up Right
    cCordinates = [qRow - 1, qCol + 1]
    while cCordinates[0] >= 0 and cCordinates[1] < n:
        if cCordinates in board:
            return False
        cCordinates[0] -= 1
        cCordinates[1] += 1
    # Down Left
    cCordinates = [qRow + 1, qCol - 1]
    while cCordinates[0] < n and cCordinates[1] >= 0:
        if cCordinates in board:
            return False
        cCordinates[0] += 1
        cCordinates[1] -= 1
    # Down Right
    cCordinates = [qRow + 1, qCol + 1]
    while cCordinates[0] < n and cCordinates[1] < n:
        if cCordinates in board:
            return False
        cCordinates[0] += 1
        cCordinates[1] += 1

    # print("Passed the test")
    return True


def nqueens(n, board=[]):
    """Print all posible solutions to the N Queens puzzle

    Args:
        n (int): Amount of Queens to place, as well as the size of the board
        board (list): The chess board with the coordinates of other Queens
            (default is [])

    Returns:
        Nothing
    """

    if len(board) == n:
        print(board)
        return

    partialBoard = board.copy()
    row = len(board)
    partialBoard.append([row, 0])
    for col in range(0, n):
        partialBoard[row] = [row, col]
        # print(partialBoard)
        if nonAttackCheck(n, row, partialBoard):
            nqueens(n, partialBoard)

    return


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
        if n < 4:
            print("N must be at least 4")
            exit(1)
        nqueens(n)
    except ValueError:
        print("N must be a number")
        exit(1)
