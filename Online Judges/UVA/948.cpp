#include <cstdio>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
#define MAX 100000009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
typedef  long long u64;
i64 fibo[200];
void fill(){
	fibo[0]=1LL;fibo[1]=2LL;
	for(int i=2;i<50;i++){
		fibo[i]=fibo[i-2]+fibo[i-1];
	}
}
void cad(i64 num){
	bool ok=0;
	int lo=lower_bound(fibo,fibo+50,num)-fibo;
	for(int i=lo;i>=0;i--){
		if(num>=fibo[i]){
			putchar('1');
			num-=fibo[i];
			ok=1;
		}
		else if(ok)
			putchar('0');
	}
}
int n,num;
int main() {
	 fill();
	 scanf("%d",&n);
	 for(int i=1;i<=n;i++){
		 scanf("%d",&num);
	 printf("%d = ",num);
	 cad(num);
	 printf(" (fib)\n");
	 }
}

