#include <bits/stdc++.h>


typedef long long i64;

using namespace std;

string add(string a,string b){

	int sa=a.size(),sb=b.size();
	int len=max(sa,sb)+1;
	string c(len,'0');

	if(a.size()!=len-1) a=string(len-a.size()-1,'0')+a;
	if(b.size()!=len-1) b=string(len-b.size()-1,'0')+b;

	for(int i=len-2;i>=0;i--){
		int cur=c[i+1]-'0';
		int inc=(a[i]-'0')+(b[i]-'0');
		int to_cur=(cur+inc)%10;
		int to_next=(cur+inc)/10;
		c[i+1]=to_cur+'0';
		c[i]=to_next+'0';
	}
	while(c.size()>0 && c[0]=='0')c.erase(0,1);
	return c;
}
string multiply_E(string a,int scalar){
	reverse(a.begin(),a.end());
	int la=a.size();
	string res="";
	for(int i=0,c=0;i<la||c>0;i++){
		if(i<la)c+=(a[i]-'0')*scalar;
		res+='0'+c%10;
		c/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
string multiply_N(string a,string b){
	if(a.size()<b.size())
		swap(a,b);
	string res="0",mm="";
	int lb=b.size();
	reverse(b.begin(),b.end());
	for(int i=0;i<lb;i++){
		mm=multiply_E(a,(b[i]-'0'));
		if(i)mm+=string(i,'0');
		res=add(mm,res);
	}
	return res;
}
string Pascal[60][60];
string Bell[60];
int N;
int main(){

	for(int i=0;i<55;i++)Pascal[i][0]="1";
	for(int i=0;i<55;i++)Pascal[i][i]="1";
	for(int i=2;i<55;i++)
		for(int j=1;j<i;j++)
			Pascal[i][j]=add(Pascal[i-1][j],Pascal[i-1][j-1]);

	Bell[0]=Bell[1]="1";
	string sum;
	for(int i=1;i<55;i++){
		sum="0";
		for(int j=0;j<=i;j++){
			sum=add(sum,multiply_N(Bell[j],Pascal[i][j]));
		}
		Bell[i+1]=sum;
	}

	while(true){
		scanf("%d",&N);
		if(N==0) break;
		printf("%d %s\n",N,Bell[N].c_str());
	}
	return 0;
}

 
