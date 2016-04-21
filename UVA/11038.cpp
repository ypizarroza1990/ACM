#include <bits/stdc++.h>
#define MAX 10009
using namespace std;
typedef long long i64;
i64 c[2][10],pow_ten[15];
void count(i64 x,bool up){
	i64* cnt=c[up],d,dcnt=0,r=0,rem0=0,v;
	while(x){
		d=x%10;x/=10;
		if(dcnt){
			v=d*pow_ten[dcnt-1]*dcnt;
			cnt[0]+=v;
			if(!d)rem0+=(pow_ten[dcnt]-1)-r;
		}
		v=pow_ten[dcnt];
		if(d)cnt[d]+=r+1;
		r=pow_ten[dcnt++]*d+r;
	}
	cnt[0]-=rem0;
}
i64 a,b;
int main() {

	pow_ten[0]=1;
	for(int i=1;i<11;i++)
		pow_ten[i]=10*pow_ten[i-1];

	 while(1){
		 cin>>a>>b;
		 if(a==-1 && b==-1)break;
		 c[0][0]=c[1][0]=0;
		 count(b,1);count(a-1,0);
		 cout<<c[1][0]-c[0][0]+(a==0)<<endl;
	 }

	return 0;
}

