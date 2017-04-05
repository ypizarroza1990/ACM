 #include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template<typename T>
T gcd(T a, T b) {
  return !b ? a : gcd(b, a % b);
}

LL pow_mod(LL a, LL n, LL m) {
  LL res = 1;
  for (a %= m; n; n >>= 1) {
    if (n & 1) res = res * a % m;
    a = a * a % m;
  }
  return res;
}

LL euler_phi(LL n) {
  LL ret = n;
  for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
    ret = ret / i * (i - 1);
    while (n % i == 0) n /= i;
  }
  if (n > 1) ret = ret / n * (n - 1);
  return ret;
}


LL log(LL a, LL r, LL m){
  if (r >= m) return -1;
  LL i, g, x, c = 0, at = int(2 + sqrt(m));
  for (i = 0, x = 1 % m; i < 50; ++i) {
    if (x == r) return i;
    x = LL(x) * a % m;
  }
  for (g = x = 1; gcd(LL(x) * a % m, m) != g; ++c) {
    x = x * a % m;
    g = gcd(x, m);
  }
  if (r % g) return -1;
  if (x == r) return c;
  map<LL, LL> u;
  g = euler_phi(m / g), u[x] = 0;
  g = pow_mod(a, g - at % g, m);
  for (i = 1; i < at; ++i){ // Baby Step
    x = x * a % m;
    u.insert(make_pair(x, i));
    if (x == r) return c + i;
  }
  for (i = 1; i < at; ++i) { // Giant Step
    r = r * g % m;
    map<LL,LL>::iterator t = u.find(r);
    if (t != u.end()) return c + i * at + t->second;
  }
  return -1;
}
int N,B,P;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>P>>B>>N){
		LL ans = log(B,N,P);
		if(ans==-1)
			cout<<"no solution\n";
		else
			cout<<ans<<"\n";
	}
	return 0;
}

