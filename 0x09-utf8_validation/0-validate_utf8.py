#!/usr/bin/python3


def validUTF8(data):
    '''
    Check if data is UTF-8 encoded
    '''

    num_bytes = 0
    for each in data:
        mask = 1 << 7
        if not num_bytes:
            while mask & each:
                num_bytes += 1
                mask >>= 1
            if not num_bytes:
                continue
            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            if each >> 6 != 0b10:
                return False
        num_bytes -= 1
    if num_bytes == 0:
        return True
    else:
        return False
