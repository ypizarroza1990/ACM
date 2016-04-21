#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include <iostream>
#include <map>
using namespace std;
typedef unsigned long long  i64;
int n,m,cas;
int main(){
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&m);
		i64 c;
		if(m>n/2)m=n-m;
		c=1;
		for(int i=0;i<m;i++)
			c=c*(n-i)/(i+1);
		cout<<c<<endl;
	}
	return 0;
}

