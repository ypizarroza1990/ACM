#include <bits/stdc++.h>
#define MOD 1000003
using namespace std;
typedef long long i64;
vector<int>A;
string line,n;
int num;
int solve(vector<int>V){
	int max_a,max_r,i;
	max_a=max_r=0;
	for(int i=0;i<V.size();i++){
		max_a=max(V[i]+max_a,0);
		max_r=max(max_a,max_r);
	}
	return max_r;
}
int main() {
	while(getline(cin,line)){
		stringstream ss(line);
		A.clear();
		while(ss>>n){
			num=atoi(n.c_str());
			A.push_back(num);
		}
		cout<<solve(A)<<endl;
	}
}
