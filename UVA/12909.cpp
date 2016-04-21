#include <bits/stdc++.h>
#define MAX 1000000000000000LL
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
vector<i64>num_Centers;
i64 num;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	num_Centers.push_back(0);
	num_Centers.push_back(1);
	for(int i = 2;num_Centers[i-1]<=MAX;i++)
	{
		num_Centers.push_back((num_Centers[i-1]*6-num_Centers[i-2]+2));
	}
	while(cin>>num && num){
		int sol = 0;
		for(int i=2;i<(int)num_Centers.size();i++)
			sol+=num_Centers[i]<=num;
		cout<<sol<<"\n";
	}
	return 0;
}
