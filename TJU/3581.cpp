#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iostream>
#define P(x)(x)*(x)
using namespace std;
struct toy{
	int id,joy,price;
	double frugal;
	toy(){};
	toy(int i,int j,int p){
		id=i;
		joy=j;
		price=p;
		frugal=(double)j/p;;
	}
	bool operator<(const toy T)const{
		return frugal>T.frugal;
	}
};
int n,x,y;
vector<toy>V;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	 scanf("%d%d",&x,&y);
    	 V.push_back(toy(i,x,y));
    }
    sort(V.begin(),V.end());
    int sol=0;
    for(int i=0;i<3;i++)
    	sol+=V[i].price;
    printf("%d\n",sol);
    for(int i=0;i<3;i++)
    	 printf("%d\n",V[i].id);
	return 0;
}
