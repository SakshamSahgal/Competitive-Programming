t=int(input())
painting=[]
flag=[1]
def isSafe(i,j,rm,cm):
    if i<0 or j<0 or i>=rm or j>=cm:
        return 0
    elif painting[i][j]=="#" or painting [i][j]=='-1':
        return 0
    return 1
def func(r,c,rm,cm):
    count=0
    safe=[]
    ans=isSafe(r+1,c,rm,cm)
    if ans:
        count+=1
        safe=[r+1,c]
    ans=isSafe(r-1,c,rm,cm)
    if ans:
        count+=1
        safe=[r-1,c]
    ans=isSafe(r,c+1,rm,cm)
    if ans:
        count+=1
        safe=[r,c+1]
    ans=isSafe(r,c-1,rm,cm)
    if ans:
        count+=1
        safe=[r,c-1]
    if count==1 and painting[r][c]=='^':
        flag[0]=0
        print("flagged")
        return
    if count==1:
        painting[r][c]='-1'
        print(safe)
        func(safe[0],safe[1],rm,cm)
for i in range(t):
    print("Case #"+str(i))
    r,c=map(int,input().split())
    painting=[]
    flag[0]=1
    for asdaw in range(r):
        painting.append(list(input()))
    for row in range(r):
        for column in range(c):
            if flag:
                func(row,column,r,c)
            else:
                break
    print (flag)
    if flag[0]==1:
        for row in range(r):
            for column in range(c):
                if painting[row][column]=='.' or painting[row][column]=='^':
                    print('^',end='')
                elif painting[row][column]=='-1':
                    print(".",end='')
                else:
                    print("#",end='')
            print()
    else:
        print("Impossible")