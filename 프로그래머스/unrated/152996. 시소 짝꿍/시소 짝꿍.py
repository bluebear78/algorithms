from itertools import product, combinations
from collections import defaultdict

def solution(weights):
    answer = 0
    info = defaultdict(int)
    for w in weights:
        answer += info[w] + info[w*2] + info[w/2] + info[(w*2)/3] + info[(w*3)/2] + info[(w*4)/3] + info[(w*3)/4]
        info[w] += 1
    return answer


def naive_solution(weights):
    answer = 0
    dist = [2,3,4]

    check_list = []

    dist_prod = list(product(dist,repeat=2))
    weight_comb = sorted(list(combinations(weights,2)))

    #print(dist_prod)
    #print(weight_comb)

    for w in weight_comb:
        for d in dist_prod:
            if w[0]*d[0] == w[1]*d[1]:
                answer+=1
                break


    return answer
    
    