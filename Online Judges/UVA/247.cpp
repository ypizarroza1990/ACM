//============================================================================
// Name        : UVA.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <stack>
#define MAXN 150
using namespace std;
vector<vector<int> >g;
map<int,vector<string> >M;
map<string,int>name;
map<int,string>num;
int d[MAXN], low[MAXN], scc[MAXN],n,m,c,cont=1;
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;
int findS(string s){
	if(name[s])return name[s];
	else{
		c++;
		name[s]=c;
		return c;
	}
}
string findN(int s){
	return num[s];
}
void init(){
	memset(d,-1,sizeof(d));
	ticks=current_scc=0;
	while(!s.empty()){
		s.pop();
	}
}
void tarjan(int u){
	d[u] = low[u] = ticks++;
	s.push(u);
	stacked[u] = true;
	const vector<int> &out = g[u];
	for (int k=0, m=out.size(); k<m; ++k){
		const int &v = out[k];
		if (d[v] == -1){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if (stacked[v]){
			low[u] = min(low[u], low[v]);
		}
	}
	if (d[u] == low[u]){
		int v;
		do{
			v = s.top();
			s.pop();
			stacked[v] = false;
			scc[v] = current_scc;
			M[current_scc].push_back(findN(v));
			//printf("%s\n",findN(v).c_str());
		}while (u != v);
		current_scc++;
	}
}
char nam[50],na[50];
int main(){
	//freopen("entrada.in","r",stdin);
	//freopen("salida.out","w",stdout);
	while(scanf("%d%d",&n,&m),m+n){
		if(cont>1)
			printf("\n");
		init();
		c=0;
		M.clear();
		name.clear();
		g.clear();
		g.resize(n+10);
		for(int i=0;i<m;i++){
			scanf("%s%s",nam,na);
			int u=findS(string(nam));
			int v=findS(string(na));
			num[u]=string(nam);
			num[v]=string(na);
			g[u].push_back(v);

		}
		for(int i=0;i<=n;i++){
			if(d[i]==-1){
				tarjan(i);
			}
		}
		printf("Calling circles for data set %d:\n",cont++);
		for(int i=current_scc-1;i>0;i--){
			for(int j=M[i].size()-1;j>0;j--)
				printf("%s, ",M[i][j].c_str());
			printf("%s\n",M[i][0].c_str());
		}
	}
	return 0;
}

