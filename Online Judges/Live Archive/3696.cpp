#include<stdio.h>
#include<vector>
#include <unordered_map>
using namespace std;
int cas,num,temp,i,j;
vector<int>arr;
unordered_map<int,vector<int>>Map;
int main(){
	while(scanf("%d",&cas)==1){
		for(int iter=0;iter<cas;iter++){
			scanf("%d",&num);
			if(Map[num].size()==0){
				arr = vector<int>(10,0);
				for(i=1;i<=num;i++){
					temp=i;
					if(!temp)arr[0]++;
					else while(temp>0){
						arr[temp%10]++;
						temp/=10;
					}
				}
				Map[num]=arr;
			}
			arr = Map[num];


			for(int i=0;i<=9;i++){
				printf("%s%d",i?" ":"",arr[i]);
			}
			puts("");
		}
	}
	return 0;
}
 
