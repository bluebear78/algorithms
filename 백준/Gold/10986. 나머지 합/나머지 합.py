_,M = list(map(int,input().split(' ')))
arr = list(map(int,input().split(' ')))

arr = [0] + arr
cand_list = [0 for _ in range(M+1)]

for i in range(1,len(arr)):
    arr[i] = (arr[i]+arr[i-1])%M
    cand_list[arr[i]]+=1
res = 0

res+=cand_list[0]

for i in range(M):
    x = cand_list[i]
    res += x*(x-1)//2

print(res)


