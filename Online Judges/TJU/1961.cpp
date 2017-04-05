#include <bits/stdc++.h>
#define MAX 12009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define P(x)(x)*(x)
using namespace std;
typedef long long i64;
template <class T > string to_str(const T &n){
	stringstream ss;ss<<n;return ss.str();
}
struct cmp{
  bool operator()(const int &x,const int &y){
	  return x>y;
  }
};
struct cmp_string{
  bool operator()(const string &x,const string &y){
	  return x>y;
  }
};
int sum,n,arr[159],res,ok,test;
string cad;
map<string,int>M;
string cadenas[1<<17];
int t;
int main() {
	 while(scanf("%d %d",&sum,&n),sum+n){
		 M.clear();test=0;t=0;
		 for(int i=0;i<n;i++)
			 scanf("%d",&arr[i]);
		 printf("Sums of %d:\n",sum);
		 for(int mask=1;mask<(1<<n);mask++){
			 res=ok=0;
			 cad="";
			 for(int i=0;i<n;i++){
				 if(mask&(1<<i)){
					 res+=arr[i];
					 if(ok)cad+='+';
					 cad+=to_str(arr[i]);
					 ok=1;
				 }
			 }
			 if(sum==res&&!M[cad])
				 cadenas[t++]=cad,M[cad]=1,test=1;
		 }
		 sort(cadenas,cadenas+t,cmp_string());
		 for(int i=0;i<t;i++)
			 printf("%s\n",cadenas[i].c_str());
		 if(!test)
			 puts("NONE");
	 }
	return 0;
}