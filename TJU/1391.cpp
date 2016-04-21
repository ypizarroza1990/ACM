#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<iostream>
#include<map>
#include<sstream>
#define ALPHA 26
using namespace std;
typedef unsigned long long  i64;
struct node{
	int val;
	vector<node*>links; //hijo trie
	node();
};
node::node(){
	val=0;
	links.resize(ALPHA,NULL);
}
class Trie{
public:
	Trie();

	int getval(string &cad)const;
	void insert(string cad, int val);

private:
	node* myroot; //raiz trie
};
Trie::Trie(){
	myroot=new node();
}
void Trie::insert(string cad, int val){
	node *t=myroot;
	int len=cad.size();
	for(int i=0;i<len;i++){
		if(t->links[cad[i]-'a']==NULL)
			t->links[cad[i]-'a']=new node();
		t=t->links[cad[i]-'a'];
	}
	t->val+=val;
}
int Trie::getval(string &cad)const{
	node *t=myroot;
	int len=cad.size();
	for(int i=0;i<len;i++){
		if(t->links[cad[i]-'a']==NULL || cad[i]<'a' ||cad[i]>'z')
			return 0;
		t=t->links[cad[i]-'a'];
	}
	return t==NULL?0:t->val;
}
int n,m,val,res;
string cad,c;
int main(){

	while(cin>>n>>m){
		Trie *mytrie;
		mytrie=new Trie();
		for(int i=0;i<n;i++){
			cin>>cad>>val;
			mytrie->insert(cad,val);
		}
		for(int i=0;i<m;i++){
			res=0;
			while(1){
			getline(cin,cad);
			if(cad==".")
				break;
			stringstream ss(cad);
			while(ss>>c){
				res+=mytrie->getval(c);
			}
		}
			cout<<res<<endl;
		}
	}
	return 0;
}

