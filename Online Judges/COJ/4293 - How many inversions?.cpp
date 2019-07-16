 #include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define endl '\n'
#define LL long long

#define MAX_SIZE 1000009

int A[MAX_SIZE],C[MAX_SIZE],pos1,pos2,sz;

LL countInversions(int a, int b){
    if(a==b) return 0;
    
    int c = ((a+b)>>1);
    LL aux = countInversions(a,c)+countInversions(c+1,b);
    pos1 = a; pos2 = c+1; sz = 0;
    
    while(pos1<=c && pos2<=b){
        if(A[pos1]<A[pos2]) C[sz] = A[pos1++];
        else{
            C[sz] = A[pos2++];
            aux += c-pos1+1;
        }
        ++sz;
    }
    
    if(pos1>c) memcpy(C+sz,A+pos2,(b-pos2+1)*sizeof(int));
    else memcpy(C+sz,A+pos1,(c-pos1+1)*sizeof(int));
    
    sz = b-a+1; 
    memcpy(A+a,C,sz*sizeof(int));
    
    return aux;
}

int n,x;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	while(cin>>n,n){
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		cout<<countInversions(0,n-1)<<endl; 


	}
return 0;
}