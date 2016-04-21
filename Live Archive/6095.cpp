#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
int ok;
char cad2[100];
void solve(string cad){
	long long sol=1;
	if(ok)printf(" ");
	printf("%s",cad.c_str());ok=1;
	for(int i=0;cad[i];i++)
		sol*=cad[i]-'0';
	if(sol>=10){
		sprintf(cad2,"%lld",sol);
		solve(cad2);
	}else{
		printf(" %d\n",sol);

	}
}
string cad;
int main() {
	while(1){
		cin>>cad;
		if(cad=="0")break;
		ok=0;
		if(cad.size()==1)cout<<cad<<endl;
		else
		solve(cad);
	}

}
