import sys
inp = sys.stdin.readline #for fast I/O
t = int(inp())
while t :
    n,m,sx,sy,d = [int(x) for x in inp().split()]
    left = sy-d-1
    down = sx+d+1
    up = sx-d-1
    right = sy+d+1
    ans = 0
    if (left >= 1 and down <= n) or (up>=1 and right <= m) :
        ans = n+m-2
    else : 
        ans = -1
    print(ans)
    t-=1