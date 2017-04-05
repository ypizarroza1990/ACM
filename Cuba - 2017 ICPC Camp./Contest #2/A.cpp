#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define MAXN 500005


struct node {
	int m, back;
	node(int mm=0, int bb=0) {
		m=mm, back=bb;
	}
};

int SIZE;
node nodes[MAXN];
int roots[MAXN];

int push(int m, int r) {
	SIZE++;
	nodes[SIZE] = node(m, r);
	nodes[SIZE].m += nodes[r].m;
	return SIZE;
}

int pop(int r) {
	SIZE++;
	return nodes[r].back;
}

int main() {

	//freopen("d.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	SIZE = -1;
	roots[0] = push(0, -1);

	int n;
	cin >> n;

	ll answer = 0;
	for (int i = 1; i <= n; i++) {

		int t, m;
		cin >> t >> m;
		if (m == 0)
			roots[i] = pop( roots[t] );
		else
			roots[i] = push(m, roots[t]);

		answer += nodes[ roots[i] ].m;
	}

	cout << answer << endl;

	return 0;
}
