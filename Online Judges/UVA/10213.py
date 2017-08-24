__author__ = 'pizarroza'
from sys import stdin


def line():
    return stdin.readline().strip()


def solve(n):
    ans = 1
    ans += n*(n-1)//2
    ans += (n*(n-1)*(n-2)*(n-3))//24
    return ans

if __name__ == "__main__":
    cas = int(line())
    for i in range(cas):
        n = int(line())
        print(solve(n))


 
