#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define INF 99999999
#define MAXN 100005

struct node {
	int v, L, R;
	node(int vv=0, int LL=0, int RR=0) {
		v=vv,L=LL,R=RR;
	}
};

int SIZE;
node ST[50*MAXN];
int N, A[MAXN], M;
int roots[50*MAXN];

int update(int n, int i, int j, int qi, int qj, int v) {

	if (i > qj || j < qi )
		return n;

	int nn = ++SIZE;

	if (qi <= i && j <= qj) {
		ST[nn] = node(v, -1, -1);
	}else {
		int mid = (i+j)>>1;
		int L = update(ST[n].L, i, mid, qi, qj, v);
		int R = update(ST[n].R, mid+1, j, qi, qj, v);
		ST[nn] = node(-1, L, R);
	}

	return nn;
}

int query(int n, int i, int j, int qi, int qj) {

	if (i > qj || j < qi )
		return -1;

	if (qi <= i && j <= qj) {
		return ST[n].v;
	}else {
		int mid = (i+j)>>1;
		int L = query(ST[n].L, i, mid, qi, qj);
		int R = query(ST[n].R, mid+1, j, qi, qj);
		return max(L,R);
	}

}



int main() {

	//freopen("d.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	SIZE = 0;
	cin >> N;
	roots[0]=0;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
		roots[i]= update(roots[i-1],1,N,i,i,A[i]);
	}

	cin >> M;
	int k = N;
	while(M--){
		char s[20]={0};
		cin >> s;
		if(s[0]=='c'){
			k++;
			int a,b,c;
			cin >> a >> b >> c;
			roots[k] = update(roots[a+N-1],1,N,b,b,c);
		}else{
			int i, j;
			cin >> i >> j;
			int ans = query(roots[i+N-1],1,N,j,j);
			cout << ans << endl;
		}
	}


	return 0;
}
