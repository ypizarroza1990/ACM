#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 mod = 1000000009LL;
void MULT(i64 A[3][3],i64 B[3][3],i64 C[3][3])
{
	i64 aux[3][3];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			aux[i][j] = 0;
			for(int k=0;k<3;k++){
				aux[i][j]=(aux[i][j]+A[i][k]*B[k][j])%mod;
			}
		}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			C[i][j]=aux[i][j];

}
i64 ans[3][3];
void POW(i64 A[3][3],i64 K)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ans[i][j]=(i==j);
	while(K)
	{
		if(K&1)
			MULT(ans,A,ans);
		K>>=1;
		MULT(A,A,A);
	}
}
void Mostrar(i64 C[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
}
i64 N;
int main()
{
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int Ti[3] = {2,1,0};
	while(cin>>N){
		if(N==0LL)break;
		if(N<=3){
			cout<<Ti[3-N]<<"\n";
		}
		else{
			i64 M [3][3] = {{1,1,1},{1,0,0},{0,1,0}};
			i64 res=0;
			POW(M,N-3);
			res += (ans[0][0]*Ti[0]+ans[0][1]*Ti[1]+ans[0][2]*Ti[2])%mod;
			res%=mod;
			cout<<res<<"\n";

		}
	}
	return 0;
}
 
