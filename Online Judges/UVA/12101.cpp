#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 10000
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>2],len;
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i))
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
	}
	prime[(k=0)++]=2;
	for(i=3;i<(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i))
			prime[k++]=i;
	}
	len=k;
}
bool isprime(int N){
	if(N<2)
		return 0;
	if(N==2)
		return 1;
	if((N&1)&&!ifc(N))
		return 1;
	return 0;
}
int d[MAX];
bool visit[MAX];
int bfs(int start,int end){
	int i,j;
	memset(d,-1,sizeof(d));
	memset(visit,0,sizeof(visit));
	queue<int>Q;
	Q.push(start);
	d[start]=0;
	visit[start]=1;
	char temp[10];
	while(!Q.empty()){
		int n=Q.front();Q.pop();
		sprintf(temp,"%d",n);
		int x=temp[0];
		for(int t=0;t<4;t++){
			t==0||t==3?i=1:i=0;
			t==3?j=2:j=1;
			x=temp[t];
			for(;i<=9;i++){
				temp[t]=(i+'0');
				int p=atoi(temp);
				if(p!=n && !visit[p] && isprime(p)){
					Q.push(p);
					visit[p]=1;
					d[p]=d[n]+1;
					if(p==end)return d[end];
				}
			}
			temp[t]=x;
		}
	}
	return d[end];
}
int cas,x,y;
int main()
{
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
	return 0;
}
 
