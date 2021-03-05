#!/usr/bin/python3
"""Lockboxes.

Given a box full of boxes full of keys to open other boxes, determine if all
boxes can be opened.
"""


def canUnlockAll(boxes):
    """canUnlockAll.

    Determine if all boxes inside boxes can be opened.

    Arguments:
    -- boxes: A box full of boxes, which may contain keys.

    Return:
    True if all boxes can be opened; False otherwise.
    """
    keychain = set([])
    boxStack = []
    currentBox = boxes[0]
    key = None
    done = False

    if len(boxes) > 0:
        keychain.add(0)

    while(not done):
        if len(currentBox) > 0:
            key = currentBox.pop(0)
            if key not in keychain and key < len(boxes):
                keychain.add(key)
                boxStack.append(currentBox)
                currentBox = boxes[key]
        else:
            if len(boxStack) > 0:
                currentBox = boxStack.pop()
            else:
                done = True
    return len(keychain) == len(boxes)
