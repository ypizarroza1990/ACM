#include <bits/stdc++.h>
#define EPS 1e-6
using namespace std;
typedef long long i64;
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
//Point
//Choose one of these two:
struct P {
	double x, y; P(){}; P(double q, double w) : x(q), y(w){}
};

double polarAngle( P p )
{
	if(fabs(p.x) <= EPS && fabs(p.y) <= EPS) return -1.0;
	if(fabs(p.x) <= EPS) return (p.y > EPS ? 1.0 : 3.0) * acos(0);
	double theta = atan(1.0 * p.y / p.x);
	if(p.x > EPS) return(p.y >= -EPS ? theta : (4*acos(0) + theta));
	return(2 * acos( 0 ) + theta);
}

bool pointInPoly( P p, vector< P > &poly )
{
	int n = poly.size();
	double ang = 0.0;
	for(int i = n - 1, j = 0; j < n; i = j++){
		P v( poly[i].x - p.x, poly[i].y - p.y );
		P w( poly[j].x - p.x, poly[j].y - p.y );
		double va = polarAngle(v);
		double wa = polarAngle(w);
		double xx = wa - va;
		if(va < -0.5 || wa < -0.5 || fabs(fabs(xx)-2*acos(0)) < EPS){
			// POINT IS ON THE EDGE
			return false;
			ang += 2 * acos( 0 );
			continue;
		}
		if( xx < -2 * acos( 0 ) ) ang += xx + 4 * acos( 0 );
		else if( xx > 2 * acos( 0 ) ) ang += xx - 4 * acos( 0 );
		else ang += xx;
	}
	return( ang * ang > 1.0 );
}
int cas,n,m;
vector<P>points;
double x,y;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		points.clear();
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			points.push_back(P(x,y));
		}
		int ans=0;
		while(m--){
			cin>>x>>y;
			ans+=pointInPoly(P(x,y),points);
		}
		cout<<ans<<'\n';
	}

}

