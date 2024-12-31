#!/usr/bin/python3
"""
Module to determine if all lockboxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    :param boxes: List of lists containing keys.
    :return: True if all boxes can be opened, False otherwise.
    """
    n = len(boxes)
    unlocked = [False] * n
    unlocked[0] = True  # The first box is unlocked by default
    keys = [0]  # Start with keys from box 0

    while keys:
        current_box = keys.pop()
        for key in boxes[current_box]:
            if 0 <= key < n and not unlocked[key]:
                unlocked[key] = True
                keys.append(key)

    return all(unlocked)
