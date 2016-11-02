#include <bits/stdc++.h>
#define MAX 50001
using namespace std;
#define i64 long long
int cas,N,x;
i64 S;
int arrays[50001];
void update(int pos)
{
	for(int i=pos;i<MAX;i+=i&-i)
		arrays[i]+=1;
}
int query(int pos){
	int sum = 0;
	while(pos){
		sum+=arrays[pos];
		pos-=(pos&-pos);
	}
	return sum;
}
int A[MAX];
int main()
{
	 ios_base::sync_with_stdio(0);
	 cin.tie(0);
	 cin>>cas;
	 S = 0;
	 while(cas--)
	 {
		 cin>>N;
		 S = 0;
		 for(int i=0;i<N;i++){
			cin>>x;
			A[i]=x;
			update(x);
		 }
		 for(int i=0;i<N;i++)
			 S+=query(A[i]);
		 cout<<S<<'\n';
		 memset(arrays,0,sizeof(arrays));
	 }
	return 0;
}

