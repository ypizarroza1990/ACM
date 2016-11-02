__author__ = 'mpc-tlj'
from sys import stdin

def line():
    return stdin.readline().strip()

MAXN = 10005

rock = [0]*MAXN
mark = [0]*MAXN

N,T,L = map(int,line().split())
L+=1

Nim = 0

for i in range(1,N,1):
    padre,rock[i] = map(int,line().split())
    padre -=1
    mark[i] = mark[padre]^1
    rock[i] %=L
    if mark[i]:
        Nim ^= rock[i]

for j in xrange(T):
    a,b=map(int,line().split())
    a-=1
    b%=L
    if mark[a]:
        Nim ^=rock[a]^b
    rock[a]=b
    if Nim == 0:
        print 'No'
    else:
        print 'Yes'

