def fanc(filename):
    n = 0
    m = 0
    k = 0
    res = 0
    try:
        f = open(filename, "r")
    except:
        print('cant open file')
    seq = [s5 for s1 in f for s2 in s1.split(' ') for s3 in s2.split('\n') for s4 in s3.split(',') for s5 in
           s4.split('\t') if s5 != '']
    print(seq)
    
    for x in seq:
        if (n == 0):
            a = int(x)
            n+=1
        if (n ==1):
            b = int(x)
            n+=1
        #if (n == 2):
            #c = int(x)
           # n+=1    
        elif (x == a):
            k += 1
            n+=1
        elif(x==b): 
            m+=1
            n+=1
        else: 
            n+=1
            
        
    f.close()
    if(k>(n-2)):
      res=1
      
    elif(m>(n-2)):
      res=1
      print('yes,you can')
    else:
      print('no,you can not')
      res=0
    return res

fanc("data.txt")
 
   