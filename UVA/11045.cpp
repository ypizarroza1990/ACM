 #include<bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
using namespace std;

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index): from(from),
  to(to),
  cap(cap),
  flow(flow),
  index(index) {}
};

struct Dinic {
  int N;
  vector < vector < Edge > > G;
  vector < Edge * > dad;
  vector < int > Q;
  Dinic(int N): N(N),
  G(N),
  dad(N),
  Q(N) {}
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }
  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge * ) NULL);
    dad[s] = & G[0][0] - 1;
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge & e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow >0) {
          dad[e.to] = & G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;
    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge * start = & G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge * e = start; amt && e != dad[s]; e = dad[e->from]){
        if (!e) {
          amt = 0;
          break;
        }
        amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge * e = start; amt && e != dad[s]; e = dad[e->from]){
        e->flow += amt;
        G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }
  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};
int normalize(string T){
    if(T=="XXL")return 1;
    else if(T=="XL")return 2;
    else if(T=="L")return 3;
    else if(T=="M")return 4;
    else if(T=="S")return 5;
    else return 6;

}
int cas,N,M,o,t;
char cad[5],cad2[5];
int main(){

    scanf("%d",&cas);
    for(int i=1;i<=cas;i++){
        scanf("%d%d",&N,&M);
        Dinic G(M+10);
        for(int i=1;i<=6;i++){
            G.AddEdge(0,i,N/6);
        }
        for(int i=1;i<=M;i++){
            scanf("%s %s",cad,cad2);
            o=normalize((string)cad);
            t=normalize((string)cad2);
            G.AddEdge(o,i+6,1);
            G.AddEdge(t,i+6,1);
            G.AddEdge(i+6,M+7,1);
        }
        int ans=G.GetMaxFlow(0,M+7);
        printf("%s\n",ans>=M?"YES":"NO");
    }
    return 0;
}
