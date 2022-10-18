arr = []
with open('file2.txt' , 'w') as ff :

    with open('file1.txt','r') as f :
        str = f.readlines()
        print(str)
        for i in str:
            data = i.split()
            print(len(data))
            if (len(data) %2 == 1) :
                ff.write(i)
            else : 
                arr.append(i)
        f.close()
ff.close()

f = open('file1.txt','w')
f.writelines(arr)
f.close()
    