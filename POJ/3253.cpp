#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 1000000
using namespace std;
typedef long long i64;
priority_queue<i64>Q;
i64 sum,n,x,res=0;
void solve(){
	int a,b;
	while(Q.size()>1){
		a=Q.top();Q.pop();
		b=Q.top();Q.pop();
		res+=(a+b);
		Q.push((a+b));
	}
}
int main() {

		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			Q.push(-x);
		}
		solve();
		 printf("%lld\n",-res);

	return 0;
}
