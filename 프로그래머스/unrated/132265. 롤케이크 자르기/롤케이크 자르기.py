from collections import Counter


def solution(topping):
    dic = Counter(topping)
    set_dic = set()
    res = 0
    for i in topping:
        dic[i] -= 1
        set_dic.add(i)
        if dic[i] == 0:
            dic.pop(i)
        if len(dic) == len(set_dic):
            res += 1
    return res

def solution2(edges):
    answer = 0
    prev_set = set({})
    post_set = set({})

    for i in range(0,len(edges)):
        post_set = set({})
        prev_set.add(edges[i])
        post_set = set(edges[i+1:])

        if len(prev_set)== len(post_set):
            answer+=1
        elif len(prev_set)>len(post_set):
            break
    return answer


def naive_solution(edges): 
    answer = 0

    for i in range(1,len(edges)-1):
        prev = edges[:i]
        post = edges[i:len(edges)]
        prev_cnt = Counter(prev)
        post_cnt = Counter(post)

        if len(prev_cnt)==len(post_cnt):
            answer+=1
    return answer
