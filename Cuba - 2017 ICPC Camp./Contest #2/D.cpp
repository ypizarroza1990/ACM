#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define INF 99999999
#define MAXN 200005

struct node {
	int count, diff, unique, L, R;
	node() {
		count = diff = unique = 0;
		L = R = -1;
	}
};

int SIZE, M;
node ST[50 * MAXN];
int roots[50 * MAXN];

//add +1 or -1
int update(int n, int i, int j, int qi, int qj, int v) {

	if (i > qj || j < qi)
		return n;

	int nn = ++SIZE;

	if (qi <= i && j <= qj) {
		ST[nn] = ST[n];
		if (ST[nn].count == 0 && v == -1)
			return nn;
		ST[nn].count += v;
		ST[nn].diff = (ST[nn].count != 0);
		ST[nn].unique = (ST[nn].count == 1);
		ST[nn].L = ST[nn].R = -1;
	} else {
		int mid = (i + j) >> 1;
		int L = update(ST[n].L, i, mid, qi, qj, v);
		int R = update(ST[n].R, mid + 1, j, qi, qj, v);
		ST[nn] = node();
		ST[nn].count = ST[L].count + ST[R].count;
		ST[nn].diff = ST[L].diff + ST[R].diff;
		ST[nn].unique = ST[L].unique + ST[R].unique;
		ST[nn].L = L;
		ST[nn].R = R;
	}

	return nn;
}

node query(int n, int i, int j, int qi, int qj) {

	if (i > qj || j < qi)
		return node();

	if (qi <= i && j <= qj) {
		return ST[n];
	} else {
		int mid = (i + j) >> 1;
		node L = query(ST[n].L, i, mid, qi, qj);
		node R = query(ST[n].R, mid + 1, j, qi, qj);
		node nod;
		nod.count = L.count + R.count;
		nod.diff = L.diff + R.diff;
		nod.unique = L.unique + R.unique;

		return nod;
	}

}

int main() {

	//freopen("d.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	SIZE = 0;

	int n, m;
	cin >> n >> m;

	int version = 1;

	string op;
	int a, b;

	ll s = 0;

	for (int i = 1; i <= n; i++) {
		cin >> op;
		if (op == "add") {
			cin >> a;
			roots[version] = update(roots[version - 1], 0, MAXN - 1, a, a, 1);
			version++;
		}
		if (op == "remove") {
			cin >> a;
			roots[version] = update(roots[version - 1], 0, MAXN - 1, a, a, -1);
			version++;
		}

		if (op == "different") {
			cin >> a;
			a = (a + s) % i;
			node q = query(roots[a], 0, MAXN - 1, 0, MAXN - 1);
			cout << q.diff << endl;
			s += q.diff;
			roots[version] = roots[version - 1];
			version++;
		}
		if (op == "unique") {
			cin >> a;
			a = (a + s) % i;
			node q = query(roots[a], 0, MAXN - 1, 0, MAXN - 1);
			cout << q.unique << endl;
			s += q.unique;
			roots[version] = roots[version - 1];
			version++;
		}
		if (op == "count") {
			cin >> a >> b;
			b = (b + s) % i;
			node q = query(roots[b], 0, MAXN - 1, a, a);
			cout << q.count << endl;
			s += q.count;
			roots[version] = roots[version - 1];
			version++;
		}
	}

	return 0;
}
