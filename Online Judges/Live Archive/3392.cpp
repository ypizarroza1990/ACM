#include <bits/stdc++.h>
#define MAX 1009
#define T(n)(n*(n+1))/2
using namespace std;
long long sum[MAX],triang[MAX];
void solve(){
	 for(int i=1;i<MAX;i++)
		 triang[i]=T(i);
	 for(int i=1;i<MAX;i++){
		 sum[i]=sum[i-1]+(i*triang[i+1]);
	 }
}
int cas,n;
int main(){
	 solve();
	 scanf("%d",&cas);
	 for(int i=1;i<=cas;i++){
		 scanf("%d",&n);
		 printf("%d %d %lld\n",i,n,sum[n]);
	 }

}
