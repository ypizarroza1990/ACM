#include<bits/stdc++.h>
using namespace std;
string add(string a,string b){
	string res="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int la=a.size(),lb=b.size();
	for(int i=0,c=0;i<la||i<lb||c>0;i++){
		if(i<la)c+=a[i]-'0';
		if(i<lb)c+=b[i]-'0';
		res+='0'+c%10;
		c/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
string tiling[259];
void solve(){
	tiling[0]=tiling[1]="1";
	for(int i=2;i<=250;i++){
		tiling[i]="0";
		tiling[i]=add(tiling[i-1],tiling[i]);
		tiling[i]=add(tiling[i-2],tiling[i]);
		tiling[i]=add(tiling[i-2],tiling[i]);
	}
}
int main(){

	 int n;
	 solve();
	 while(scanf("%d",&n)==1){
		 printf("%s\n",tiling[n].c_str());
	 }
	return 0;
}

