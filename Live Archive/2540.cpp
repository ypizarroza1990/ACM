#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
char C[30],cad[150];
int main() {
	 for(int i='A';i<='Z';i++){
		  char c=i+21;
		  if(c>'Z')
			  c=c-'A'+39;
		 C[i-'A']=c;
	 }
	 while(gets(cad),strcmp(cad,"ENDOFINPUT")!=0){
		 if((strlen(cad)==3 &&strcmp(cad,"END")==0 )||(strlen(cad)==5 &&strcmp(cad,"START")==0))
			 continue;
		 else{
			 for(int i=0;cad[i];i++){
				 if(isupper(cad[i]))
					 putchar(C[cad[i]-'A']);
				 else
					 putchar(cad[i]);
			 }
		 }
		 puts("");
	 }
}
