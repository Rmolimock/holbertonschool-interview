#!/usr/bin/python3
"""
rotate matrix counter clockwise
"""

matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

def rotate_2d_matrix(mat): 
    N = len(mat)
    for x in range(0, int(N / 2)): 
          
        for y in range(x, N-x-1): 
              
            temp = mat[x][y] 
  
            mat[x][y] = mat[y][N-1-x] 
  
            mat[y][N-1-x] = mat[N-1-x][N-1-y] 
  
            mat[N-1-x][N-1-y] = mat[N-1-y][x] 
  
            mat[N-1-y][x] = temp 
  
 