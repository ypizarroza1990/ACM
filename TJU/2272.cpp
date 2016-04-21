#include <bits/stdc++.h>
using namespace std;
#define MAX 100009
#define LOG 18
typedef long long i64;
int M[LOG][MAX],Level[1<<(LOG)],prof[1<<(LOG)],first[1<<(LOG)];
int array[MAX],n;
void build(int node,int depth,int ini,int fin){
	prof[node]=depth;
	Level[node]=(fin-ini+1);
	first[node]=ini;
	if(ini==fin)M[depth][ini]=array[ini];
	else{
		int mid=(ini+fin)/2;
		build(2*node+1,depth+1,ini,mid);
		build(2*node+2,depth+1,mid+1,fin);

		int sz1=mid-ini+1,sz2=fin-mid;
		int ini1=ini,ini2=mid+1;
		int cont1=0,cont2=0;

		while(cont1<sz1&&cont2<sz2){
			if(M[depth+1][ini1+cont1]<M[depth+1][ini2+cont2]){
				M[depth][ini+cont1+cont2]=M[depth+1][ini1+cont1];
				cont1++;
			}else{
				M[depth][ini+cont1+cont2]=M[depth+1][ini2+cont2];
				cont2++;
			}
		}
		if(sz1==cont1){
			while(sz2!=cont2){
				M[depth][ini+cont1+cont2]=M[depth+1][ini2+cont2];
				cont2++;
			}
		}
		else{
			while(sz1!=cont1){
				M[depth][ini+cont1+cont2]=M[depth+1][ini1+cont1];
				cont1++;
			}
		}
	}
}

int num,nodes[LOG];
void get_nodes(int node,int ini,int fin,int min,int max){
	if(ini>max || fin<min)
		return;
	if(ini>=min && fin<=max){
		nodes[num]=node;
		++num;
	}else{
		int mid=(ini+fin)/2;
		get_nodes(2*node+1,ini,mid,min,max);
		get_nodes(2*node+2,mid+1,fin,min,max);
	}
}
int count(int idx,int val){
	int l=Level[idx],ini=first[idx],d=prof[idx];
	if(M[d][ini]>val)
		return 0;
	int lo=0,hi=l-1;
	while(lo!=hi){
		int mid=(hi+lo+1)/2;
		if(M[d][ini+mid]<=val)lo=mid;
		else hi=mid-1;
	}
	return lo+1;
}
int kth(int min,int max,int k){
	num=0;
	get_nodes(0,0,n-1,min,max);
	int lo=0,hi=n-1;
	while(lo!=hi){
		 int cont=0;
		int mid=(hi+lo)/2;
		for(int i=0;i<num;i++){
			cont+=count(nodes[i],array[mid]);
		}
		if(cont<k)lo=mid+1;
		else hi=mid;
	}
	return array[lo];
}
int main(){

	int m;
		scanf("%d %d",&n,&m);
		for(int i = 0;i<n;++i) scanf("%d",&array[i]);

		build(0,0,0,n-1);
		for(int i = 0;i<n;++i) array[i] = M[0][i];

		for(int i = 0,s,e,k;i<m;++i){
			scanf("%d %d %d",&s,&e,&k);
			printf("%d\n",kth(s-1,e-1,k));
		}
}

