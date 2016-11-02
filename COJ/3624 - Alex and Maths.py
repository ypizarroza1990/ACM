__author__ = 'Antrhax'
from sys import stdin
import functools
def line():
    return stdin.readline().strip()
mod = 10**9+9
arr = [0]*102
N = None
R = None
def memoize(function):
    cache = {}
    @functools.wraps(function)
    def memoized(*args):
        if args in cache:
            return cache[args]
        else:
            res = function(*args)
            cache[args] = res
            return res
    return memoized

@memoize
def solve(pos,t,r):
	if pos == N and t == 0 and r == 0:
		return 1
	if t<0  or pos>N:
		return 0
	ans = (solve(pos+1,t,r)+solve(pos+1,t-1,(r+arr[pos])%R))%mod
	return ans

N,t,R = map(int,line().split())
arr = map(int,line().split())
arr.append(0)
print solve(0,t,R)


