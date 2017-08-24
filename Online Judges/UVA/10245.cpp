#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define px second
#define py first
typedef pair<double, double> point;

int N;
point P[MAX_N];
multiset<point> box;

bool compare_x(point a, point b){ return a.px<b.px; }

inline double dist(point a, point b){
    return	sqrt((a.px-b.px)*(a.px-b.px)+(a.py-b.py)*(a.py-b.py));
}

double closest_pair(){
    if(N<=1) return -1;

    sort(P,P+N,compare_x);

    double ret = dist(P[0],P[1]);
    box.insert(P[0]);

    set<point> :: iterator it;

    for(int i = 1,left = 0;i<N;++i){
        while(left<i && P[i].px-P[left].px>ret) box.erase(P[left++]);

        for(it = box.lower_bound(make_pair(P[i].py-ret,P[i].px-ret));it!=box.end() && P[i].py+ret>=(*it).py;++it)
                ret = min(ret, dist(P[i],*it));
        box.insert(P[i]);
    }

    return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>N){
		if(N == 0)break;
		for(int i=0;i<N;i++){
			cin>>P[i].px>>P[i].py;
		}
		double ans = closest_pair();
		if(ans>=1e4 || ans < 0)
			cout<<"INFINITY\n";
		else{
			cout<<setprecision(4)<<fixed<<ans<<"\n";
		}
		box.clear();
	}
}
 
