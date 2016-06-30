#include <bits/stdc++.h>
using namespace std;
vector<long double> gauss(vector< vector<long double> >a, vector<long double> b) {
	int n = a.size();
	for (int row = 0; row < n; row++) {
		int best = row;
		for (int i = row + 1; i < n; i++)
			if (abs(a[best][row]) < abs(a[i][row]))
				best = i;
		vector<long double>tt = a[row];
		a[row] = a[best];
		a[best] = tt;
		double t = b[row];
		b[row] = b[best];
		b[best] = t;
		for (int i = row + 1; i < n; i++)
			a[row][i] /= a[row][row];
		b[row] /= a[row][row];
		// a[row][row] = 1;
		for (int i = 0; i < n; i++) {
			long double x = a[i][row];
			if (i != row && x != 0) {
				// row + 1 instead of row is an optimization
				for (int j = row + 1; j < n; j++)
					a[i][j] -= a[row][j] * x;
				b[i] -= b[row] * x;
			}
		}
	}
	return b;
}
int N;
long double x,num;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector< vector<long double> >a;
	vector<long double> b;
	a.resize(4);
	cin>>N;
	for(int i=0;i<4;i++){
		cin>>x>>num;
		for(int j=0;j<4;j++){
			a[i].push_back(pow(x,3-j));
		}
		b.push_back(num);
	}
	vector< vector<long double> > a1 = a;
	for (int i = 0; i < a.size(); i++)
		a1[i] = a[i];
	vector<long double>  b1 = b;
	vector<long double>  x = gauss(a, b);
	double y = 0;
	for (int i = 0; i < a.size(); i++) {
		 y+=x[i]*(pow(N,3-i));
	}
	cout<<(long long)round(y)<<"\n";
}

