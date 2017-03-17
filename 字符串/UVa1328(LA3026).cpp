#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define MAXN 1000010
using namespace std;
int N,F[MAXN];
char S[MAXN];
int main()
{
     int case_count=0,i,j;
 	 scanf("%d",&N);
 	 while(N)
 	 {
 	 	case_count++;
 	 	scanf("%s",S);
 	 	F[0]=0;F[1]=0;
 	 	for(i=1;i<N;i++)
 	 	{
 	 		j=F[i];
 	 		while(j&&S[i]!=S[j]) j=F[j];
 	 		if(S[i]==S[j]) F[i+1]=j+1;
 	 		else F[i+1]=0;
 	 	}
 	 	
 	 	printf("Test case #%d\n",case_count);
 	 	for(i=2;i<=N;i++)
 	 	   if(F[i]&&(i%(i-F[i])==0)) printf("%d %d\n",i,i/(i-F[i]));
 	 	printf("\n");
 	 	
 	 	scanf("%d",&N);
 	 }
 	 system("pause");
 	 return 0;
}
