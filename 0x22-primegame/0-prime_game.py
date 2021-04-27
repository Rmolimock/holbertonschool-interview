#!/usr/bin/python3
""" prime game """


def helper(nums):
    """ helper """
    num = max(nums)
    l = []
    for _ in range(max(num + 1, 2)):
        l.append(True)
    for i in range(2, int(pow(num, 0.5)) + 1):
        if l[i]:
            for k in range(i*i, num + 1, i):
                l[k] = False
        else:
            continue
    l[0], l[1] = False, False
    c = 0
    for k in range(len(l)):
        if l[k]:
            c += 1
        l[k] = c
    return l

def isWinner(x, nums):
    """ prime game """
    if not nums or x < 1:
        return None
    p1 = 0
    l = helper(nums)
    for num in nums:
        p1 += l[num] % 2 == 1
    if len(nums) == p1 * 2:
        return None
    if len(nums) < p1 * 2:
        return "Maria"
    return "Ben"
