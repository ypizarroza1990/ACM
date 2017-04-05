#include<bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 31629
using namespace std;
void find_lis(vector<int> &a, vector<int> &b){
	vector<int> p(a.size());
	int u, v;
	if (a.empty()) return;
	b.push_back(0);
	for (size_t i = 1; i < a.size(); i++){
		if (a[b.back()] < a[i]){
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
		for (u = 0, v = b.size()-1; u < v;){
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
		if (a[i] < a[b[u]]){
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}
int cas,n,x;
int main(){
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);

		vector<int> lis,seq;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			seq.push_back(x);
		}
		find_lis(seq, lis);
		printf("%d\n",lis.size());
	}
	return 0;
}

