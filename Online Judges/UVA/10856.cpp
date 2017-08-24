#include <bits/stdc++.h>
using namespace std;
const int MAX = 3000000;
#define i64 long long
int primes[MAX];
 void criba(){
	 for(int i=2;i<MAX;i++){
		 if(!primes[i]){
			 primes[i]=1;
			 for(int j=2*i;j<MAX;j+=i){
				 primes[j] = primes[j/i]+1;
			 }
		 }
	 }
	 for(int i=1;i<MAX;i++)
		 primes[i]+=primes[i-1];
 }

int solve(int n){
	int lo = 0,hi = MAX;
	while(lo < hi){
		int mid=(lo+hi)>>1;
		if(primes[mid]< n)
			lo = mid+1;
		else
			hi = mid;
	}
	return (primes[lo]==n)?lo:-1;
}
int n,cas;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	while(cin>>n){
		if(n<0)break;
		int ans = solve(n);

		cout<<"Case "<<++cas<<": ";
		if(ans == -1)
			cout<<"Not possible.\n";
		else
			cout<<ans<<"!\n";
	}
	return 0;
}


