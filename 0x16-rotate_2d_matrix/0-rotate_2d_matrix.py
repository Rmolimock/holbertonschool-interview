#!/usr/bin/python3
"""
rotate a 2d matrix algorithm
"""


def rotate_2d_matrix(matrix):
    """
    rotate a 2d matrix algorithm
    """
    if not len(matrix) == len(matrix[0]) or not len(matrix):
        return
    size = len(matrix)
    for y in range(size // 2):
        x, end, k = y, size - 1 - y, 0
        for i in range(x, end):
            save = matrix[x][i]
            matrix[x][i] = matrix[end - k][x]
            matrix[end - k][x] = matrix[end][end - k]
            matrix[end][end - k] = matrix[i][end]
            matrix[i][end] = save
            k += 1
