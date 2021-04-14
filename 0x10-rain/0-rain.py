#!/usr/bin/python3


def rain(walls):
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
        if walls[i] >= walls[highIdx]:
            h = walls[highIdx] if walls[highIdx] <= walls[i] else walls[i]
            w = abs(i - highIdx - 1)
            if (w * h) - occupiedSpaces > waterRetained:
                waterRetained += (w * h) - occupiedSpaces
            occupiedSpaces = 0
            highIdx = i
        occupiedSpaces += walls[i]

    if highIdx != wallIdx:
        h = walls[wallIdx]
        w = abs(i - highIdx - 1)
        if (w * h) - occupiedSpaces > waterRetained:
            waterRetained += (w * h) - ocupiedSpaces

    return waterRetained
