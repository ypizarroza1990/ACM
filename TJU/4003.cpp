#include <iostream>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

string add(string a,string b){
	string solve="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int la=a.size();
	int lb=b.size();
	for(int i=0,c=0;i<la||c;i++){
		if(i<la)c+=a[i]-'0';
		if(i<lb)c+=b[i]-'0';
		solve+=c%10+'0';
		c/=10;
	}
	reverse(solve.begin(),solve.end());
	return solve;
}
int main()
{
	int cas,sum;
	cin>>cas;
	string cad;
	while(cas--){
		cin>>cad;
		for(int i=1;;){
			sum=0;
			cad=add(cad,toStr(i));
			for(int j=0;cad[j];j++){
				sum=(sum+(cad[j]-'0'))%10;
			}
			if(sum==0)
				break;
		}
		cout<<cad<<endl;
	}
	return 0;
}

