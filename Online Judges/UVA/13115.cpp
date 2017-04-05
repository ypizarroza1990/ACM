#include <bits/stdc++.h>
#include  <memory>
using namespace std;
typedef long long i64;
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
int M[30][30];
bool check[30];
int N,cases;

bool row(){
	bool isCorrect=true;

	for(int i=0;i<N && isCorrect ;i++)
	{
		memset(check,false,sizeof(check));
		for (int j = 0; j < N && isCorrect ; ++j){
			if(!check[M[i][j]] &&  1<=M[i][j] && M[i][j]<=N)
				check[M[i][j]]=true;
			else
				isCorrect=false;
		}
	}

	return isCorrect;
}


bool column(){
	bool isCorrect=true;

	for(int i=0;i<N && isCorrect ;i++)
	{
		memset(check,false,sizeof(check));
		for (int j = 0; j < N && isCorrect ; ++j){
			if(!check[M[j][i]] && 1<=M[j][i] && M[j][i]<=N )
				check[M[j][i]]=true;
			else
				isCorrect=false;
		}
	}
	return isCorrect;
}

bool cuadrant(int row,int column)
{
	bool isCorrect=true;
	memset(check,false,sizeof(check));
	for (int i = row; i < row+sqrt(N); ++i) {
		for (int j = column; j < column+sqrt(N); ++j) {
			if(!check[M[i][j]] && 1<=M[i][j] && M[i][j]<=N )
				check[M[i][j]]=true;
			else
				isCorrect=false;
		}
	}
	return isCorrect;
}


bool checkCuadrant()
{
	bool isCorrect=true;
	for(int i=0;i<N;i+=sqrt(N))
	{
		for (int  j= 0;  j< N; j+=sqrt(N)) {
			isCorrect=isCorrect & cuadrant(i,j);
		}
	}


	return isCorrect;
}

int main(){
	//freopen("001.in","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>cases)
	{
		while(cases--)
		{
			cin>>N;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					cin>>M[i][j];
				}
			}
			if(row() && column() && checkCuadrant())
				cout<<"yes\n";
			else
				cout<<"no\n";
		}
	}
}
