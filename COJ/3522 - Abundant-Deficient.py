__author__ = 'Anthrax'
from sys import stdin

def line():
    return stdin.readline().strip()

def factorize(n):
    factors = {}
    power = 0
    while n % 2 == 0:
        power += 1
        n //=2
    if power > 0:
        factors[2] = power
    d = 3
    while n > 1:
        power = 0
        while n % d == 0:
            power += 1
            n //= d
        if power > 0:
            factors[d] = power
        d += 2
        if d * d > n:
            d = n
    return factors


def get_all_divisors(n):
    divisors = 1
    d = n
    factor = factorize(n)
    for x,y in factor.items():
        divisors *=((x**(y+1)-1)/(x-1))
    return divisors-d

MAXN = 100005

tree=[0]*(2*MAXN)
arr = [0]*MAXN

def update(pos,val):
    i = pos+MAXN
    while i < 2*MAXN:
        tree[i]+=val
        i += i&-i

def query(pos):
    suma = 0
    i = pos+MAXN
    while i > 0:
        suma += tree[i]
        i -= i&-i
    return suma

n = int(line())

for i in xrange(n):
    x = int(line())
    div = get_all_divisors(x)
    if div == x:
        continue
    if div>x:
        arr[i] = 1
    else:
        arr[i]= -1

ans = 0
tmp = 0
update(0,1)

for i in xrange(n):
    tmp += arr[i]
    ans +=query(tmp)
    update(tmp,1)

print ans


