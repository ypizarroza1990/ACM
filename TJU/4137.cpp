#include <cstdio>
int c[10], pow10[10];
void count(int x){
	int *cnt = c, d, dcnt = 0, r = 0, rem0 = 0, v;
	while(x){
		d = x % 10; x /= 10;
		if(dcnt){
			v = d * pow10[dcnt - 1] * dcnt;
			for(int i = 0; i < 10; ++i) cnt[i] += v;
			if(!d) rem0 += (pow10[dcnt] - 1) - r;
		}
		v = pow10[dcnt];
		for(int i = 1; i < d; ++i) cnt[i] += v;
		if(d) cnt[d] += r + 1;
		r = pow10[dcnt++] * d + r;
	}
	cnt[0] -= rem0;
}
int cas,a;
int main(void){
	pow10[0] = 1;
	for(int i = 1; i < 10; ++i) pow10[i] = 10 * pow10[i - 1];
	scanf("%d", &cas);
	for(int i=0;i<cas;i++){
		scanf("%d", &a);;
		for(int i = 0; i < 10; ++i) c[i] = 0;
		count(a);
		printf("%d\n", c[1]);
	}
	return 0;
}

