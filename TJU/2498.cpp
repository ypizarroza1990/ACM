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
int n,m,pw[100],len;
void power(int b,int e){
	pw[len++]=1;
	int res;
	for(int i=1;i<=e;i++){
		res=0;
		for(int j=0;j<len;j++){
			res=pw[j]*b+res;
			pw[j]=res%1000;
			res/=1000;
		}
		if(res){
			pw[len++]=res;
		}
	}
}
int main() {
	while(scanf("%d%d",&n,&m),n+m){
		len=0;
		power(n,m);

		printf("%d",pw[len-1]);
		for(int i=len-2;i>=0;i--)
		printf("%.3d",pw[i]);
		printf("\n");
	}
	return 0;
}
