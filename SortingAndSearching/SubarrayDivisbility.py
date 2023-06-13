#t = int(input())
t = 1
while(t):
    n = int(input())
    v = list(map(int, input().split()))
    d = {}
    d[0] = 1
    sum = 0
    ans = 0
    for i in v:
        sum = (i+i%n+n)%n
        if((sum) in d):
            ans += d[sum]
        if(sum not in d): d[sum] = 1
        else: d[sum] += 1
    print(ans)
    t = t-1