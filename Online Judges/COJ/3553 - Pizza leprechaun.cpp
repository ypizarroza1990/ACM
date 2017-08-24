#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000001111107
typedef long long LL;

inline LL mul_mod(LL a, LL b, LL mod) {
  assert(0 <= a && a < mod);
  assert(0 <= b && b < mod);
  if (mod < int(1e9)) return a * b % mod;
  LL k = (LL)((long double)a * b / mod);
  LL res = a * b - k * mod;
  res %= mod;
  if (res < 0) res += mod;
  return res;
}

LL pow_mod(LL a, LL n, LL m) {
  LL res = 1;
  for (a %= m; n; n >>= 1) {
    if (n & 1) res = mul_mod(res, a, m);
    a = mul_mod(a, a, m);
  }
  return res;
}
LL ToneLLi_Shanks(LL n, LL p) {
  if (p == 2) return (n & 1) ? 1 : -1;
  if (pow_mod(n, p >> 1, p) != 1) return -1;
  if (p & 2) return pow_mod(n, p + 1 >> 2, p);
  int s = __builtin_ctzll(p ^ 1);
  LL q = p >> s, z = 2;
  for (; pow_mod(z, p >> 1, p) == 1; ++z);
  LL c = pow_mod(z, q, p);
  LL r = pow_mod(n, q + 1 >> 1, p);
  LL t = pow_mod(n, q, p), tmp;
  for (int m = s, i; t != 1;) {
    for (i = 0, tmp = t; tmp != 1; ++i) tmp = tmp * tmp % p;
    for (; i < --m;) c = c * c % p;
    r = r * c % p;
    c = c * c % p;
    t = t * c % p;
  }
  return r;
}
LL n,a,b;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n){
		if(n == -1LL)
			break;
		a = ToneLLi_Shanks(n,MOD);
		if(n == 0 )
			cout<<"0\n";
		else if(a == -1LL)
			cout<<"DUENDE DIABOLICO"<<"\n";
		else{
			b = MOD-a;
			if(a>b)swap(a,b);
			cout<<a<<" "<<b<<"\n";
		}
	}
	return 0;
}

 
