//============================================================================
// Name        : COJ.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 saldo;
int n,val;
char op[20];
int main() {
	scanf("%d",&n);
	saldo=0;
	while(n--){
		scanf("%s",op);
		if(op[0]=='d'){
			scanf("%d",&val);
			saldo+=val;
		}else{
			printf("%lld\n",saldo);
		}
	}
    return 0;
}
