#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 20
#define oo 12345678
using namespace std;
typedef long long i64;
int dp[1<<18][18],g[20][20],shift[1<<20];
void TSP(int mask,int last){
	if(dp[mask][last]!=oo)
		return ;
	int i,j,tmp;
	dp[mask][last]--;
	for(int i=mask;i;i-=j){
		j=i&(-i);
		TSP(mask-j,shift[j]);
		tmp=dp[mask-j][shift[j]]+g[shift[j]][last];
		dp[mask][last]=min(tmp,dp[mask][last]);
	}
}
int x[20],y[20],n,l,a,cas;
int main()
{
	  scanf("%d",&cas);
	  while(cas--){
		  for(int i=0;i<18;i++){
			  shift[1<<i]=i;
		  }
		  scanf("%d%d",&l,&a);
		  scanf("%d%d",&x[0],&y[0]);
		  scanf("%d",&n);n++;
		  for(int i=1;i<n;i++)
			  scanf("%d%d",&x[i],&y[i]);
		  for(int i=0;i<n;i++)
			  for(int j=0;j<n;j++)
				  g[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]));

		  for(int i=1<<n;i>=0;i--)
			  for(int j=0;j<n;j++)
				  dp[i][j]=oo;
		  dp[0][0]=0;
		  TSP((1<<n)-1,0);
		  printf("The shortest path has length %d\n",dp[(1<<n)-1][0]);

	  }
}

