//============================================================================
// Name        : Run.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>
using namespace std;
#define ALL 20010
#define SHIFT 10005
typedef long long Long;
typedef vector<int> VI;
typedef vector<VI> VVI;
struct SAT2 {
	VVI adj, radj;
	VI vis, order, comp, sat;
	SAT2(int N){
		adj = VVI(2*N);
		radj = VVI(2*N);
	}
	void addImplication(int i, int j, int neg){
		i--;j--;
		adj[2*i+(neg>>1)].push_back(2*j+(neg&1));
		radj[2*j+(neg&1)].push_back(2*i+(neg>>1));
	}
	void dfs1(int u){
		vis[u] = 1;
		for(int v : adj[u]){
			if(!vis[v])
				dfs1(v);
		}
		order.push_back(u);
	}
	void dfs2(int u, int color){
		comp[u] = color;
		for(int v : radj[u]){
			if(comp[v] == -1)
				dfs2(v, color);
		}
	}
	bool run2SAT(){
		int N = adj.size();
		vis = VI(N);
		comp = VI(N, -1);
		sat = VI(N/2);
		for (int i = 0; i < N; ++i) {
			if(!vis[i])
				dfs1(i);
		}
		int c = 0;
		for (int i = 0; i < N; ++i) {
			int u = order[N-i-1];
			if(comp[u] == -1)
				dfs2(u, c++);
		}
		for (int i = 0; i < N; ++i) {
			if(comp[i] == comp[i^1])
				return false;
		}
		for (int i = 0; i < N; i += 2) {
			sat[i / 2] = comp[i] > comp[i ^ 1];
		}
		return true;
	}
};



int main() {
	
	
	int N,M;
	scanf("%d%d", &N, &M);
	SAT2 S(N);
	for (int i = 0; i < M; ++i) {
		int a,b;
		scanf("%d%d", &a, &b);
		if(a > 0 && b > 0){
			S.addImplication(abs(a), abs(b), 2);
			S.addImplication(abs(b), abs(a), 2);
		}else if(a < 0 && b < 0){
			S.addImplication(abs(a), abs(b), 1);
			S.addImplication(abs(b), abs(a), 1);
		}else if(a < 0 && b > 0){
			S.addImplication(abs(a), abs(b), 0);
			S.addImplication(abs(b), abs(a), 3);
		}else if(a > 0 && b < 0){
			S.addImplication(abs(a), abs(b), 3);
			S.addImplication(abs(b), abs(a), 0);
		}
	}
	cout << (S.run2SAT() ? "1" : "0") << endl;
}

 
