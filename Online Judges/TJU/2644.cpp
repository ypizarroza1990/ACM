#include<bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 31629
using namespace std;
typedef long long int i64;
int cas,n,t;
double pie[10009],r;
bool ok(double V,double A[],int t){
	int res=0;
	for(int i=0;i<n;i++){
		res+=(floor(A[i]/V));
	}
	return res>=t;
}
int main(){

	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&t);
		double lo=0,hi=0,mid;
		for(int i=0;i<n;i++){
			scanf("%lf",&r);
			pie[i]=M_PI*r*r;
			hi=max(hi,pie[i]);
		}
		while(hi-lo>1e-5){
			mid=(lo+hi)/2;
			if(ok(mid,pie,t+1))
				lo=mid;
			else
				hi=mid;
		}
		printf("%.4lf\n",lo+1e-6);
	}

	return 0;
}

