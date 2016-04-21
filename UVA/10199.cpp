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
#include <cstdlib>
#include <map>
#include <algorithm>
#define MAX 150
using namespace std;
map<string,int>M;
map<int,string>N;
int ndfs, vdfs[MAX], low[MAX],res,n,m,cont=1;
bool apoint[MAX];
vector<vector<int> > G;
vector<string>citynames;
int findString(string S){
	return M[S];
}
string findName(int n){
	return N[n];
}
void tarjan(int u, int p = -1){
	int v;
	low[u]=vdfs[u]=ndfs++;
	for(int i=G[u].size()-1;i>=0;i--){
		v=G[u][i];
		if(!vdfs[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if((vdfs[u]==1 && vdfs[v]>2) ||(vdfs[u]!=1 && vdfs[u]<=low[v]))
				apoint[u]=true;
		}else if(v!=p)low[u]=min(low[u],vdfs[v]);
	}
}
void BCC(int n){
	res=0;
	citynames.clear();
	for(int i = 0; i <=n; ++i) vdfs[i] = apoint[i] = 0;
	for(int i = 0; i <=n; ++i)
		if(!vdfs[i]){
			ndfs = 1;
			tarjan(i);
		}
	for(int i = 0; i <=n; ++i){
		if(apoint[i]){
			res++;
			citynames.push_back(findName(i));
		}
	}
}
char city[50],to[50];
int main(){
	//freopen("entrada.in","r",stdin);
	//freopen("salida.out","w",stdout);
	while(scanf("%d",&n),n){
		if(cont>1)
			printf("\n");
		G.clear();
		G.resize(n+10);
		for(int i=0;i<n;i++){
			scanf("%s",city);
			M[string(city)]=i;
			N[i]=string(city);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%s%s",city,to);
			int u=findString(string(city));
			int v=findString(string(to));
			G[u].push_back(v);
			G[v].push_back(u);
		}
		BCC(n);
		sort(citynames.begin(),citynames.end());
		printf("City map #%d: %d camera(s) found\n",cont++,res);
		for(int i=0;i<citynames.size();i++)
			printf("%s\n",citynames[i].c_str());

	}
	return 0;
}

