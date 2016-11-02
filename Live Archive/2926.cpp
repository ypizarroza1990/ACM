#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int tree[1005];
typedef pair<int,int>pi;
typedef long long i64;
void update(int pos,int val){
	for(;pos<=1001;pos+=(pos&-pos))
		tree[pos]+=val;
}
i64 querry(int pos){
	i64 sum=0;
	for(;pos>0;pos-=(pos&-pos))
		sum+=tree[pos];
	return sum;
}
int cas,x,y,a,b,e;
i64 cont;
vector<pi>array;
int main() {
	 scanf("%d",&cas);
	 for(int k=1;k<=cas;k++){
		 cont=0;
		 scanf("%d%d%d",&a,&b,&e);
		 for(int i=0;i<e;i++){
			 scanf("%d%d",&x,&y);
			 array.push_back(make_pair(x,y));
		 }
		 sort(array.begin(),array.end());
		 for(int i=0;i<e;i++){
			 cont+=i-querry(array[i].second);
			 update(array[i].second,1);
		 }
		 printf("Test case %d: %lld\n",k,cont);
		 array.clear();
		 memset(tree,0,sizeof(tree));
	 }
}
 