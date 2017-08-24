__author__ = 'Anthrax'
from sys import stdin
def line():
    return stdin.readline().strip()

fact = []
fact.append(1)
for i in range(1,601):
    fact.append(fact[i-1]*i)
while True:
    n = int(line())
    if n == 0 :
        break
    print(fact[2*n]//fact[n+1]) 
