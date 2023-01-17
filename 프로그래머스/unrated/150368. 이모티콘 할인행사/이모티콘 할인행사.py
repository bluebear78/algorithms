from itertools import product

def solution(users, emoticons):
    answer = []
    num_people = len(users)

    num_emo = len(emoticons)
    sales = [40,30,20,10]
    max_join = 0
    max_profit = 0
    for sale in product(sales,repeat=num_emo):
        join = 0
        total_profit = 0
        for user in users:
            profit = 0 #이 사람이 구매한 총 구매액
            for e in range(num_emo):
                if sale[e]>=user[0]: # 만약 할인율이 설정한 값보다 크면 구매
                    profit += emoticons[e] * ((100-sale[e]) / 100) #이 사람이 구매한 액수
            if profit>=user[1]:#만약 가격의 상한선을 넘으면
                join+=1 #그냥 가입하자
                profit = 0 #구매는 취소
            total_profit+=profit
        if max_join < join: #가입자수가 늘었다면 바로 변경
            max_join = join
            max_profit = total_profit
        elif max_join==join:#가입자 수가 같으면 최대 매출액으로 변경
            if max_profit < total_profit:
                max_profit = total_profit

    return [max_join,int(max_profit)]