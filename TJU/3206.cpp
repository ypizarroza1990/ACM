#include <bits/stdc++.h>
#define MAX 12009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define P(x)(x)*(x)
using namespace std;
typedef long long i64;
template <class T > string to_str(const T &n){
	stringstream ss;ss<<n;return ss.str();
}
int arr[309],coins[10];
int n,m;
int main() {
	//freopen("A.in","r",stdin);
   scanf("%d%d",&n,&m);
   for(int i=0;i<m;i++)
	   scanf("%d",&coins[i]);
  arr[0]=1;
   for(int i=0;i<m;i++){
	   for(int j=coins[i];j<=n;j++){
		   arr[j]+=arr[j-coins[i]];
	   }
   }
	  printf("%d\n",arr[n]);
	return 0;
}
