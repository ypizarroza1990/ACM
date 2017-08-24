from sys import stdin

def line():
    return stdin.readline().strip()

if __name__ == "__main__":
    while True:
        n = int(line())
        if n == 0:
            break
        for _ in range(n):
            x, y, n = map(int, line().split())
            print(pow(x, y, n)) 
