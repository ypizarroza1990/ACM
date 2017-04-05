//============================================================================
// Name        : pp.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
typedef unsigned long long i64;
vector<i64>V;
i64 longitud,val;
int i,j,cas;
int main() {
	ios::sync_with_stdio(false);
    while(cin>>longitud>>cas){
    longitud=longitud*10000000;
    if(cas){
    	 V.clear();
    for(int i=0;i<cas;i++){
    	cin>>val;
    	V.push_back(val);
    }
    sort(V.begin(),V.end());
    i=0;j=V.size()-1;
    while(i!=j){
    	if(V[i]+V[j]==longitud)break;
    	if(V[i]+V[j]<longitud)i++;
    	else j--;
    }
    if(i<j)printf("yes %lld %lld\n",V[i],V[j]);
    else puts("danger");
    }
    else puts("danger");
    }
}

