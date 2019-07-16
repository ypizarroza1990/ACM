#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF -1000000009
const int MAXN = 3000001;
				 
struct node
{
	int key,prior;
	int cnt;
	node *l,*r;
};

typedef node *pnode;
pnode root;
node treap[MAXN];
vector<int> rnd;
int t_cnt;

int cnt(pnode t){
	return t ? t->cnt : 0;
}

void upd_cnt(pnode t){
	if(t)
		t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

int get_value(pnode t){
	return t ? t->key :INF;
}

void split(pnode t, int key, pnode &l, pnode &r){
	if(!t)
		l = r = NULL;
	else if(key < t->key)
		split(t->l, key, l,t->l), r=t;
	else
		split(t->r, key,t->r,r), l=t;
	upd_cnt(t);
}

void insert(pnode &t, pnode it){
	if(!t)
		t = it;
	else if(it->prior>t->prior)
		split(t,it->key,it->l,it->r), t = it;
	else
		insert(it->key < t->key ? t->l : t->r, it);
	upd_cnt(t);
}

void merge(pnode &t, pnode l, pnode r){
	if(!l || !r)
		t = l ? l : r;
	else if(l->prior > r-> prior)
		merge(l->r,l->r,r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

void erase(pnode &t, int key){
	if(t->key == key)
		merge(t,t->l,t->r);
	else
		erase(key < t->key ? t->l : t->r, key);
	upd_cnt(t);
}

bool find(pnode &t, int key){
	if(!t)
		return false;
	else if(t->key == key)
		return true;
	else
		return find(key < t->key ? t->l : t->r, key);
}

void insert(int val){
		pnode it = &treap[t_cnt];
		it->key = val;
		it->prior = rnd[t_cnt];
		++t_cnt;
		insert(root,it);
}

void erase(int val){
	if(find(root,val)){
		erase(root, val);
	}
}

int k_th(pnode &t, int pos){
	if(pos < cnt(t->l))
		return k_th(t->l, pos);
	else if(pos > cnt(t->l))
		return k_th(t->r, pos - cnt(t->l)-1);
	return get_value(t);
}

int index(pnode &t, int val){
	int ans = 0;
	if(!t)
		return 0;
	else if(val >= get_value(t)){
		ans += cnt(t->l) + 1;
		ans += index(t->r,val);
	}
	else
		ans = index(t->l,val);
	return ans;
}

void print(node *t) {
    if (t) {
        print(t->l);
		cout << t->key<<" ";
        print(t->r);
    }
}

void print() {
    print(root);
    cout << endl;
}

int N,M,val,ans;
int op;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    for (int i = 0; i < MAXN; i++)
        rnd.push_back(i);
    random_shuffle(rnd.begin(), rnd.end());

	while(cin>>op){
		if(op == -1)
			break;
		cin>>val;
		switch(op){
			case 1:
				insert(val);
				break;
			case 2:
				erase(val);
				break;
			case 3:
				if(!find(root,val))
					cout<<-1<<endl;
				else
					cout<<index(root,val)<<endl;
				break;
			default:
				if(val>cnt(root))
    				cout<<-1<<endl;
    			else{
					cout<<k_th(root,val-1)<<endl;
				}
    			break;

		}
	}

}