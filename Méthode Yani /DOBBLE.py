from itertools import combinations
import random as rd
import time
import matplotlib.pyplot as plt

def rajoute(i,l,LL):
    L = []
    for j in l:
        a = [i]+j
        list.sort(a)
        if a not in LL:
            L.append(a)
    return L


def listekparmin(k,n,l):
    L = []
    if k==1:
        for i in range(n):
            if i+1 not in l:
                L.append([i+1])
    else:
        for i in range(n):
            if i+1 not in l:
                LL = rajoute(i+1,listekparmin(k-1,n,l+[i+1]),L)
                L = L+LL
    return L


def transformation(l):
    L = [i for i in l]
    return L



def listekparmin2(k,n):
    L = []
    letters = [i+1 for i in range(n)]
    a = combinations(letters, k)
    for i in a:
        L.append(transformation(i))
#        L.append(i)
    return L



def base(k):
    return [i for i in range(k-1)]



def cardinalun(l1,l2):
    l = l1+l2
    list.sort(l)
    s = 0
    for i in range(len(l)-1):
        if l[i]==l[i+1]:
            s+=1
    if s == 1:
        return True
    else:
        return False



def listekparmin3(k,n):
    j = 0
    m = 0
    L = []
    letters = [i+1 for i in range(n)]
    a = combinations(letters, k)
    for i in a:
        j += 1
        if cardinalun(transformation(i),base(k)):
            L.append(transformation(i))
#        L.append(i)
        if j==1000000:
            print(m)
            j = 0
            m += 1
    return L


#c = listekparmin(3,7,[])
#d = listekparmin(4,13,[])
e = listekparmin2(5,21)
f = listekparmin2(6,31)
#g = listekparmin3(8,57)
#f = listekparmin(6,31,[])
rd.shuffle(f)

#cc = listekparmin2(8,57)



def algorithmerajoute(l):
    n = len(l)
    nn = len(f)
    booll1 = True
    i = 0
    s = 0
    while i<nn and booll1:
        booll2 = True
        k = 0
        while k<n and booll2:
            if not cardinalun(f[i],l[k]):
                booll2 = False
            k += 1
        if booll2 and k==n:
            booll1 = False
            s = f[i]
        else:
            i+=1
    if s!=0:
        return l+[s]
    else:
        return l


def vraialgorithme(s):
    L = [s]
    while algorithmerajoute(L)!=L:
        print('1')
        L = algorithmerajoute(L)
    return L


def vraialgorithmefinal(s):
    rd.shuffle(f)
    a = vraialgorithme(s)
    print(len(a),'le premier')
    while len(a)!=31:
        print(len(a))
        rd.shuffle(f)
        a = vraialgorithme(s)
    return a


###


def algorithmerajoute2(l,j):
    n = len(l)
    nn = len(f)
    booll1 = True
    i = j
    s = 0
    while i<nn and booll1:
        booll2 = True
        k = 0
        while k<n and booll2:
            if not cardinalun(f[i],l[k]):
                booll2 = False
            k += 1
        if booll2 and k==n:
            booll1 = False
            s = f[i]
        else:
            i+=1
    if s!=0:
        return l+[s],i
    else:
        return l,i


def algorithmerajoute3(l,j,g):
    n = len(l)
    nn = len(g)
    booll1 = True
    i = j
    s = 0
    while i<nn and booll1:
        booll2 = True
        k = 0
        while k<n and booll2:
            if not cardinalun(g[i],l[k]):
                booll2 = False
            k += 1
        if booll2 and k==n:
            booll1 = False
            s = g[i]
        else:
            i+=1
    if s!=0:
        return l+[s],i
    else:
        return l,i


def vraialgorithme2(s):
    L = [s]
    j = 0
    while algorithmerajoute2(L,j)[0]!=L:
        print('1')
        L,j = algorithmerajoute2(L,j)
    return L


def vraialgorithme3(s,g):
    L = [s]
    j = 0
    while algorithmerajoute3(L,j,g)[0]!=L:
        print('1')
        L,j = algorithmerajoute3(L,j,g)
    return L


def vraialgorithmefinal2(s):
    rd.shuffle(f)
    a = vraialgorithme2(s)
    print(len(a),'le premier')
    while len(a)!=31:
        print(len(a))
        rd.shuffle(f)
        a = vraialgorithme2(s)
    return a


def calcul(n):
    return n**2-n+1



def vraialgorithmefinal3(s):
    seconds = time.time()
    c = 1
    n = len(s)
    g = listekparmin2(n,calcul(n))
    rd.shuffle(g)
    a = vraialgorithme3(s,g)
    print(len(a),'le premier')
    while len(a)!=calcul(n):
        print(len(a))
        print(g[0])
        rd.shuffle(g)
        a = vraialgorithme3(s,g)
        c += 1
    seconds2 = time.time()
    b = seconds2-seconds
    return a,b,c

def test(n):
    x = [i for i in range(2,7)]
    y = []
    for i in range(2,7):
        a = 0
        for j in range(n):
            a += vraialgorithmefinal3([i for i in range(1,i+1)])[1]
        a = a/n
        y.append(a)
    plt.plot(x,y)
    plt.show()

###


def tentative(q):
    liste = []
    c = 1
    a = [i+1 for i in range(q)]
    liste.append(a)
    liste = liste+labase(q)
    for i in range(1,q):
        d = suite(q,i+1)
        liste = liste + d
    return liste,len(liste),verification(liste)


def labase(q):
    liste = []
    for k in range(1,q):
        a = [1]
        for j in range(k*(q-1)+2,k*(q-1)+q+1):
            a.append(j)
        liste.append(a)
    return liste



def suite(q,i):
    liste = []
    listedeliste = [[j for j in range(k*(q-1)+2,k*(q-1)+q+1)] for k in range(1,q)]
    listedeliste2 = [[(k+j*(i-2))%(q-1) for j in range(0,q-1)] for k in range(0,q-1)]
    for k in range(1,q):
        a = [i]
        for v in range(len(listedeliste2[k-1])):
            a.append(listedeliste[v][listedeliste2[k-1][v]])
#        print(a)
        liste.append(a)
    return liste




def verification(l):
    n = len(l)
    for i in range(n):
        for j in range(i+1,n):
            if not cardinalun(l[i],l[j]):
                return False
    return True
