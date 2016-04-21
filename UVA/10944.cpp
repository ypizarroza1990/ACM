#include<bits/stdc++.h>
#define MAX 20
#define oo 1e9
using namespace std;
typedef pair<int,int>PI;
typedef vector<int>VI;
typedef vector<PI>VPI;
int g[MAX][MAX],dp[1<<MAX][MAX],shift[1<<MAX],x[MAX],y[MAX];
void TSP(int state,int last){
	if(dp[state][last]!=oo)
		return;
	int i,j,tmp;
	dp[state][last]--;
	for(i=state;i;i-=j){
		j=i&(-i);
		TSP(state-j,shift[j]);
		tmp=dp[state-j][shift[j]]+g[shift[j]][last];
		dp[state][last]=min(tmp,dp[state][last]);
	}

}
char M[MAX][MAX];
int n,m,nuts;
int main(){

	while(scanf("%d%d",&n,&m)==2){
		nuts=1;
		for(int i=0;i<n;i++)
			scanf("%s",M[i]);
		for(int i=0;i<MAX;i++)
			shift[1<<i]=i;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if(M[i][j]=='#')
					x[nuts]=i,y[nuts++]=j;
				if(M[i][j]=='L')
					x[0]=i,y[0]=j;
			}

		for(int i=0;i<nuts;i++){
			for(int j=0;j<nuts;j++){
				for(int l=0;;l++){
					if(x[i]+l>=x[j]&&x[i]-l<=x[j]&&
							y[i]+l>=y[j]&&y[i]-l<=y[j]){
						g[i][j]=l;break;
					}
				}
			}
		}
		for(int i=1<<nuts;i>=0;i--)
			for(int j=0;j<nuts;j++)
				dp[i][j]=oo;
		dp[0][0]=0;
		TSP((1<<nuts)-1,0);
		cout<<dp[(1<<nuts)-1][0]<<endl;
	}

	return 0;
}

