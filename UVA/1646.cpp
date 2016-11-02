#include <bits/stdc++.h>

using namespace std;
string add(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string result="";
	int la=a.size(),lb=b.size();
	for(int i=0,c=0;i<la||i<lb||c>0;i++){
		if(i<la)c+=a[i]-'0';
		if(i<lb)c+=b[i]-'0';
		result+='0'+c%10;
		c/=10;
	}
	reverse(result.begin(),result.end());
	return result;
}
string fibo[10009];
void generate(){
	fibo[0]="1",fibo[1]="3";
	for(int i=2;i<10009;i++)
		fibo[i]=add(fibo[i-1],fibo[i-2]);
}
int n;
int main()
{
	generate();
	while(scanf("%d",&n)==1){
		printf("%s\n",fibo[n-1].c_str());
	}

}

