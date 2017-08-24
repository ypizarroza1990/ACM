from sys import stdin
from random import randrange


def line():
    return stdin.readline().strip()


def miller_rabin(n, k=20):
    if n == 2:
        return True
    if not n & 1:
        return False

    def check(a, s, d, n):
        x = pow(a, d, n)
        if x == 1:
            return True
        for i in range(s-1):
            if x == n-1:
                return True
            x = pow(x, 2, n)
        return x == n-1

    s = 0
    d = n-1
    while d % 2 == 0:
        d >>= 1
        s += 1

    for i in range(k):
        a = randrange(2, n)
        if not check(a, s, d, n):
            return False
    return True


if __name__ == "__main__":
    while True:
        p, a = map(int, line().split())
        if (p, a) == (0, 0):
            break
        ans = (not miller_rabin(p)) and (pow(a, p, p) == a)

        print('yes' if ans else 'no') 
