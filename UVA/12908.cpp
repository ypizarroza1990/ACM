 
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
i64 N;
i64 Acum[14150];
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Acum[0]=0LL;
	for(i64 i=1LL;i<14150;i++){
		Acum[i]=Acum[i-1]+i;
	}
	while(cin>>N)
	{
		if(!N)break;
		int t=upper_bound(Acum,Acum+14143,N)-Acum;
		cout<<Acum[t]-N<<" "<<t<<"\n";
	}
	return 0;
}
