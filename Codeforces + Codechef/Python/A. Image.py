import sys #for fast I/O
inp = sys.stdin.readline #for fast I/O

t = int(inp())
while t :
    s1 = inp()
    s2 = inp()
    z = set()
    z.add(s1[0])
    z.add(s1[1])
    z.add(s2[0])
    z.add(s2[1])
    if len(z) == 1 : 
        print(0)
    elif len(z) == 2:
        print(1)
    elif len(z)  == 3:
        print(2)
    else :
        print(3)
    t-=1
