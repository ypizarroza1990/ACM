#include <bits/stdc++.h>
using namespace std;

string add(string a,string b){
	string res="";
	if(a>b)swap(a,b);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int la=a.size(),lb=b.size();
	for(int i=0,c=0;i<la||i<lb||c>0;++i){
		if(i<la)c+=a[i]-'0';
		if(i<lb)c+=b[i]-'0';
		res+='0'+c%10;
		c/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
int cas;
string fibo[510];
void solve(){
	fibo[0]="1",fibo[1]="2";
	for(int i=2;i<509;i++){
		fibo[i]=add(fibo[i-2],fibo[i-1]);
	}
}
struct cmp_str{
	bool operator()(const string &a,const string &b){
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
int main()
{
	solve();
    int lo,hi;
    string a,b;
    while(cin>>a>>b){
    	if(a=="0" && b=="0")break;
    	lo=lower_bound(fibo,fibo+509,a,cmp_str())-fibo;
    	hi=upper_bound(fibo,fibo+509,b,cmp_str())-fibo;
    	printf("%d\n",hi-lo);
    }
    return 0;
}

