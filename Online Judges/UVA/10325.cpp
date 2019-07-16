#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'
typedef long long int i64;

int Array[16],N,M;
i64 sum;

i64 GCD(i64 a, i64 b){
	if(!b)
		return a;
	return GCD(b, a%b);
}

void solve(int pos,i64 val,int cnt){
	if(pos == M){
		if(cnt & 1)
			sum -= N/val;
		else
			sum += N/val;
	}
	if(val > N) return;
	solve(pos +1,val*Array[pos]/GCD(val,Array[pos]),cnt + 1);
	solve(pos+1,val,cnt+1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	while(cin>>N>>M){
		sum = 0;
		for(int i=0;i<M;i++)
			cin>>Array[i];
		solve(0,1LL,0);
		cout<<sum<<endl;
	}
	
	return 0;
}
