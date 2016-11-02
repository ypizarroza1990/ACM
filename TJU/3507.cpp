//============================================================================
// Name        : Grundy_Cup.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
struct Date{
	int y,m,d;
};
bool bisiesto(int year){
	if((year%4==0 && (year%100!=0))||(year%100==0 && (year%400==0)))
		return true;
	return false;
}
int Day(Date D){
	int mes[]{0,31,28,31,30,31,30,31,31,30,31,30,31};
	i64 ans=0;
	for(int i=999;i<D.y;i++){
		if(bisiesto(i))ans+=366;
		else ans+=365;
	}
	if(bisiesto(D.y))mes[2]=29;
	for(int i=1;i<D.m;i++){
		ans+=mes[i];
	}
	ans+=D.d;
	return ans;
}
int cas,y,m,d;
Date one,two;
int main() {
	scanf("%d",&cas);
	while(cas--){
		scanf("%d/%d/%d",&y,&m,&d);
		one=Date{y,m,d};
		scanf("%d/%d/%d",&y,&m,&d);
		two=Date{y,m,d};
		printf("%d\n",abs(Day(one)-Day(two)));
	}
	return 0;
}
