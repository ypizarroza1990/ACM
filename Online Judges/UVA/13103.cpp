#include <bits/stdc++.h>
#define i64 long long
using namespace std;
int K,bits;
int number[25];
i64 N,ans,temp;
int main() {
	//freopen("001.in","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>N){
		cin>>K;
		for(int i=0;i<K;i++)
			cin>>number[i];
		sort(number,number+K);
		bits = 0;
		for (int i=0;i<K;i++){
			if ((N >> number[i]) & 1){
				bits ++;
				N ^= 1LL << number[i];
			}
		}
		for (int i =(1 << K)-1;i>=0;i--){
			if(__builtin_popcount(i) != bits)
				continue;

			temp = N;
			for (int j = 0;j<K;j++){
				if ((i >> j) & 1)
					temp |= 1LL << number[j];
			}
			if (temp % 7 == 0){
				cout<< temp <<"\n";
				break;
			}

		}
	}
	return 0;
}
