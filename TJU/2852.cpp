//============================================================================
// Name        : 2852.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define SIZE(L)(int)L.size()
using namespace std;
int N,array[80010],top[80010],cont;
long long res=0;

int main() {
	 scanf("%d",&N);
	 for(int i=0;i<N;i++)
		 scanf("%d",&array[i]);

	 for(int i=N-1;i>=0;i--){
		 top[i]=i+1;
		 while(top[i]<N && array[top[i]]<array[i]){
			 res+=top[top[i]]-top[i];
			 top[i]=top[top[i]];
		 }
	 }
	 printf("%lld\n",res);
}
