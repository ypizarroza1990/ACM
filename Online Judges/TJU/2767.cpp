#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
const int MAX=4000010;
int flag[MAX>>6],prime[MAX>>3],primelen;
void Criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=2)
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	prime[(k=0)++]=2;
	for(int i=3;i<MAX;i+=2)
		if(!ifc(i))
			prime[k++]=i;
	primelen = k;
}
bool esPrimo(int n){
	if(n==2)return true;
	if(n>2 &&((n&1) && !ifc(n)))return true;
	return false;
}
int x,y,lower,cont=0;
char d[2],cad[20];
int main() {
	Criba();
	scanf("%d %d %s",&x,&y,d);
	for(int i=x;i<=y;i++){
		if(esPrimo(i)){
			sprintf(cad,"%d",i);
			if(strstr(cad,d)){cont++;}
		}
	}
	printf("%d\n",cont);
}