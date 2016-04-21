#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;
struct edge{
        int to,from;
        double cost;
        edge(){};
        edge(int _to,int _from,double _cost):to(_to),from(_from),cost(_cost){};
        bool operator <(const edge E)const{
                return cost<E.cost;
        }
};
struct Djoin_set{
        int* rank;
        int* setSize;
        int*parent;
        int setnumber;
        Djoin_set(int n){
                rank = new int[n+9];
                parent = new int[n+9];
                setSize = new int [n+9];
                setnumber = n;
                memset(setSize,1,sizeof(setSize));
                for(int i=0;i<n;i++)
                        parent[i]=i;
        }
        int find(int x){
                return parent[x]==x?x:parent[x]=find(parent[x]);
        }
        bool equal(int x,int y){
                return find(x)==find(y);
        }
        void join(int x,int y){
                int x1=find(x),x2=find(y);
                if(x1==x2)
                        return;
                if(rank[x1]==rank[x2])
                        ++rank[x1];
                if(rank[1]<rank[x2])
                        swap(x1,x2);
                parent[x2]=parent[x1];
                setSize[x1]+=setSize[x2];
                setnumber--;
        }

};
vector<edge>edge_list;
double MST(int n){
        Djoin_set S(n);
        double res=0;
        sort(edge_list.begin(),edge_list.end());
        int sz=edge_list.size();
        for(int i=0;i<sz;i++){
                int f=edge_list[i].from;
                int t=edge_list[i].to;
                if(!S.equal(f,t)){
                        S.join(f,t);
                        res+=edge_list[i].cost;
                }
        }
        return res;
}
int n,m,x,y;
int x_c[1000],y_c[1000];
int main() {
        while(scanf("%d",&n)==1){
                for(int i=0;i<n;i++){
                        scanf("%d%d",&x_c[i],&y_c[i]);
                }
                for(int i=0;i<n-1;i++)
                        for(int j=i+1;j<n;j++)
                                edge_list.push_back(edge(i,j,hypot(x_c[i]-x_c[j],y_c[i]-y_c[j])));
                scanf("%d",&m);
                while(m--){
                        scanf("%d%d",&x,&y);
                        edge_list.push_back(edge(x-1,y-1,0));
                }
                printf("%.2lf\n",round(MST(n)*100)/100);
                edge_list.clear();
        }
        return 0;
}
