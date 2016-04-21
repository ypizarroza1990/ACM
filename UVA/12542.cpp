#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
const int MAV = 100100;
int flag[MAV>>6],num,ans;
void Criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAV);i+=2){
		if(!ifc(i)){
			for(j = i*i,k=(i<<1);j<MAV;j += k)
				isc(j);
		}
	}
}
bool isprime(int n){
	if(n<2)return false;
	if(n==2)return true;
	if((n&1)&&!ifc(n))return true;
	return false;
}
string line,n;
int main() {
	Criba();
	while(cin>>line){
		if(line=="0")break;
		int l=line.size();ans=0;
		for(int k=0;k<l;k++){
			for(int i=k;i<l&&i<k+5;i++){
				n="";
				for(int j=k;j<=i&&j<i+5;j++)
					n+=line[j];
				num=atoi(n.c_str());
				if(isprime(num)){
					ans=max(ans,num);
				}
			}
		}
		printf("%d\n",ans);
	}

}
