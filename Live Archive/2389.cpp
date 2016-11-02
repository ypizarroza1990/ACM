#include <bits/stdc++.h>
#define MAX 100009
using namespace std;
typedef long long i64;
char bases[]={"0123456789abcdef"};
string convert_base(int n,int base){
	string res="";
	while(n){
		res+=bases[n%base];
		n/=base;
	}
	return res;
}
bool palimdromo(string num){
	string rev=num;
	reverse(rev.begin(),rev.end());
	return rev==num;
}
int n,ok,p;
int main( ) {
	//freopen("ent.in","r",stdin);
	while(scanf("%d",&n),n){
		ok=p=0;
		printf("Number %d is ",n);
		for(int i=2;i<=16;i++){
			if(palimdromo(convert_base(n,i))){
				if(!p)printf("palindrom in basis ");
				if(ok)printf(" ");
				printf("%d",i);
				ok=p=1;
			}
		}
		if(!ok)
			printf("not palindrom");
		printf("\n");
	}
	return 0;
}
