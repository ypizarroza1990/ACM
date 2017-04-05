#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
string sum(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int la=a.size(),lb=b.size();
	string res="";
	for(int i=0,c=0;i<la||i<lb||c;i++){
		if(i<la)c+=(a[i]-'0');
		if(i<lb)c+=(b[i]-'0');
		res+=c%10+'0';
		c/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
int n;
string fibo[12000];
int main(){
	scanf("%d",&n);
	fibo[1]=fibo[2]="1";
	for(int i=3;i<=4790;i++)
	  fibo[i]=sum(fibo[i-1],fibo[i-2]);
	printf("%s\n",fibo[n].c_str());
	return 0;
}

