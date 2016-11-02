#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 mod = 1000007;
void MULT(i64 A[4][4],i64 B[4][4],i64 C[4][4])
{
	i64 aux[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			aux[i][j] = 0;
			for(int k=0;k<4;k++){
				aux[i][j]=(aux[i][j]+A[i][k]*B[k][j])%mod;
			}
		}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			C[i][j]=aux[i][j];

}
i64 ans[4][4];
void POW(i64 A[4][4],int K)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			ans[i][j]=(i==j);
	while(K)
	{
		if(K&1)
			MULT(ans,A,ans);
		K>>=1;
		MULT(A,A,A);
	}
}
int a,b,c,N;
i64 rr[90];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
    i64 M [4][4] = {{0,1,2,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
    int Ti[4] = {3,1,1,1};
    if(N<=4){
    	cout<<Ti[4-N]<<"\n";
    }
    else{
    	i64 res=0;
    	POW(M,N-4);
    	res += (ans[0][0]*Ti[0]+ans[0][1]*Ti[1]+ans[0][2]*Ti[2]+ans[0][3]*Ti[3])%mod;
    	res%=mod;
    	cout<<res<<"\n";

    }
	return 0;
}

