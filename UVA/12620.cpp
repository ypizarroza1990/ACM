#include <bits/stdc++.h>
#define MAX 301
#define LOG(x)31-__builtin_clz(x);
using namespace std;
typedef long long i64;
i64 fibo[MAX],sum[MAX];
i64 solve(i64 num){
	if(num<301)
		return sum[num];
	i64 temp=num/300;
	i64 ans=sum[300]*temp;
	ans+=sum[num%300];
	return ans;
}
int cas;
i64 a,b;
int main() {

	fibo[1]=1,fibo[2]=1;
	sum[1]=1,sum[2]=2;
	for(int i=3;i<MAX;i++){
		fibo[i]+=(fibo[i-1]+fibo[i-2])%100;
		 sum[i]+=sum[i-1]+fibo[i];
	}

	cin>>cas;
	while(cas--){
		cin>>a>>b;
		cout<<solve(b)-solve(a-1)<<endl;
	}
	return 0;
}

