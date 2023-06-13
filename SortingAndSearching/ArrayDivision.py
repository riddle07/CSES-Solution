#t = int(input())
t = 1
while(t):
    nn = list(map(int, input().split()))
    n = nn[0]
    k = nn[1]
    v = list(map(int, input().split()))
    ans = int(1e18)
    l = 0
    h = int(1e18)
    while(l<=h):
        m = l + int((h-l)/2)
        c = 0
        crt = 0
        for i in v:
            if(crt+i>m):
                crt = i
                c = c+1
            else: crt += i
        if(c+1==k):
            ans = m
            h = m-1
        elif(c<k):
            h = m-1
        else: l = m+1
    print(ans)
    t = t-1
