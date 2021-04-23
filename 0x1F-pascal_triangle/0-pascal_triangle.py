#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """ Pascal’s triangle of n """
    triangle = []
    for i in range(1, n+1):
        line = []
        for k in range(i):
            if k == i-1 or k == 0:
                n = 1
                line.append(n)
            else:
                n = triangle[i-2][k-1] + triangle[i-2][k]
                line.append(n)
        triangle.append(line)
    return triangle