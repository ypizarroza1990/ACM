from sys import stdin


def line():
    return stdin.readline().strip()


class DisjoinSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.level = [1] * n
        self.N = n

    def equal(self, x, y):
        return self.find(x) == self.find(y)

    def find(self, x):
        if x == self.parent[x]:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def join(self, x, y):
        xroot = self.find(x)
        yroot = self.find(y)

        if xroot == yroot:
            return

        self.N -= 1

        if self.level[xroot] == self.level[yroot]:
            self.level[xroot] += 1

        if self.level[xroot] < self.level[yroot]:
            tmp = xroot
            xroot = yroot
            yroot = tmp
        self.parent[yroot] = xroot


class edge:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def __lt__(self, other):
        return self.c > other.c


class Kruskal:
    def __init__(self, edges, n):
        self.edges = edges
        self.N = n

    def mst(self):
        mst = 0
        edges = sorted(self.edges)
        set = DisjoinSet(self.N)
        for e in edges:
            if not set.equal(e.a, e.b):
                set.join(e.a, e.b)
                mst += e.c
            if set.N == 1:
                break
        return mst



if __name__ == "__main__":
    while True:
        cas = int(line())
        if cas == 0:
            break
        for _ in range(cas):
            n, m = map(int, line().split())
            edges = []
            suma = 0

            for i in range(m):
                x, y, z = map(int, line().split())
                edges.append(edge(x-1, y-1, z))
                suma += z

            K = Kruskal(edges, n)
            print(suma - K.mst())

 
