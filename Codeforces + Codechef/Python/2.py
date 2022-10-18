arr = ['abc' , 'xyz' , 'aba' , '1221']
my = []
for i in arr :
    if(len(i) % 2 == 0) :
        my.append(i)

print(my)