from collections import deque

def solution(queue1, queue2):
    answer = 0
    queue1 = deque(queue1)
    queue2 = deque(queue2)

    maximium = len(queue1)+len(queue2)
    while True:
        sum_1 = sum(queue1)
        sum_2 = sum(queue2)

        if answer>maximium:
            return -1

        if sum_1 == sum_2:
            break
        elif sum_1 < sum_2:
            temp = queue2.popleft()
            queue1.append(temp)
        else:
            temp = queue1.popleft()
            queue2.append(temp)
        answer+=1



        

    return answer
