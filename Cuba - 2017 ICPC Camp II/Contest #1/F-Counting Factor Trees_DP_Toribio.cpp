#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
#define ALL 20010
#define SHIFT 10005
typedef long long Long;

vector<int> P;
int isC[40010];
unordered_map<int,Long> M;
vector< pair<int,int> > FAC(int N){
	vector<pair<int,int> >R;
	for(int i=0;P[i]*P[i]<= N && i< P.size();i++){
		if(N%P[i]==0){
			int cont = 0;
			while(N%P[i]==0){
				cont++;
				N/=P[i];
			}
			R.push_back(make_pair(P[i],cont));
		}
	}
	if(N>1)
		R.push_back(make_pair(N,1));
	
	return R;
}

void dfs(int id, int n, vector<pair<int,int>> &F, vector<int> &A){
	if(id == F.size()){
		A.push_back(n);
		return;
	}
	for (int i = 0; i <= F[id].second; ++i) {
		dfs(id+1, n, F, A);
		n *= F[id].first;
	}
}
vector<int> DIV(int n){
	vector<pair<int,int>> F = FAC(n);
	vector<int> R;
	dfs(0, 1, F, R);
	return R;
}
Long dp(int n){
	Long w = 0;
	if(M.count(n))return M[n];
	int isP = 1;
	if(n < 40000 && !isC[n])return 1; 
	for(int i = 0; P[i]*P[i] <= n && isP; ++i){
		if(n % P[i] == 0)isP = 0;
	}
	if(isP)return 1;
	// es compuesto
	vector<int> D = DIV(n);
	for(int d : D){
		if(d == 1 || d == n)continue;
		w += dp(d) * dp(n / d);
	}
	return M[n] = w;
}
int main() {
	for (int i = 2; i < 40000; ++i) {
		if(isC[i])continue;
		P.push_back(i);
		for(int j = 2*i; j < 40000; j += i){
			isC[j] = 1;
		}
	}

	int n;
	int tc;
	scanf("%d", &tc);
	while(tc-->0){
		scanf("%d", &n);
		vector<pair<int,int>> V = FAC(n);
		vector<int> p(V.size());
		for (int i = 0; i < V.size(); ++i) {
			p[i] = V[i].second;
		}
		sort(p.rbegin(), p.rend());
		Long n = 1;
		for (int i = 0; i < p.size(); ++i) {
			while(p[i]-->0){
				n *= P[i];
			}
		}
		printf("%lld\n", dp(n));
	}

}

