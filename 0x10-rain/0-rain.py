#!/usr/bin/python3
""" rain algorithm """


def rain(walls):
    """ rain algorithm """
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
            
#        print("after", left, right, space)
