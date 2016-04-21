#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
int add(string a ,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int la=a.size(),lb=b.size();
	int res=0;
	for(int i=0,c=0;i<la||i<lb||c>0;i++){
		if(i<la)c+=(a[i]-'0');
		if(i<lb)c+=(b[i]-'0');
		c/=10;
		if(c)res++;
	}
	return res;
}

int main(){

	 string a,b;
	 while(cin>>a>>b){
		 if(a=="0" && b=="0")break;
		  int sol=add(a,b);
		  if(sol==0)
			  puts("No carry operation.");
		  else if(sol==1)
			  puts("1 carry operation.");
		  else
			  printf("%d carry operations.\n",sol);
	 }

	return 0;
}

