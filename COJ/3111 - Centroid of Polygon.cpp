#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793;
typedef complex<double> P;
#define X real()
#define Y imag()
typedef vector<P> Pol;
struct circle{
	P p; double r;
	circle(P p=0,double r=0):p(p),r(r){}
};
struct L: public vector <P> //Linea
{L(P a,P b){push_back(a); push_back(b);}};
bool cmp(const P a, const P b)
{return a.X!=b.X ?a.X<b.X :a.Y <b.Y;}
double cross(P a, P b)//1
{return a.X*b.Y-a.Y*b.X;}
double dot(P a, P b)//2
{return a.X*b.X + a.Y*b.Y;}
double area(Pol pol) {//25, 1
 double A = 0; int n = pol.size();
 for(int i=0;i<n;i++) A += cross(pol[i],pol[(i+1)%n]);
 return A / 2;
}
P ComputeCentroid(const Pol &pol) {
	P c(0,0);int n=pol.size();
	double scale = 6.0 * area(pol);
	for(int i=0;i<n;i++){
		int j = (i+1)%n;
		c += (pol[i] + pol[j])*cross(pol[i],pol[j]);
	}
	return c / scale;
}
int N;
double x,y;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	Pol poly;
	for(int i=0;i<N;i++){
		cin>>x>>y;
		poly.push_back(P(x,y));
	}
	P ans = ComputeCentroid(poly);

	cout<<"("<<setprecision(2)<<fixed<<ans.real()<<";"<<ans.imag()<<")\n";
	return 0;
}

