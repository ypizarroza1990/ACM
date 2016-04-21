#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include <stack>
#include <vector>
#define MAXN 1000000
using namespace std;
char C[MAXN+1];
int carry=0,n,A[MAXN+1],B[MAXN+1];;
char toC(int c){
	return c+'0';
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&A[i],&B[i]);
	for(int i=n-1;i>=0;i--){
		carry+=(A[i]+B[i]);
		C[i]=toC(carry%10);
		carry/=10;
	}
	printf("%s\n",C);
}


