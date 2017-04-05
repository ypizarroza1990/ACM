#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1000000
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>2],len;
int array[MAX+10];
int nod(int x){
	int prod=1,sz;
	for(int i=2;i<=x/i;i++){
		sz=0;
		if(x%i==0){
			while(x%i==0){
				++sz;
				x/=i;
			}
			prod*=(sz+1);
		}
	}
	if(x>1)prod*=2;

	return prod;
}
void solve(){
	memset(array,0,sizeof(array));
	array[0]=1;
	for(int x=1;x<=MAX;){
		++array[x];
		x+=nod(x);
	}
	for(int x=1;x<=MAX;x++){
		array[x]+=array[x-1];
	}
}
int cas,a,b;
int main(){
	solve();
	scanf("%d",&cas);
	for(int i=1;i<=cas;i++){
		scanf("%d%d",&a,&b);
		printf("Case %d: %d\n",i,array[b]-array[a-1]);
	}
}

