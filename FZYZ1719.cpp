#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXP 110
#define MAXT 1010
using namespace std;
int fish[MAXT][MAXP];
int dist[MAXP];
int init[MAXP];
int decr[MAXP];
int maxT[MAXP],minT[MAXP],mcnt[MAXP];
int N,T;
int main()
{
	
	int maxi,i,t,n,tmp,ans;
	scanf("%d",&N);
	for(i=1;i<=N;i++) scanf("%d",&init[i]);
	for(i=1;i<=N;i++) scanf("%d",&decr[i]);
	for(i=1;i<=N-1;i++) scanf("%d",&dist[i]);
	scanf("%d",&T);
	for(i=1;i<=N;i++)
	{
		if(decr[i])
			mcnt[i]=init[i]/decr[i]+(init[i]%decr[i] ? 1:0);
		else
			mcnt[i]=T;
	}
	maxT[1]=mcnt[1];
	for(i=1;i<=N-1;i++)
	{
		minT[i+1]=minT[i]+dist[i];
		maxT[i+1]=maxT[i]+dist[i]+mcnt[i+1];
	}
	ans=0;
	for(n=1;n<=N;n++)
	{
		for(t=minT[n];t<=maxT[n]&&t<=T;t++)
		{
			maxi=fish[t-dist[n-1]][n-1];tmp=init[n];
			for(i=1;i<=mcnt[n]&&t-i-dist[n-1]>=minT[n-1];i++)
			{
				maxi=maxi>fish[t-i-dist[n-1]][n-1]+tmp?maxi:fish[t-i-dist[n-1]][n-1]+tmp;
				tmp+=(init[n]-i*decr[n]);
			}
			fish[t][n]=maxi;
			ans=ans>maxi?ans:maxi;
		}	
	}
	
	printf("%d",ans);
	return 0;

}

