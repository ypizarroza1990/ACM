#include <algorithm>
#include <stdio.h>
#include <cmath>
#define MAX 15010
#define MOD 10000
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
int fibo[MAX];
void compute(){
	fibo[1]=fibo[2]=1;
	for(int i=3;i<MAX;i++)
		fibo[i]=(fibo[i-1]+fibo[i-2])%MOD;
}
int n;
int main() {
	compute();
	while(scanf("%d",&n),n!=-1){
		n%=15000;
		n=n?n:15000;
		printf("%d\n",fibo[n]);
	}
	return 0;
}
