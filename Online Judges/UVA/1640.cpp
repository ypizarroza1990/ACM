#include <bits/stdc++.h>

using namespace std;
int c[2][10],pow_ten[10];
void count(int x,bool up){
	int *cnt=c[up],d,dcnt=0,r=0,rem0=0,v;
	while(x){
		d=x%10,x/=10;
		if(dcnt){
			v=d*pow_ten[dcnt-1]*dcnt;
			for(int i=0;i<10;i++)cnt[i]+=v;
			if(!d)rem0+=pow_ten[dcnt]-1-r;
			}
		v=pow_ten[dcnt];
		for(int i=1;i<d;i++)cnt[i]+=v;
		if(d)cnt[d]+=r+1;
		r=pow_ten[dcnt++]*d+r;
	}
	cnt[0]-=rem0;
}
int a,b;
int main()
{
	pow_ten[0]=1;
	for(int i=1;i<10;i++)pow_ten[i]=pow_ten[i-1]*10;
	 while(scanf("%d%d",&a,&b),a+b){
		 for(int i=0;i<10;i++)c[1][i]=c[0][i]=0;
		 if(a>b)a^=b^=a^=b;
		 count(a-1,0),count(b,1);
		 for(int i=0;i<10;i++){
			 if(i)putchar(' ');
			 printf("%d",c[1][i]-c[0][i]);
		 }
		 putchar('\n');
	 }

}

