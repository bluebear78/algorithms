
def solution(storey):
    answer = 0
    res = int(storey)
    while res:
        temp = res%10
        next = (res//10)%10

        if temp>=6:
            answer += 10 - temp
            res+=10
        elif temp == 5:
            answer+=5
            if next>=5:
                res+=10
        else:
            answer += temp
        res = res//10

    return answer
