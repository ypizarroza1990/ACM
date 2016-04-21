#include <iostream>
#include<stdio.h>
using namespace std;

long long int Catalan(int n)
{
    if(n<=0)
    {
        return 1;
    }
    else
    {
         return (2*(2*n-1)*Catalan(n-1))/(n+1);
    }

}

int main()
{

     int n,ok=0;
     while(cin>> n){
    	 if(ok)puts("");
     cout<< Catalan(n)<<endl;
     ok=1;
     }
}
