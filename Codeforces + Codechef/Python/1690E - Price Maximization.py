import sys #for fast I/O
inp = sys.stdin.readline #for fast I/O

t = int(inp())
while t :
    n,k = [int(x) for x in inp().split()]
    a = [int(x) for x in inp().split()]
    s = 0
    for i in range(n) :
        s += int(a[i]/k)
        a[i] = a[i]%k
    a.sort(reverse = True)
    i = 0
    j = n-1
    #print(a)
    while i < j :
        if a[i] + a[j] >= k :
            s+=1
            i+=1
            j-=1
        else : 
            j-=1
    print(s)    
    t-=1