__author__ = '@Anthrax'
from sys import stdin
from fractions import gcd
def line():
	return stdin.readline().strip()
cas  = int(line())
for i in xrange(cas):
	a,b,c = map(int,line().split())
	print str(a)*gcd(b,c)
