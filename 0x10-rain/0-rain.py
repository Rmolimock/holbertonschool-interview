#!/usr/bin/python3
""" rain algorithm """


def rain(walls):
    """ rain algorithm """
    if not walls:
        return 0
    if not isinstance(walls, list):
        return 0
    if len(walls) == 0:
        return 0
    left, right, water, space = 0, 0, 0, False
    for wall in walls:
        if wall and not left:
            left = wall
            space = False
        elif wall and left:
            if space:
                right = wall
                water += left if left < right else right
            left = wall
            space = False
        else:
            space = True
    return water
