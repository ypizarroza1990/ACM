#include <algorithm>
#include <stdio.h>
#include <cmath>
#define MAX 100009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
int flag[MAX>>6],prime[MAX>>3],len;
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i))
			prime[k++]=i;
	}
	len=k;
}
int n,m;
int main() {
	criba();
	 while(scanf("%d %d",&n,&m),n!=-1&&m!=-1){
		 if(n>m)swap(n,m);
		 int x=lower_bound(prime,prime+len,n)-prime;
		 int y=upper_bound(prime,prime+len,m)-prime;
		 printf("%d\n",y-x);
	 }
	return 0;
}
