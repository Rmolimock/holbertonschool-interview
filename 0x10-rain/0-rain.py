#!/usr/bin/python3
""" rain algorithm """


def rain(walls):
    """ rain algorithm """
    left = right = water = 0
    i, end = 0, len(walls) - 1
    while i < end:
        if walls[end] < walls[i]:
            if walls[end] > right:
                right = walls[end]
            else:
                water += right - walls[end]
            end -= 1
        else:
            if left > walls[i]:
                water += left - walls[i]
            else:
                left = walls[i]
            i += 1
    return water