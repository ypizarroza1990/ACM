from sys import stdin

def read_line():
    return stdin.readline().strip()

class Matriz(object):

    def __init__(self,N):
        self.N =N
        self.M = [[0]*N for i in range(N)]

    def multiply(self,M2,MOD):
        res = [[0]*self.N for i in range(self.N)]
        for i in range(self.N):
            for j in range(self.N):
                for k in range(self.N):
                    x = self.M[i][k] * M2[k][j]
                    res[i][j] += x
                    res[i][j] %= MOD

        return res

    def identity(self):
        size = range(self.N)
        return [[(i == j) * 1 for i in size] for j in size]

    def power(self,pow,MOD):
        res = self.identity()
        while pow > 0:
            if pow & 1:
                res = self.multiply(res,MOD)
            pow >>= 1
            self.M = self.multiply(self.M,MOD)
        return res


if __name__ == "__main__":
    M = Matriz(2)
    cas = 1
    while True:
        n,m = map(int,read_line().split())
        M.M[0] = [1]*2
        M.M[1][1] = 0
        M.M[1][0] = 1
        if (n,m) == (0,0):
            break
        M.M = M.power(n-1,m)
        print ("Case "+str(cas)+":",n,m,(2*sum(M.M[0])-1)%m)
        cas += 1 
