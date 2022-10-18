import sys #for fast I/O
inp = sys.stdin.readline #for fast I/O
inf = int(9e9)
t = int(inp())
for i in range(t) :
    n = int(inp())
    rr = [-inf,-inf] #ed,cost
    ll = [inf,inf] #st,cost
    mxl = [-inf,-inf] #len,cost
    for j in range(n) : 
        a,b,c = [int(x) for x in inp().split()]
        rr = max(rr,[b,-c]) #max end point with min cost
        ll = min(ll,[a,c]) #min st with min cost
        mxl = max(mxl,[b-a+1,-c]) #max len min cost
        a1 = abs(rr[1]) + abs(ll[1])
        a2 = abs(mxl[1])
        if(mxl[0] == (rr[0] - ll[0] + 1)):
            print(min(a1,a2))
        else :
            print(a1) 



