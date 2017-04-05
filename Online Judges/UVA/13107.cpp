#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

string cad,ans;
int t;
bool mark[30];
int val[30];
string number[30];
string find(char a){
	int c;
	if(!mark[a-'a']){
		mark[a-'a']=1;
		c = val[a-'a']=t++;
	}else{
		c = val[a-'a'];
	}
	return number[c];

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<30;i++)
		number[i]=toStr(i);
	while(cin>>cad){
		t=1;
		ans="";
		for(int i=0;i<cad.size();i++){
			ans=find(cad[i]);
			for(int i=0;i<ans.size();i++){
				if(ans[i]=='2')cout<<'5';
				else if(ans[i]=='5')cout<<'2';
				else if(ans[i]=='6')cout<<'9';
				else if(ans[i]=='9')cout<<'6';
				else  cout<<ans[i];
			}
		}
		cout<<"\n";
		memset(mark,0,sizeof(mark));
		memset(val,0,sizeof(val));
	}
}
