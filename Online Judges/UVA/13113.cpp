#include <bits/stdc++.h>
#define EPS 1e-6
using namespace std;
typedef long long i64;
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
struct candidate{
	int id,elect;
	candidate(){};
	candidate(int i):id(i),elect(0){};
	void update(double porcent,int total){
		int val = (total*porcent)/100+0.5;
		elect+=val;
	}
	bool operator<(const candidate &c)const{
		return c.elect<elect;
	}
};
int cas,n,m;
vector<candidate>C;
vector<double>PorC[1501];
vector<int>E;
double x;
int y;
i64 total;
int main(){
	//freopen("001.in","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		C.clear();
		E.clear();
		cin>>n>>m;
		total=0;
		for(int j=0;j<m;j++)PorC[j].clear();
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				cin>>x;
				PorC[j].push_back(x);
			}
			cin>>y;
			E.push_back(y);
			total+=y;
		}
		for(int i=0;i<n;i++)
			C.push_back(candidate(i+1));
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				C[i].update(PorC[j][i],E[j]);
			}
		}
		sort(C.begin(),C.end());
		double temp1 = (C[0].elect*100.0)/total;
		if(temp1>=50.1){
			cout<<C[0].id<<" "<<C[0].elect<<"\n";
		}else{
			cout<<C[0].id<<" "<<C[0].elect<<"\n";
			cout<<C[1].id<<" "<<C[1].elect<<"\n";
		}
		if(cas)
			cout<<"\n";
	}

}


