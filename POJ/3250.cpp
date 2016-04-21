#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long i64;
int h[80009],n[80009],N;
i64 solve(){
	i64 T=0,c;
	for(int i=N-1;i>=0;i--){
		n[i]=i+1;c=0;
		while(n[i]<N && h[n[i]]<h[i]){
			c+=n[n[i]]-n[i];
			n[i]=n[n[i]];
		}
		T+=c;
	}
	return T;
}
int main()
{
	 scanf("%d",&N);
	 for(int i=0;i<N;i++)
		 scanf("%d",&h[i]);
	 printf("%lld\n",solve());
	return 0;
}

