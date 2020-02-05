#!/usr/bin/python3
'''
This is the lockboxes algorithm, first try.
'''


def canUnlockAll(boxes):
    '''return true if all boxes in list can be opened'''
    if not type(boxes) is list:
        return False
    if len(boxes) == 0:
        return True
    if not type(boxes[0]) is list:
        return False
    keys = [0]
    for key in keys:
        if len(keys) == len(boxes):
            return True
        for each in boxes[key]:
            if each not in keys and each < len(boxes):
                keys.append(each)
    return False
