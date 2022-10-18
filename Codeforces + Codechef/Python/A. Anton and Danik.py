import sys
inp = sys.stdin.readline #for fast I/O

n = int(inp())
s = inp()
fa = 0
fd = 0
for i in range(n) :
    if s[i] == 'A' :
        fa += 1
    else :
        s[i] == 'B'
        fd += 1

if fa == fd :
    print("Friendship")
elif fa > fd : 
    print("Anton")
else :
    print("Danik")
