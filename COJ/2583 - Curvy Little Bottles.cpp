#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<iostream>
#include<map>
#include<sstream>
#define ERROR 1e-4
using namespace std;
typedef  long long  i64;
vector<double>poly,integral,polysq;
double evaluate(vector<double>&poly,double x){
	int sz=poly.size();
	double ans=0.0;
	for(int i=1;i<sz;i++){
		ans+=poly[i]*pow(x,i);
	}
	return ans;
}
double volume(vector<double>&poly,double min_val,double max_val){
	return M_PI*(evaluate(poly,max_val)-evaluate(poly,min_val));
}
double binary_search(vector<double>&poly,double target,double min_val,double low,double high){
	double mid=(low+high)/2;
	while(high-low>ERROR){
		mid=(low+high)/2;
		double val=volume(poly,min_val,mid);
		if(val<target)
			low=mid;
		else if(val>target)
			high=mid;
		else
			return mid;
	}
	return mid;
}
int grado,sz,kases=1;
double x,low,high,inc;
int main(){
	while(scanf("%d",&grado)==1){
		for(int i=0;i<=grado;i++){
			scanf("%lf",&x);
			poly.push_back(x);
		}
		sz=poly.size();
		polysq.resize(2*grado+1,0);
		for(int i=0;i<sz;i++)
			for(int j=0;j<sz;j++){
				polysq[i+j]+=(poly[i]*poly[j]);
			}
		integral.resize(2*grado+2);
		integral[0]=0;
		sz=polysq.size();
		for(int i=0;i<sz;i++)
			integral[i+1]=(polysq[i]/(i+1));
		scanf("%lf%lf%lf",&low,&high,&inc);
		double total=volume(integral,low,high);
		printf("Case %d: %.2lf\n",kases++,total);
		if(total<inc)
			puts("insufficient volume");
		else{
			int mark=total/inc;
			mark=mark>8?8:mark;
			double newval=low;
			for(int i=0;i<mark;i++){
				double target=(i+1)*inc;
				newval= binary_search(integral,target,low,newval,high);
				printf("%.2lf",newval-low);
				if(i<mark-1)
					printf(" ");
			}
			printf("\n");
		}
		poly.clear();
		polysq.clear();
		integral.clear();
	}
	return 0;
}


