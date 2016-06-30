#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const double EPS =1e-8;
const double oo =1e12;
#define X real()
#define Y imag()
typedef complex<double> P;

struct L: public vector <P>{ //Linea
	L (P a, P b){
		push_back(a); push_back(b);
	}};


double dot(P a, P b){//2
	return (conj(a)*b).X;
}

//Proyeccion punto recta
P projection(L l,P p){//10,2
	double t=dot(p-l[0], l[0]-l[1])/norm(l[0]-l[1]);
	return l[0] + t*(l[0]-l[1]);
}

//Interseccion segmento y punto
bool intersectSP (L s,P p){//9
	double a=abs(s[0]-p)+abs(s[1]-p);
	return a-abs(s[1]-s[0])<EPS;
}
//Distancia segmento punto
double distanceSP(L s, P p){//15, 10 9
	const P r = projection(s,p);
	if (intersectSP(s,r)) return abs(r-p);
	return min( abs(s[0]-p), abs(s[1]-p) );
}

P A[109],B[109];
double dist=oo,d;
int cas,a,b;
P p;
int main(){
	scanf("%d",&cas);
	while(cas--){
		dist=oo;
		scanf("%d",&a);
		for(int i=0;i<a;i++){
			scanf("%lf%lf",&real(p),&imag(p));
			A[i]=p;
		}
		A[a]=(A[0]);
		scanf("%d",&b);
		for(int i=0;i<b;i++){
			scanf("%lf%lf",&real(p),&imag(p));
			B[i]=p;
		}
		B[b]=(B[0]);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++){
				d=distanceSP(L(B[j],B[(j+1)]),A[i]);
				dist=min(dist,d);
				d=distanceSP(L(A[i],A[(i+1)]),B[j]);
				dist=min(dist,d);
			}
		printf("%.8lf\n",dist/2);
	}
}

