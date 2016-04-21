#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include <stack>
#include <vector>
#define MAXN 1120
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
void line_line_intersection(double x0, double y0,
double x1, double y1,
double x2, double y2,
double x3, double y3){
#ifndef EPS
#define EPS 1e-9
#endif
double t0 = (y3-y2)*(x0-x2)-(x3-x2)*(y0-y2);
double t1 = (x1-x0)*(y2-y0)-(y1-y0)*(x2-x0);
double det = (y1-y0)*(x3-x2)-(y3-y2)*(x1-x0);
if (fabs(det) < EPS){
if (fabs(t0) < EPS || fabs(t1) < EPS){

	printf("LINE\n");
	}else{

	printf("NONE\n");
	}
	}else{
	t0 /= det;
	t1 /= det;
	double x = x0 + t0*(x1-x0);
	double y = y0 + t0*(y1-y0);

	printf("POINT %.2lf %.2lf\n", x, y);
	}
}
int cas;
double x0,x1,x2,x3,y01,y11,y2,y3;
int main(){
	scanf("%d",&cas);
	puts("INTERSECTING LINES OUTPUT");
	while(cas--){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x0,&y01,&x1,&y11,&x2,&y2,&x3,&y3);
		line_line_intersection(x0,y01,x1,y11,x2,y2,x3,y3);
	}
	puts("END OF OUTPUT");
	return 0;
}



