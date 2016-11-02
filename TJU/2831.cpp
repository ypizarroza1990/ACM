#include <bits/stdc++.h>
#define INF 1000
using namespace std;
typedef long long i64;
struct edge{ int u,v,w; } edges[6005];
int H[INF];
int cas,n,m,w;
bool bellman_ford( int edge){
	for(int i = 1; i <= n+1; ++i) H[i] = INF;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < edge; ++j)
			if(H[ edges[j].v ] > H[ edges[j].u ] + edges[j].w)
				H[ edges[j].v ] = H[ edges[j].u ] + edges[j].w;
	for(int i = 0; i < edge; ++i)
		if(H[ edges[i].v ] > H[ edges[i].u ] + edges[i].w)
			return true; // ciclo negativo detectado
	return false;
}
int main()
{
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d%d",&n,&m,&w);
		int x,y,c,t=0;
		for(int i=0;i<m;i++){
			 cin>>x>>y>>c;
			 edges[t++]=(edge){--x,--y,c};
			 edges[t++]=(edge){y,x,c};
		}
		for(int i=0;i<w;i++){
			cin>>x>>y>>c;
			edges[t++]=(edge){--x,--y,-c};
		}
		!bellman_ford(t)?puts("NO"):puts("YES");
	}
	return 0;
}

