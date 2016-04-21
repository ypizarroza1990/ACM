#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 10000
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>2];
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
}
bool isprime(int N){
	if((N&1)&&!ifc(N))
		return 1;
	return 0;
}
int d[MAX];
bool visit[MAX];
int bfs(int start,int end){
	memset(d,-1,sizeof(d));
	memset(visit,0,sizeof(visit));
	queue<int>Q;
	Q.push(start);
	visit[start]=1;
	d[start]=0;
	int i,j;
	char cad[10];
	while(!Q.empty()){
		int v=Q.front();Q.pop();
		sprintf(cad,"%d",v);
		int x=cad[0];
		for(int t=0;t<4;t++){
			t==0||t==3?i=1:i=0;
			t==3?j=2:j=1;
			x=cad[t];
			for(;i<=9;i+=j){
				cad[t]=(i+'0');
				int u=atoi(cad);
				if(v != u && !visit[u] && isprime(u) ){
					Q.push(u);
					visit[u]=1;
					d[u]=d[v]+1;
					if(u==end)return d[end];
				}
			}
			cad[t]=x;
		}
	}
	return d[end];
}
int cas,x,y;
int main() {

	criba();
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&x,&y);
		if(x==y)
			puts("0");
		else{
			int d=bfs(x,y);
			d==-1?puts("Impossible."):printf("%d\n",d);
		}
	}

}

