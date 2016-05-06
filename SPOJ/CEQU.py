__author__ = '@Anthrax'
from sys import stdin
from fractions import gcd
def line():
	return stdin.readline().strip()
cas  = int(line())
for i in xrange(cas):
	a,b,c = map(int,line().split())
	mcd = gcd(a,b)
	if c % mcd == 0:
		print 'Case '+str(i+1)+': Yes'
	else:
		print 'Case '+str(i+1)+': No'
