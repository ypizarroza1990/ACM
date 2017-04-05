from sys import stdin
import functools

def line():
    return stdin.readline().strip()

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
def mahonian_row(n):

    i = 1
    result = [1]
    while i < n:
        # Copy previous row of n into prev
        prev = result[:]
        result = [0] * int(1 + ((i + 1) * 0.5) * (i))
        m = [1] * (i + 1)
        # Multiply
        for j in range(len(m)):
            for k in range(len(prev)):
                result[k+j] += m[j] * prev[k]
        i = i + 1
    return result


def main():
    t = int(line())
    for _ in xrange(t):
        n, k = map(int,line().split())
        row = mahonian_row(n)
        if k < 0 or k > len(row) - 1:
            print 0
        else:
            print row[k]


if __name__ == '__main__':
    main()

 
