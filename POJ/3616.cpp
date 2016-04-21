#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long i64;
struct event{
	int start,end,cost;
	event(){};
	event(int s,int e,int w):start(s),end(e),cost(w){};
	bool operator<(const event E)const{
		return end<E.end;
	}
};
event interv[1009];
int N,M,R;
int main()
{
	scanf("%d%d%d",&N,&M,&R);
	int best[1009],sol=0;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&interv[i].start,&interv[i].end,&interv[i].cost);
	}
	 sort(interv,interv+M);
	 for(int i=0;i<M;i++){
		 best[i]=interv[i].cost;
		 for(int j=0;j<i;j++)
			 if(interv[j].end+R<=interv[i].start && best[i]<best[j]+interv[i].cost){
				 best[i]=best[j]+interv[i].cost;
				 sol=max(sol,best[i]);
			 }
	 }
	 printf("%d\n",sol);
	return 0;
}

