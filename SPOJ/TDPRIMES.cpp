#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int Max= 100000000;
const int root = 10000;
int flag[Max>>6];
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
void Criba(){
	register int i,j,k;
	for(i=3;i<root;i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1;j<Max;j+=k)
				isc(j);
	j = k = 1;
		printf("2\n");
		for(i=3; i<Max; i+=2)
		{
			if(!ifc(i))
			{
				j++;
				if(j-k==100)
				{
					printf("%d\n", i);
					k = j;
				}
			}
		}
	}
int val,cant;
int main()
{
    Criba();
	return 0;
}

