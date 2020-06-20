#!/usr/bin/python3
"""
position queens so they're not attacking each other
for given board size
"""
from sys import argv, exit


def create_board(board, col):
    """ place queens so long as not attacking """
    board_len = len(board)
    if col is board_len:
        print(str([[c, board[c]] for c in range(board_len)]))
        return
    for row in range(board_len):
        if not attacking(board, row, col):
            board[col] = row
            create_board(board, col + 1)


def attacking(board, row, col):
    """ verify they're not able to attack """
    for c in range(col):
        if abs(board[c] - row) is abs(c - col) or board[c] is row:
            return True
    return False


if __name__ == "__main__":
    """ entry point """
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    size = 0
    try:
        size = int(argv[1])
    except Exception:
        print("N must be a number")
        exit(1)
    if size < 4:
        print("N must be at least 4")
        exit(1)
    board = [0 for x in range(size)]
    create_board(board, 0)
