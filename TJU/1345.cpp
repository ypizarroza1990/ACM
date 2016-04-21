#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
struct cmp_str{
	bool operator()(const string &a ,const string &b){
		int la=a.size(),lb=b.size();
		if(la==lb){
			for(int i=0;i<la;i++){
				if(a[i]==b[i])continue;
				return a[i]<b[i];
			}
		}
		return la<lb;
	}
};
string add(string a ,string b){
	if(a>b)swap(a,b);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int la=a.size(),lb=b.size();
	string res="";
	for(int i=0,c=0;i<la||i<lb||c>0;i++){
		if(i<la)c+=(a[i]-'0');
		if(i<lb)c+=(b[i]-'0');
		res+=c%10+'0';
		c/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
string fibo[509];
int main(){

	 fibo[0]="1",fibo[1]="2";
	 for(int i=2;i<509;i++)
		 fibo[i]=add(fibo[i-2],fibo[i-1]);
	 string a,b;
	 while(cin>>a>>b){
		 if(a=="0" && b=="0")break;
		 int lo=lower_bound(fibo,fibo+509,a,cmp_str())-fibo;
		 int hi=upper_bound(fibo,fibo+509,b,cmp_str())-fibo;
		 printf("%d\n",hi-lo);
	 }

	return 0;
}

