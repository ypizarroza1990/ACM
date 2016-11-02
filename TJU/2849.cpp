//============================================================================
// Name        : Grundy_Cup.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAXLOG 16
#define MAX    25000
using namespace std;
typedef long long i64;
priority_queue<int>Q;
i64 solve(priority_queue<int>&Q){
	i64 ans=0;
	while(Q.size()>1){
		int a=Q.top();Q.pop();
		int b=Q.top();Q.pop();
		ans-=(a+b);
		Q.push(a+b);
	}
	return ans;
}
int cas,n;
int main() {
	 scanf("%d",&cas);
	 while(cas--){
		 scanf("%d",&n);
		 Q.push(-n);
	 }
	 cout<<solve(Q)<<endl;
	return 0;
}
