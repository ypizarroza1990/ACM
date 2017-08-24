#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const double eps = 1e-9;

struct point{
	i64 x,y;

	point(){}
	point(i64 _x, i64 _y) : x(_x), y(_y){}

	point operator-(point b){
		return point( x-b.x,y-b.y);
	}

};

i64 cross(point a, point b){
	return a.x * b.y - a.y * b.x;
}

i64 OnSegment(point P1,point P2){
	point P = P1-P2;
	int x = abs(P.x); int y = abs(P.y);

	return (__gcd(x,y));
}
int N;
i64 x,y;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin>>N && N){
		vector<point>P;
		for(int i=0;i<N;i++){
			cin>>x>>y;
			P.push_back(point(x,y));
		}


		i64 area = cross(P[N-1],P[0]);

		for(int i=0;i<N-1;i++)
			area += cross(P[i],P[i+1]);

		area = abs(area)/2;

		i64 I = OnSegment(P[N-1],P[0]);

		for(int i=0;i<N-1;i++)
			I += OnSegment(P[i],P[i+1]);


		cout<<(area + 1 - I/2)<<"\n";
	}
	return 0;
}
 
