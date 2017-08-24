#include <bits/stdc++.h>
#define i64 long long
using namespace std;
i64 c[10], _pow10[10];
void count(int x){
    i64 *cnt = c, d, dcnt = 0, r = 0, rem0 = 0, v;
    while(x){
        d = x % 10; x /= 10;
        if(dcnt){
            v = d * _pow10[dcnt - 1] * dcnt;
            for(int i = 0; i < 10; ++i) cnt[i] += v;
            if(!d) rem0 += (_pow10[dcnt] - 1) - r;
        }
        v = _pow10[dcnt];
        for(int i = 1; i < d; ++i) cnt[i] += v;
        if(d) cnt[d] += r + 1;
        r = _pow10[dcnt++] * d + r;
    }
    cnt[0] -= rem0;
}
int main(void){
    _pow10[0] = 1;
    for(int i = 1; i < 10; ++i) _pow10[i] = 10 * _pow10[i - 1];
    int cas,b;
    scanf("%d",&cas);
    while(cas--){
    	scanf("%d",&b);
        for(int i = 0; i < 10; ++i) c[i] = 0;
        count(b);
        i64 sum = 0LL;
        for(int i = 1; i < 10; ++i){
            sum = (sum + i*c[i])%3;
        }
       sum==0?printf("YES\n"):printf("NO\n");
    }
    return 0;
}
 
