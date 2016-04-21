#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 mod;
void MULT(i64 A[16][16],i64 B[16][16],i64 C[16][16],int m)
{
	i64 aux[m][m];
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++){
			aux[i][j] = 0;
			for(int k=0;k<m;k++){
				aux[i][j]=(aux[i][j]+A[i][k]*B[k][j])%mod;
			}
		}
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			C[i][j]=aux[i][j];

}
i64 ans[16][16];
void POW(i64 A[16][16],i64 K,int m)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			ans[i][j]=(i==j);
	while(K)
	{
		if(K&1)
			MULT(ans,A,ans,m);
		K>>=1;
		MULT(A,A,A,m);
	}
}
void Mostrar(i64 C[16][16],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
}
i64 N;
int cas,n;
i64 M[16][16];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int Ti[16];
	while(cin>>n>>N>>mod){
		if(n+N+mod==0)break;
		for(int i=0;i<n;i++)
			cin>>M[0][i];
		for(int i=n-1;i>=0;i--)
			cin>>Ti[i];
		for(int i=1;i<n;i++)
			for(int j=0;j<n;j++)
				if(j==(i-1))
					M[i][j]=1;
		if(N<=n){
			cout<<Ti[n-N]<<"\n";
		}
		else{
			i64 res=0;
			POW(M,N-n,n);
			for(int i=0;i<n;i++)
			res += (ans[0][i]*Ti[i])%mod;
			res%=mod;
			cout<<res<<"\n";

		}
		memset(M,0,sizeof(M));
	}
	return 0;
}
