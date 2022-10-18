n,m = [int(x) for x in input().split()]
print(min(n,m) + 1)

if n <= m : 
    for i in range(n,-1,-1):
        print(i , n-i)
else : 
    for i in range(m,-1,-1):
        print(m-i , i)
