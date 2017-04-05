 #include <cstdio>
#include<map>
#include <vector>
using namespace std;

map <int,int> l;
int t, n , a , cont , sum,L;
vector<int>V;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		sum = 0;   cont = 0;
		l.clear(); l[0] = 1;
		V.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a);
			V.push_back(a);
		}
		scanf("%d",&L);
		for(int i=0;i<n;i++)
		{
			a=V[i];
			sum  += a;
			cont += l[sum-L];
			l[sum]++;
		}
		printf("%d\n", cont);
	}
	return 0;
}
