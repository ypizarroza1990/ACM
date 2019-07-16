#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'
const int MAXN = 600001;

struct node
{
	int cnt,prio;
	int key;
	node *l, *r;
};

typedef node* pnode;

pnode root;
node treap[MAXN];
vector<int> rnd;
int t_cnt;

int cnt(pnode t){
	return t ? t->cnt : 0;
}

void update(pnode t){
	if(t)
		t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(pnode t, pnode &l, pnode &r, int pos){
	if(!t)
		l = r = NULL;
	else if(pos <= cnt(t->l))
		split(t->l, l, t->l, pos), r = t;
	else
		split(t->r, t->r, r, pos - cnt(t->l)-1), l = t;

	update(t);
}

void merge(pnode &t, pnode l, pnode r){
	if(!l || !r)
		t = l ? l: r;
	else if(l->prio > r->prio)
		merge(l->r,l->r,r), t = l;
	else
		merge(r->l, l, r->l), t = r;

	update(t);
}

void insert(pnode &t, pnode it, int pos){
	if(!t)
		t = it;
	else if(it->prio > t->prio)
		split(t,it->l,it->r, pos), t=it;
	else if(pos <= cnt(t->l))
		insert(t->l, it, pos);
	else
		insert(t->r,it, pos-cnt(t->l)-1);

	update(t);
}

int k_th(pnode &t, int pos){
	if(pos < cnt(t->l))
		return k_th(t->l, pos);
	else if(pos > cnt(t->l))
		return k_th(t->r, pos - cnt(t->l)-1);
	return t->key;
}

void erase(pnode &t, int key){
	if(t->key == key)
		merge(t, t->l, t->r);
	else
		erase(key < t->key ? t->l : t->r, key);
}

void output(pnode t){
	if(!t) return;
	output(t->l);
	cout<<t->key<<' ';
	output(t->r);
}

void insert(int pos,int val){
	pnode it = &treap[t_cnt];
	it->key = val;
	it->prio = rnd[t_cnt];
	++t_cnt;
	insert(root, it,pos);
}

int N ,M ,op;
int value, pos, val;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	 for (int i = 0; i < MAXN; i++)
        rnd.push_back(i);
    random_shuffle(rnd.begin(), rnd.end());
	cin>>N>>M;
    for(int i = 0; i < N; i++){
    	cin >> val;
    	insert(i,val);
    }
    while(M--){
		cin>>op>>pos;pos--;
		switch(op){
			case 1:
				cin>>val;
				insert(pos,val);
				break;
			case 2:
				value = k_th(root,pos);
				erase(root, value);
				break;
			default:
				cout<<k_th(root,pos)<<endl;
				break;
		}
    }
	return 0;
}