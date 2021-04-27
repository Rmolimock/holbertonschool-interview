#!/usr/bin/python3
""" island perimiter algo """


def island_perimeter(grid):
    """ island perimiter algo """
    sm, high = (0, 0)
    grid_len = (len(grid))
    col_len = len(grid[0])
    for c in range(grid_len):
        sm += sum(grid[c])
        for r in range(col_len):
            if grid[c][r]:
                if grid[c - 1][r] == 1 and c > 0:
                    high += 1
                if grid[c][r - 1] == 1 and r > 0:
                    high += 1
    sm = sm * 4
    high = high * 2
    return sm - high
