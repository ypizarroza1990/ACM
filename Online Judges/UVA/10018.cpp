#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 50
using namespace std;
typedef long long i64;
i64 reversed(i64 n){
	i64 res=0;
	while(n){
		res=res*10+n%10;
		n/=10;
	}
	return res;
}
bool ispalindrome(i64 num){
	int d[20],t=0;
	while(num){
		d[t++]=num%10;
		num/=10;
	}
	for(int i=0;i<t-1;i++){
		if(d[i]!=d[t-i-1])
			return false;
	}
	return true;
}
int cas;
i64 num;
int main()
{
	 scanf("%d",&cas);
	 while(cas--){
		 scanf("%lld",&num);
		 int cont=0;
		 while(!ispalindrome(num)){
			 cont++;
			 num+=reversed(num);
		 }
		 printf("%d %lld\n",cont,num);
	 }
}

