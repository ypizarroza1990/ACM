#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 20005;
const int M = 60005;
const int inf=1<<30;
int pre[N], d[N], q[M], head[N];
bool vis[N];
int len, s, t, ans, cost;
struct node {
	int u, v, c, cost;
	int next;
}edge[M*4];

void addedge(int u, int v, int c,int cost) {
	edge[len].u = u; edge[len].v = v; edge[len].cost = cost;
	edge[len].c = c; edge[len].next = head[u]; head[u] = len++;

	edge[len].u = v; edge[len].v = u; edge[len].cost = -cost;
	edge[len].c = 0; edge[len].next = head[v]; head[v] = len++;
}
bool SPFA() {
	int l, r, j;
	memset(vis, 0, sizeof vis);
	memset(pre, -1, sizeof pre);
	for(int i=0; i<=t; i++) d[i] = inf;

	l = r = 0;
	q[r++] = s;
	vis[s] = 1;
	d[s] = 0;
	while(l != r) {
		int u = q[l++];
		vis[u] = 0;
		for(j = head[u]; j != -1; j = edge[j].next) {
			int v = edge[j].v;
			if(edge[j].c != 0 && d[v] > d[u] + edge[j].cost) {
				d[v] = d[u] + edge[j].cost;
				pre[v] = j;
				if(!vis[v]) {
					vis[v] = 1;
					q[r++] = v;
				}
			}
		}
	}
	if(pre[t] == -1) return 0;
	return 1;
}
void MCF() {
	while(SPFA()) {
		int minflow = inf, i;
		for(i = pre[t]; i != -1; i = pre[edge[i].u]) if(minflow > edge[i].c)
			minflow = edge[i].c;
		for(i = pre[t]; i != -1; i = pre[edge[i].u]) {
			edge[i].c -= minflow;
			edge[i^1].c += minflow;
			cost += edge[i].cost;
		}
		ans += minflow;
	}
}

int n, m, tmp, T;

int main() {

	int N,M,u,v;
	long long cst;

	while(scanf("%d %d",&N,&M)==2){

		s=0,t=N+1;
		memset(head, -1, sizeof head);
		ans = cost = len = 0;
		for(int i = 0;i<M;++i){
			scanf("%d %d %lld",&u,&v,&cst);
			addedge(u,v,1,cst);
			addedge(v,u,1,cst);
		}
		addedge(0,1,2,0);
		addedge(N,N+1,2,0);

		MCF();

		printf("%d\n",cost);
	}
}
