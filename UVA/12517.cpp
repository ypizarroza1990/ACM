#include <bits/stdc++.h>
#define MAX_V 1500
using namespace std;
typedef long long i64;
int c[2][10], powe10[10];
void count(int x, bool up){
	int *cnt = c[up], d, dcnt = 0, r = 0, rem0 = 0,
			v;
	while(x){
		d = x % 10; x /= 10;
		if(dcnt){
			v = d * powe10[dcnt - 1] * dcnt;
			for(int i = 0; i < 10; ++i) cnt[i] += v;
			if(!d) rem0 += (powe10[dcnt] - 1) - r;
		}
		v = powe10[dcnt];
		for(int i = 1; i < d; ++i) cnt[i] += v;
		if(d) cnt[d] += r + 1;
		r = powe10[dcnt++] * d + r;
	}
	cnt[0] -= rem0;
}
int main(void){
	powe10[0] = 1;
	for(int i = 1; i < 10; ++i) powe10[i] = 10 *
			powe10[i - 1];
	for(int a, b; scanf("%d %d", &a, &b) == 2 && (a
			|| b); ){
		if(a > b) b ^= a ^= b ^= a;
		for(int i = 0; i < 10; ++i) c[0][i] = c[1][i]
		                                           = 0;
		count(b, 1);
		count(a - 1, 0);
		i64 sum=0;
		for(int i = 1; i < 10; ++i){
			sum+=i64(c[1][i] - c[0][i])*i;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
