#include <bits/stdc++.h>
#define MAX 10000000
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
int flag[(4*MAX)>>6];
void criba(){
	int i,j,k;
	for(i=3;i<6325;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<(4*MAX);j+=k){
				isc(j);
			}
		}
	}
	for(int i=30000001;i<(4*MAX);i+=(i%6==1)?4:2){
		if(!ifc(i))
			printf("%d\n",i);
	}
}
int main(void){
     criba();
    return 0;
}
