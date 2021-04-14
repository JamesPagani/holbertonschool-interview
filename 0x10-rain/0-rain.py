#!/usr/bin/python3
"""Rain.

Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""


def rain(walls):
    """Calculate the amount of water retained after it rains."""
    highIdx = 0
    wallIdx = 0
    occupiedSpaces = 0
    waterRetained = 0

    if len(walls) < 3:
        return 0

    while walls[highIdx] < 1 and highIdx < len(walls):
        highIdx += 1

    wallIdx = highIdx
    for i in range(highIdx + 1, len(walls)):
        if walls[i] > 0:
            h = walls[wallIdx] if walls[wallIdx] <= walls[i] else walls[i]
            w = abs(i - wallIdx - 1)
            waterRetained += w * h
            occupiedSpaces += (w * h)
            wallIdx = i
        occupiedSpaces += walls[i]
        if walls[i] >= walls[highIdx]:
            occupiedSpaces -= walls[i]
            h = walls[highIdx] if walls[highIdx] <= walls[i] else walls[i]
            w = abs(i - highIdx - 1)
            if (w * h) - occupiedSpaces > 0:
                waterRetained += (w * h) - occupiedSpaces
            occupiedSpaces = 0
            highIdx = i

    # When no other higher wall is found
    if highIdx != wallIdx:
        occupiedSpaces -= walls[wallIdx]
        h = walls[wallIdx]
        w = abs(wallIdx - highIdx - 1)
        if (w * h) - occupiedSpaces > 0:
            waterRetained += (w * h) - ocupiedSpaces

    return waterRetained
