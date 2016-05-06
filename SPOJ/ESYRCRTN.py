__author__ = '@Anthrax'
from sys import stdin
 
def line():
    return stdin.readline().strip()
 
lista = [0]
 
def fib():
    lista.append(1)
    lista.append(3)
    for i in range(3,7,1):
        lista.append(lista[i-1]-lista[i-2])
 
fib()
n = int(line())
for i in range(1,7,1):
    lista[i]+=lista[i-1]
for i in xrange(n):
    x = int(line())
    print lista[x%6] 
