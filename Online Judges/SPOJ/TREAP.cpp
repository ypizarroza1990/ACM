#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define INF 10000000009
const int MAXN = 200001;

using namespace std;

struct node
{
	int key,prior,cnt;
	int minv,maxv,minq;
	node *l,*r;
};

typedef node* pnode;

pnode root;
node treap[MAXN];
vector<int> rnd;
int t_cnt;

int cnt(pnode t){return t ? t->cnt : 0;}
int maxv(pnode t){return t ? t->maxv : -INF;}
int minv(pnode t){return t ? t->minv : INF;}
int minq(pnode t){return t ? t->minq : INF;}

void update(pnode t){
	if(!t)
		return;
	t->cnt = 1 + cnt(t->l) + cnt(t->r);
	t->maxv = max(t->key, max(maxv(t->l),maxv(t->r)));
	t->minv = min(t->key, min(minv(t->l),minv(t->r)));
	if(t->l)
		t->minq = min(t->minq, t->key - maxv(t->l));
	if(t->r)
		t->minq = min(t->minq, minv(t->r) - t->key);
}

void split(pnode t, int key, pnode &l, pnode &r){
	if(!t)
		l = r = NULL;
	else if(key < t->key)
		split(t->l, key, l, t->l), r = t;
	else
		split(t->r, key, t->r, r), l = t;

	update(t);
}

void split(pnode t, pnode &l, pnode &r, int pos){
	if(!t)
		l = r = NULL;
	else if(pos <= cnt(t->l))
		split(t->l, l, t->l, pos), r = t;
	else
		split(t->r, t->r, r, pos - cnt(t->l) -1), l = t;

	update(t);
}

bool find(pnode &t, int key){
	if(!t)
		return false;
	else if(key == t->key)
		return true;
	else
		return find(key < t->key ? t->l : t->r, key);
}

void insert(pnode &t, pnode it){
	if(!t)
		t = it;
	else if(it->prior > t->prior)
		split(t, it->key, it->l, it->r), t = it;
	else
		insert(it->key < t->key ? t->l: t->r, it);

	update(t);
}

void insert(int value){
	if(!find(root,value)){
       pnode it = &treap[t_cnt];
       it->prior = rnd[t_cnt];
       it->key = value;
       insert(root, it);
	}
}

void merge(pnode &t, pnode l, pnode r){
	if(!l || !r)
		t = l ? l : r;
	else if(l->prior > r->prior)
		merge(l->r,l->r, r), t = l;
	else
		merge(r->l,l, r->l), t = r;

	update(t);
}

void erase(pnode &t, int key){
	if(t->key == key)
		merge(t, t->l, t->r);
	erase(key < t->key ? t->l : t->r, key);

	update(t);
}

void erase(int value){
	if(find(root, value)){
		erase(root,value);
	}
}

int Nquery(int i, int j){
	pnode l1, r1;
	split(root, l1, r1, j+1);
	pnode l2, r2;
	split(l1, l2, r2, i);
	int ans = minq(r2);
	pnode t;
	merge(t, l2, r2);
	merge(root, t, r1);
	return ans;
}

int Xquery(int i, int j){
	pnode l1, r1;
	split(root, l1, r1, j+1);
	pnode l2, r2;
	split(l1, l2, r2, i);
	int ans = maxv(r2) - minv(r2);
	pnode t;
	merge(t, l2, r2);
	merge(root, t, r1);
	return ans;
}

int cas,i,j;
char op;
int main()
{
	 for (int i = 0; i < MAXN; i++)
        rnd.push_back(i);
    random_shuffle(rnd.begin(), rnd.end());
	cin>>cas;
	while(cas--){
		cin>>op>>i;

		switch(op){
			case 'I':
				insert(i);
				break;
			case 'D':
				erase(j);
				break;
			case 'N':
				cin>>j;
				if(j - i < 1)
					cout<<-1<<endl;
				else
					cout<<Nquery(i-1,j-1)<<endl;
				break;
			default:
				cin>>j;
				if(j - i < 1)
					cout<<-1<<endl;
				else
					cout<<Xquery(i-1,j-1)<<endl;
				break;
		}
	}
	return 0;
}