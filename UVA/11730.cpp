#include<bits/stdc++.h>
#define MAX 1100
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
int flag[MAX>>6],prime[MAX>>2],len,d[MAX];
bool visit[MAX];
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;

	len=k;
}
vector<int>factors(long long n){
	vector<int>F;
	for(int i=0;prime[i]*prime[i]<=n&&i<len;i++){
		if(n%prime[i]==0){
			F.push_back(prime[i]);
			while(n%prime[i]==0)
				n/=prime[i];
		}
	}
	if(n>1)F.push_back(n);

	return F;
}
int bfs(int n,int end){
	memset(visit,0,sizeof(visit));
	memset(d,-1,sizeof(d));
	queue<int>Q;
	d[n]=0;
	visit[n]=1;
	Q.push(n);
	while(!Q.empty()){
		int temp=Q.front();Q.pop();
		vector<int>V=factors(temp);
		for(int i=0;i<(int)V.size();i++){
			if(V[i]!=temp){
				int num=temp+V[i];
				if(num<=end && !visit[num] ){
					d[num]=d[temp]+1;
					visit[num]=1;
					if(num==end)
						return d[end];
					Q.push(num);
				}
			}
		}
	}
	return d[end];
}
int cas,a,b,t=1;
int main(){
	criba();
	while(scanf("%d%d",&a,&b),a+b){
		printf("Case %d: %d\n",t++,bfs(a,b));
	}
	return 0;
}

