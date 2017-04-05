#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define INF 99999999
#define MAX 100005

vector<int> tree[4*MAX];
int A[MAX];
int N, M, Q;
int next[MAX];
map<int,int> MAP;

void merge(int ini, int fin, int node){

	int left =0, right =0;
	int SIZELEFT = tree[2*node].size();
	int SIZERIGHT = tree[2*node+1].size();

	for(int i = ini; i <= fin; i++){
		if(left < SIZELEFT && (right == SIZERIGHT || tree[2*node][left] <= tree[2*node+1][right])){
			tree[node].push_back(tree[2*node][left]);
			left++;
		}else if (right < SIZERIGHT && (left == SIZELEFT || tree[2*node+1][right] < tree[2*node][left])){
			tree[node].push_back(tree[2*node+1][right]);
			right++;
		}
	}

}

void create(int ini, int fin, int node){
	if(ini==fin){
		tree[node].push_back(next[ini]);
		return;
	}

	int mit = (ini+fin)/2;
	create(ini,mit,2*node);
	create(mit+1,fin,2*node+1);

	merge(ini,fin,node);
}

int query(int ini, int fin, int a, int b, int v, int node){

	if(ini>b || fin<a){
		return 0;
	}

	if(ini>=a && fin<=b){
		int SIZE = tree[node].size();
		int p = upper_bound(tree[node].begin(), tree[node].end(),v)-tree[node].begin();

		return SIZE-p;
	}

	int mit =(ini+fin)/2;

	int sleft = query(ini,mit,a,b,v,2*node);
	int sright = query(mit+1,fin,a,b,v,2*node+1);

	return sleft + sright;
}




int main() {

	//freopen("d.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for(int i = 1; i <= N; i++){
		cin >> A[i];
		next[i] = INF;
	}

	MAP.insert( make_pair(A[N],N) );
	for(int i = N-1; i >= 1; i--){
		if(MAP.find(A[i]) != MAP.end()){
			next[i] = MAP[A[i]];
		}
		MAP[A[i]]=i;
	}

	create(1,N,1);

	cin >> Q;
	int p = 0;
	while(Q--){
		int xi,yi;
		cin >> xi >> yi;
		int li = ((xi+p) % N) + 1;
		int ki = ((yi+p) % M) + 1;

		//cout << li << " " << ki << endl;

		//binary_search
		int ini = li, fin = N;
		int sol = 0;
		while(ini<=fin){
			int mit=(ini+fin)/2;

			int diferents = query(1,N,li,mit,mit,1);

			if(diferents > ki){
				fin=mit-1;
			}else if(diferents < ki ){
				ini=mit+1;
			}else {
				sol = mit;
				fin=mit-1;
			}
		}

		cout << sol << endl;
		p = sol;
	}

	return 0;
}
