#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define LL long long
int cas;
LL n;
int bits_counts(LL n){
	int ans = 0;
	for(int i=0;1LL<<i <= n;i++)
		ans += (1LL<<i & n) != 0;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	cin>>cas;
	while(cas--){
		cin>>n;
		cout<<bits_counts(n)<<endl;
	}

	return 0;
}