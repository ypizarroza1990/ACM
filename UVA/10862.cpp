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
string fibo[4009];
string add(string a,string b){
	string sol="";
	int la=a.size(),lb=b.size();
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int i=0,c=0;i<la||i<lb||c;i++){
		if(i<la)c+=(a[i]-'0');
		if(i<lb)c+=(b[i]-'0');
		sol+=('0'+c%10);
		c/=10;
	}
	reverse(sol.begin(),sol.end());
	return sol;
}
void fill(){
	fibo[0]=fibo[1]="1";
	for(int i=2;i<4009;i++){
		fibo[i]=add(fibo[i-2],fibo[i-1]);
	}
}
int n,num;
int main() {
	 fill();
	 while(scanf("%d",&num),num){
		 printf("%s\n",fibo[2*num-1].c_str());
	 }

}

