#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long i64;
int ans[MAX+3];
void compute(){
	ans[0]=1;
	for(int i=1;i<=MAX;i++){
		ans[i]=i*ans[i-1];
		while(ans[i]%10==0)ans[i]/=10;
		ans[i]%=100000;
	}
}
int main(){

	compute();
	int n;
	while(scanf("%d",&n)==1){
		printf("%5d -> %d\n",n,ans[n]%10);
	}
}

