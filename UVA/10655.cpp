#include <bits/stdc++.h>
using namespace std;
typedef long long int i64;
typedef long long u64;
void MUL(u64 A[2][2],u64 B[2][2],u64 C[2][2])
{
    u64 aux[2][2];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            aux[i][j]=0;
            for(int k=0;k<2;k++)
                aux[i][j]=(aux[i][j]+A[i][k]*B[k][j]);
        }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j]=aux[i][j];
}
u64 ans[2][2];
void POW(u64 A[2][2],u64 K)
{
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            ans[i][j]=(u64)(i==j);
    while(K){
        if(K&1)
            MUL(ans,A,ans);
        K>>=1;
        MUL(A,A,A);
    }
}
void Mostrar(u64 C[2][2],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}
u64 p,q,N;
int cas;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        while(cin>>p>>q>>N){
        if(N==0)
            cout<<"2\n";
        else{
            u64 M[2][2]={{p,-q},{1LL,0LL}};
            POW(M,N);
            cout<<u64(ans[1][0]*p+ans[1][1]*2)<<endl;
        }
    }
return 0;
}
 
