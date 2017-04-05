#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long i64;
i64 GCD(i64 a,i64 b){
	while(b){
		a%=b;
		a^=b^=a^=b;
	}
	return a;
}
i64 comb(i64 n,i64 r){
	i64 i,j,g,k=(r>n-r)?r:n-r,m=n-k,lob=1,hob=1;
	for(i=k+1,j=m;i<=n&&j>0;i++,j--){
		lob*=i;
		hob*=j;
		g=GCD(lob,hob);
		lob/=g;
		hob/=g;
	}
	return lob;
}
int cas;
i64 n,m;
i64 mem[1005];
i64 solve(int n){
    if(mem[n])
     return mem[n];
    if(n<6)
    	return mem[n]=(i64)pow(2.0,n-1);
    else
    	return mem[n]=comb(n,4)+comb(n,2)+1;

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	 cin>>cas;
	 while(cas--){
		 cin>>n;
	 cout<<solve(n)<<endl;;
	 }
}
