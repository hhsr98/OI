#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MOD 10
using namespace std;
int power[30][50][50];
int sum[30][50][50];
int result[50][50];
void mul(int a[][50],int b[][50],int c[][50],int size,int mod)
{
	int temp[50][50],i,j,k;
	for(i=1;i<=size;i++)
	  for(j=1;j<=size;j++)
	     {temp[i][j]=0;
		  for(k=1;k<=size;k++)
		    temp[i][j]=(temp[i][j]+a[i][k]*b[k][j]%mod)%mod;
		 }
	for(i=1;i<=size;i++)
	  for(j=1;j<=size;j++)
	     c[i][j]=temp[i][j];
}
void add(int a[][50],int b[][50],int c[][50],int size,int mod)
{
	int i,j;
	for(i=1;i<=size;i++)
	  for(j=1;j<=size;j++)
	     c[i][j]=(a[i][j]+b[i][j])%mod;
}	
int main()
{
    int N,K,i,j,k,exp,temp1[50][50],temp2[50][50];
	scanf("%d%d",&N,&K);
	while(N!=0)
	{
		for(i=1;i<=N;i++)
		  for(j=1;j<=N;j++)
		    {scanf("%d",&power[0][i][j]);
		     sum[0][i][j]=power[0][i][j]=power[0][i][j]%MOD;
	        }
	    for(exp=-1,k=K;k!=0;k>>=1,exp++);
	    for(i=1;i<=exp;i++)
	    {
	    	mul(power[i-1],power[i-1],power[i],N,MOD);
	    	mul(sum[i-1],power[i-1],sum[i],N,MOD);
	    	add(sum[i-1],sum[i],sum[i],N,MOD);
	    }
	    for(i=1;i<=N;i++) 
		   for(j=1;j<=N;j++) 
           {temp1[i][j]=(i==j)?1:0;temp2[i][j]=result[i][j]=0;}
	    for(i=exp,k=K;k!=0;k=(k|(1<<i))^(1<<i),i--)
	    {
	    	if( (k&(1<<i))!=0 )
	    	{
	    		mul(temp1,sum[i],temp2,N,MOD);
	    		add(result,temp2,result,N,MOD);
	    		mul(temp1,power[i],temp1,N,MOD);
	    	}
	    }
	    for(i=1;i<=N;i++)
		{for(j=1;j<=N-1;j++)
		      printf("%d ",result[i][j]);
           printf("%d\n",result[i][N]);
        }
        printf("\n");
        scanf("%d%d",&N,&K);
    }
    system("pause");
    return 0;
}
/*
3 2
1 0 0
0 1 0
0 0 1
4 10
2 0 0 0
0 2 0 0
0 0 1 0
0 0 0 3
0 0
*/
        
		 
	     
