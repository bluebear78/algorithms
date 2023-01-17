
def get_gradient(dots):
    p1 = dots[0]
    p2 = dots[1]
    return float(p2[1]-p1[1])/float(p2[0]-p1[0])

def is_parallel(dots_1,dots_2):
    if get_gradient(dots_1)==get_gradient(dots_2):
        return 1
    else:
        return 0


def solution(dots):
    answer = 0
    dots_list = [i for i in range(len(dots))]
    index = 0 
    
    for i in range(1,len(dots)):
        dots_1 = [dots[0]]
        dots_2 = []
        
        dots_1.append(dots[i])
        for k in range(0,len(dots)):
            if dots[k] not in dots_1:
                dots_2.append(dots[k])
        if(is_parallel(dots_1,dots_2)):
            return 1
    
    return 0