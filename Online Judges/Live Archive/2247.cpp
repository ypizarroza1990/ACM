#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
int flag[15660];
char cad[1000];
void Criba(){
	int i,j,k;
	for(i=3;i<=1000;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<1000000;j+=k)
				isc(j);
		}
	}
}
bool prime(int num){
	if(num<2)return 0;
	if(num==2)return 1;
	if(num&1&&(!ifc(num)))return 1;
	return 0;
}
void solve(){
	int num=atoi(cad);
	if(prime(num)){
		printf("%7s\n",cad);
		return;
	}
	else if(num>10){
		num=0;
		for(int i=0;cad[i];i++){
			num+=(cad[i]-'0');
		}
		sprintf(cad,"%d",num);
		solve();
	}
	else{printf("   %s","none\n");
	return;
	}
}
int main() {
	Criba();
	while( scanf("%s",cad),strcmp(cad,"0")!=0){
		printf("%7s ",cad);
		solve();
	}
}
