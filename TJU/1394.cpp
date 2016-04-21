#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int f[1000009],ans;
void prefix(string cad){
	f[0]=0;
	int n=cad.size(),k=0;
	for(int i=1;i<n;i++){
		while(k>0 && cad[i]!=cad[k])k=f[k-1];
		if(cad[i]==cad[k])k++;
		f[i]=k;
	}
}
int main(void){
	 string cad;
	 while(cin>>cad){
		 ans=1;
		 if(cad==".")break;
		 prefix(cad);
		 int len=cad.length();
		 int s=len-f[len-1];
		 if(len>s&&len%s==0)ans=len/s;
		 cout<<ans<<endl;
	 }
    return 0;
}
