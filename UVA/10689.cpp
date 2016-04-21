#include <stdio.h>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void mult(ll A[2][2],ll B[2][2],ll C[2][2],int mod){
	ll aux[3][3];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			aux[i][j] = 0;
			for(int k=0;k<2;k++)
				aux[i][j] = (aux[i][j] + A[i][k] * B[k][j]) % mod;
		}
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			C[i][j] = aux[i][j];
}

ll ans[2][2];
void POW(int K,ll A[2][2],int mod){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			ans[i][j] = (i == j);
	while(K){
		if (K & 1)
			mult(ans, A, ans,mod);
		K /= 2;
		mult(A,A,A,mod);
	}
}
void Mostrar(ll C[2][2]){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
}
int N,a,b,n,m,cas,t=1;

int main()
{
	ll V[2] ;
	scanf("%d",&cas);
	while(cas--){
		ll A[2][2] = { {1,1},{1,0}};
		scanf("%lld%lld%d%d",&V[1],&V[0],&n,&m);
		int mod=(int)pow(10.0,m);
		if(n<2){
			cout<<V[!n]<<endl;
		}else{
			POW(n-2,A,mod);
			//Mostrar(A);

			ll salida = 0;
			salida += (ans[0][0]*V[0] + ans[0][1]*V[0]) % mod;
			salida += (ans[1][0]*V[1] + ans[1][1]*V[1] ) % mod;
			salida %= mod;

			cout << salida << endl;
		}
	}
}
 
