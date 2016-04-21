#include<bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 31629
using namespace std;
typedef long long int i64;
i64 c[2][10],pot10[15];
void count(i64 x,bool up){
	i64 *cnt=c[up],d,dcnt=0,r=0,rem0=0,v;

	while(x){
		d=x%10;x/=10;
		if(dcnt){
			v=d*pot10[dcnt-1]*dcnt;
			cnt[0]+=v;
			if(!d)rem0+=(pot10[dcnt]-1)-r;
		}
		v=pot10[dcnt];
		if(d)cnt[d]+=r+1;
		r=pot10[dcnt++]*d+r;
	}
	cnt[0]-=rem0;
}
i64 a,b;
int main(){

	 pot10[0]=1;
	 for(int i=1;i<15;i++)
		 pot10[i]=10*pot10[i-1];
	 while(scanf("%lld%lld",&a,&b),a!=-1&&b!=-1){
		 c[0][0]=c[1][0]=0;
		 count(a-1,0);count(b,1);
		 printf("%lld\n",c[1][0]-c[0][0]+(a==0));
	 }
	return 0;
}

