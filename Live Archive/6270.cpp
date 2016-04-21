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
string fibo[10009];
void solve(){
	fibo[1]="1",fibo[2]="3";
	for(int i=3;i<10009;i++){
		fibo[i]=add(fibo[i-2],fibo[i-1]);
	}
}
struct cmp_str{
	bool operator()(const string &a,const string &b){
		int la=a.size(),lb=b.size();
		if(la!=lb){
			return la<lb;
		}
		return a<b;
	}
};
int main()
{
	solve();
    int a;
    while(scanf("%d",&a)==1){
    	printf("%s\n",fibo[a].c_str());
    }
    return 0;
}

