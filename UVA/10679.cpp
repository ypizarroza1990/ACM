#include <bits/stdc++.h>
#define MOD 1000003
using namespace std;
typedef long long i64;
const int MAXS = 60*1000*5;
const int MAXC = 60;
bitset<1001>out[MAXS];
int f[MAXS],g[MAXS][MAXC];
int buildMatchingMachine(const vector<string> &words,char lowestChar = 'a',char highestChar = 'z') {
	for(int i=0;i<MAXS;i++)
		out[i].reset();
	memset(f, -1, sizeof f);
	memset(g, -1, sizeof g);

	int states = 1; // Initially, we just have the 0 state

	for (int i = 0; i < words.size(); ++i) {
		const string &keyword = words[i];
		int currentState = 0;
		for (int j = 0; j < keyword.size(); ++j) {
			int c = keyword[j]-lowestChar;
			if (g[currentState][c] == -1) {
				// Allocate a new node
				g[currentState][c] = states++;
			}
			currentState = g[currentState][c];
		}
		// There's a match of keywords[i] at node currentState.
		out[currentState].set(i);
	}

	// State 0 should have an outgoing edge for all characters.
	for (int c = 0; c < MAXC; ++c) {
		if (g[0][c] == -1) {
			g[0][c] = 0;
		}
	}

	// Now, let's build the failure function
	queue<int> q;
	// Iterate over every possible input
	for (int c = 0; c <= highestChar - lowestChar; ++c) {
		// All nodes s of depth 1 have f[s] = 0
		if (g[0][c] != -1 and g[0][c] != 0) {
			f[g[0][c]] = 0;
			q.push(g[0][c]);
		}
	}
	while (q.size()) {
		int state = q.front();
		q.pop();
		for (int c = 0; c <= highestChar - lowestChar; ++c) {
			if (g[state][c] != -1) {
				int failure = f[state];
				while (g[failure][c] == -1) {
					failure = f[failure];
				}
				failure = g[failure][c];
				f[g[state][c]] = failure;

				// Merge out values
				out[g[state][c]] |= out[failure];
				q.push(g[state][c]);
			}
		}
	}

	return states;
}
int findNextState(int currentState, char nextInput, char lowestChar = 'a') {
	int answer = currentState;
	int c = nextInput - lowestChar;
	while (g[answer][c] == -1) answer = f[answer];
	return g[answer][c];
}
string text;
int n,cas;
int main() {
	scanf("%d",&cas);
	while(cas--){
		cin>>text;
		scanf("%d",&n);
		vector<int>arr(n,0);
		vector<string>words(n);
		for(int i=0;i<n;i++){
			cin>>words[i];
		}
		buildMatchingMachine(words,'A','z');
		int current=0;
		for(int i=0;i<text.size();++i){
			current=findNextState(current,text[i],'A');
			if(out[current]==0)continue;
			for(int j=0;j<words.size();++j){
				if(out[current].test(j))
					arr[j]=1;
			}
		}
		for(int i=0;i<n;i++)
			arr[i]?puts("y"):puts("n");
	}
}
