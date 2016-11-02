#include <bits/stdc++.h>
#define ALL(x)(x).begin(),(x).end()
#define RFOR(i,x)for(__typeof(x.rbegin())i=x.rbegin();i!=x.rend();i++)
#define MAX 100009
using namespace std;
char cad[155],*ptr;
int calc(char* cad){
	return (cad[0]-'A')*(26*26)+(cad[1]-'A')*(26)+(cad[2]-'A');
}

void solve(char* cad){
	ptr=strtok(cad,"-");
	int a=calc(ptr),b;
	while((ptr=strtok(NULL,"-"))!=NULL)
			b=atoi(ptr);
	abs(a-b)<=100?puts("nice"):puts("not nice");
}
int cas;
int main()
{
	scanf("%d",&cas);
	while(cas--){
		scanf("%s",cad);
	solve(cad);
	}
}

