//============================================================================
// Name        : 10405.cpp
// Author      : Anthrax
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int LCS(string X,string Y)
{
     if (Y.length() > X.length())
        swap(X,Y);
     int m = X.length(),n=Y.length();
     vector< vector<int> > c(2, vector<int>(n+1,0));
     int i,j;
     for (i=1;i<=m;i++)
     {
         for (j=1;j<=n;j++)
         {
             if (X[i-1]==Y[j-1])
                c[1][j]=c[0][j-1]+1;
             else
                 c[1][j]=max(c[1][j-1],c[0][j]);
         }
         for (j=1;j<=n;j++)
             c[0][j]=c[1][j];
     }
     return (c[1][n]);
}
string A,B;
int main() {

	while(getline(cin,A)){
		getline(cin,B);
		printf("%d\n",LCS(A,B));
	}
	return 0;
}
