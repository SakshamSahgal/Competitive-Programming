import sys #for fast I/O
inp = sys.stdin.readline #for fast I/O
t = int(inp())
while t :
    n = int(inp())
    a = [ int(i) for i in inp().split()]
    for i in range(0,n,3) :
       if(i+1 < n) :
        a[i+1] = 2*a[i]
       if(i+2 < n) :
        if(i+3 < n) :
            a[i+2] = 2*a[i+3]
        else:
            a[i+2] = a[i+1] 
    
    for i in range(n) :
        print(a[i],end=" ")
    print()
    t-=1