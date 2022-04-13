from collections import defaultdict

def solution(id_list, report, k):
    answer = []

    be_reported = defaultdict(set)
    to_reported = defaultdict(set)
    report = set(report)

    for r in report:
        to_report,be_report = r.split(' ')

        be_reported[be_report].add(to_report)
        to_reported[to_report].add(be_report)

    for _id in id_list:
        cnt = 0
        for to_report in to_reported[_id]:
            if (len(be_reported[to_report])>=k):
                cnt+=1
        answer.append(cnt)
    return answer


id_list = ["muzi", "frodo", "apeach", "neo"]
report = ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]
k = 2

print(solution(id_list,report,k))


