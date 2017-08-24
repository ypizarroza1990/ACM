 
from sys import stdin


def line():
    return stdin.readline().strip()

mod = 10**16 + 7


def solve(n, k):
    p = n * k // 2
    q = n * k - p

    ans = (pow(p, q-1, mod) * pow(q, p-1, mod)) % mod

    return ans


if __name__ == "__main__":
    n = int(line())

    for _ in range(n):
        n, k = map(int, line().split())
        print(solve(n, k))