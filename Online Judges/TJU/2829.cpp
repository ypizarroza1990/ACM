//============================================================================
// Name        : 2829.cpp
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
int N,L;
void solve(){
	scanf("%d%d",&N,&L);
	bool ok;
	int aux;
	for(int i=1,cont=0;;i++){
		ok=1;aux=i;
		while(aux!=0 && ok){
			if(aux%10==L)ok=0;
			aux/=10;
		}
		if(ok)cont++;
		if(cont==N){
			printf("%d\n",i);
			return;
		}
	}
}
int main() {
	 solve();
}
