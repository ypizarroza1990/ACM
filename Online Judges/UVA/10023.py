from sys import stdin


def line():
    return stdin.readline().strip()


def SQRT(N):
    sqr = N >> (len(bin(N)[2:]) >> 1)
    result = 0
    while True:
        if sqr:
            result = (sqr + N // sqr) >> 1
        if sqr != result:
            sqr = result
        else:
            break
    return result

if __name__ == "__main__":
    n = int(line())
    for _ in range(n):
        line()
        if _ :
            print()
        x = int(line())
        y = SQRT(x)
        print(y)
