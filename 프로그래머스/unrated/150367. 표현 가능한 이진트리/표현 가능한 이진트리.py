import math


def is_tree(s,parent):
    if parent=='0':
        if not all(child=='0' for child in s):
            return False

    if len(s) == 1:
        return True
    center = len(s)//2
    return is_tree(s[:center],s[center]) and is_tree(s[center+1:],s[center])

def to_bin(num):
    s = bin(num)[2:]
    s_length = int(math.log2(len(s)))+1
    digit =  2**s_length-1
    return '0' * (digit - len(s))+s


def solution(numbers):
    answer = []
    for num in numbers:
        s = to_bin(num)
        if is_tree(s,s[len(s)//2]):
            answer.append(1)
        else:
            answer.append(0)

    return answer
