
str = "(((())))()()(())"
my_list = []
temp = ''
c = 0
for i in str :
    
    print("at = " , i)
    if(i == '(') :
        c+=1
    else :
        c-=1
    
    temp += i
    
    if(c == 0) :
        my_list.append(temp)
        temp = ''

if(c == 0) :
    print(my_list)
else :
    print('error')
