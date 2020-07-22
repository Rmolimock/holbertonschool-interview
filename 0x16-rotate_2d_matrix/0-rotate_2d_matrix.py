#!/usr/bin/python3
"""
rotate matrix counter clockwise
"""


def rotate_2d_matrix(matrix):
    """
    rotate matrix counter clockwise
    """
    if not len(matrix) or len(matrix) != len(matrix[0]):
        return
    n = len(matrix)
    for y in range(n // 2):
        x, end, offset = y, n - 1 - y, 0
        for i in range(x, end):
            tmp = matrix[x][i]
            matrix[x][i] = matrix[end - offset][x]
            matrix[end - offset][x] = matrix[end][end - offset]
            matrix[end][end - offset] = matrix[i][end]
            matrix[i][end] = tmp
            offset += 1
