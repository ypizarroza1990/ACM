#include <bits/stdc++.h>
using namespace std;
int cad[125000],len,res;
void solve(int b,int e){
	cad[(len=0)++]=1;
	for(int i=1;i<=e;i++){
		res=0;
		for(int j=0;j<len;j++){
			res=b*cad[j]+res;
			cad[j]=res%10000;
			res/=10000;
		}
		if(res){cad[len++]=res;}}}
int main() {
	int b,e;
	while(scanf("%d%d",&b,&e),b+e){
		 memset(cad,0,sizeof(cad));
		solve(b,e);
		printf("%d",cad[len-1]);for(int i=len-2;i>=0;i--)
		printf("%.4d",cad[i]);
		printf("\n");
	}
	return 0;
}
