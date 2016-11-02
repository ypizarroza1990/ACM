 #include<bits/stdc++.h>
#define MAX 3000001
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
string cad;
int f[2170],sol[MAX],cas,N;
double A[MAX];
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	f[1940]=1;
	for(int i=1;i<MAX;i++){
		A[i]+=(A[i-1]+log10(i));
	}
	for(int i=1941;i<=2160;i++){
		f[i]=f[i-1];
		if(i%10==0)f[i]*=2;
	}
	for(int i=1;i<MAX;i++){
		sol[i]=(int)(A[i]/log10(2))+1;
	}
	while(cin>>N){
		if(!N)break;
		int pos=lower_bound(sol,sol+MAX,f[N])-sol;
		if(sol[pos]>f[N])pos--;
		cout<<pos<<"\n";
	}
	return 0;
}
