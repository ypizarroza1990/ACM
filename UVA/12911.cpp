#include <bits/stdc++.h>
using namespace std;
#define i64 long long
vector<i64> solve(vector<i64>V)
{
	  int sz=V.size();
	  vector<i64> ans;
	  i64 sum;
	  for(int mask=0;mask<(1<<sz);mask++){
		  sum=0LL;
		  for(int i=0;i<sz;i++){
			  if(mask&(1<<i))
				  sum+=V[i];
		  }
		  ans.push_back(sum);
	  }
	  return ans;
}
int N,sol,x;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>N>>sol){
		vector<i64>a,b;
		for(int i=0;i<N;i++){
			cin>>x;
			if(i<N/2)
				a.push_back(x);
			else
				b.push_back(x);
		}
		vector<i64>A=solve(a),B=solve(b);
		sort(A.begin(),A.end());
		int ans=0;
		for(vector<i64>::iterator it=B.begin();it!=B.end();it++){
			i64 temp=sol-*it;
			int p=lower_bound(A.begin(),A.end(),temp)-A.begin();
			int q=upper_bound(A.begin(),A.end(),temp)-A.begin();
			ans+=(q-p);
		}
		if(sol==0)ans--;
		cout<<ans<<"\n";
	}
	return 0;
}
 
