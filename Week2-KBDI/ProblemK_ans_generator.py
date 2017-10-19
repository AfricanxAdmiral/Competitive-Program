from random import sample, randint
from itertools import product

print(50)
for i in range(0,160,4):
    if i == 20:
        print(20,20)
        print(*["{} 1".format(x+1) for x in range(20)],sep='\n')
    elif i == 0:
        print(20,0)
    else:
        print(20,2*i)
        cand = ['{} {}'.format(x,y) for x, y in product(range(1,21),range(1,21))]
        print(*sample(cand,i*2),sep='\n')

for i in range(10):
    n = randint(2,19)
    m = randint(0,n**2//2)
    print(n,m)
    cand = ['{} {}'.format(x,y) for x, y in product(range(1,n+1),range(1,n+1))]
    print(*sample(cand,m),sep='\n')