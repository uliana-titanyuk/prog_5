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
        elif (n ==1 ):
            b = int(x)
            if (a ==b):
               k+=1
        elif (int(x) == a):
            k += 1
        elif (int(x)==b):
            m+=1
        n+=1
    f.close()
    print(k, m, n)
    if (k>(n-3)):
      res=1
      print('yes,you can')
    elif(m>(n-3)):
      res=1
      print('yes,you can')
    else:
      print('no,you can not')
      res=0
    return res

fanc("data.txt")
 
   