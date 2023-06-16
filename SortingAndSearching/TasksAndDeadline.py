n = int(input())
v = []
sum = 0
for i in range (0,n):
    x,y = input().split()
    x = int(x)
    y = int(y)
    v.append(x)
    sum += y
v.sort()
ans = sum
lsum = 0
for i in v:
    ans = (ans-i-lsum)
    lsum += i
print(ans)