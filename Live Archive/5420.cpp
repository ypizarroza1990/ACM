#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
# define maxn 52
using namespace std;
typedef long long i64;
typedef pair<int, int> pi;
int t,n;
map<int,int>mapa;
map<int,int>::iterator it;
char num[50],ar[50];
bool duplicate;
int fn(char cn){
	if('A'==cn||'B'==cn ||'C' ==cn)return 2;
	else if('D'==cn||'E'==cn ||'F' ==cn)return 3;
	else if('G'==cn||'H'==cn ||'I' ==cn)return 4;
	else if('J'==cn||'K'==cn ||'L' ==cn)return 5;
	else if('N'==cn||'M'==cn ||'O' ==cn)return 6;
	else if('P'==cn||'R'==cn ||'S' ==cn)return 7;
	else if('T'==cn||'U'==cn ||'V' ==cn)return 8;
	else if('X'==cn||'W'==cn ||'Y' ==cn)return 9;

}
int vp[]={1e7,1e6,1e5,1e4,1e3,1e2,10,1};
int act=0;
int main() {
	scanf("%d", &t);
    while(t--){
    	scanf("%d",&n);
    	for(int i=0;i<n;i++){
    		scanf("%s",num);
    		int len=strlen(num);
    		for(int i=0,s=0;i<len;i++){
    			if(isdigit(num[i])){
    				act+=num[i]-48;
    				s++;
        			if(s<7){
        				act*=10;
        			}
    			}
    			else if(isalpha(num[i])){
    				act+=fn(num[i]);
    				s++;
        			if(s<7){
        				act*=10;
        			}
    			}

    		}
    		++mapa[act];
    		act=0;
    	}
    	duplicate=true;
    	for(it=mapa.begin();it!=mapa.end();it++){
    		if(it->second>1){
    			duplicate=false;
    			if(duplicate)puts("No duplicates.");
    			sprintf(ar,"%.7d\n",it->first);
    			printf("%c%c%c-%c%c%c%c %d\n",ar[0],ar[1],ar[2],ar[3],ar[4],ar[5],ar[6],it->second);
    		}
    	}
    	if(duplicate)puts("No duplicates.");
    	mapa.clear();
    	if(t)printf("\n");
    }
	return 0;
}
