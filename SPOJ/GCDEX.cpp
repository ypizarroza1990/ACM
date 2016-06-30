#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1000009
using namespace std;
typedef long long i64;
i64 divi[MAX],f1[MAX],f2[MAX];
i64 powi,p,aux,expi;
int main(){
	memset(divi,-1,sizeof(divi));

	for(int i=2;i<MAX;i++){
		if(divi[i]==-1){
			divi[i]=i;
			if(i<=1000){
				for(int j=i*i;j<MAX;j+=i)
					divi[j]=i;
			}
		}
	}

	memset(f2,-1,sizeof(f2));
	f1[1]=0;
	f2[1]=1;
	for(int i=2;i<MAX;i++){
		p=divi[i],powi=1;
		aux=i,expi=0;
		while(aux%p==0){
			expi++;
			powi*=p;
			aux/=p;
		}
		f2[i]=((expi+1)*powi-expi*(powi/p))*f2[aux];
		f1[i]=f1[i-1]+f2[i]-i;
	}
	int N;
	while(scanf("%d",&N),N){
		printf("%lld\n",f1[N]);
	}

}

