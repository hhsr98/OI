#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXM 400010
using namespace std;
struct node
{
	long long cost;
	long long tag;
	bool operator < (const node &b) const
	{
		return (cost+tag) < (b.cost+b.tag);
	}
	bool operator > (const node &b) const
	{
		return (cost+tag) > (b.cost+b.tag);
	}
}heap[MAXM];
int hcnt;
int a[MAXM];
void del(int pos)
{
	int i,tmp1;
	node tmp;
	heap[pos]=heap[hcnt];
	hcnt--;
	i=pos;
	while(2*i<=hcnt)
	{
		tmp1=2*i;
		if(2*i+1<=hcnt)
			tmp1=heap[2*i]<heap[2*i+1]?2*i:2*i+1;	
		if(heap[tmp1]<heap[i])
		{	tmp=heap[tmp1];heap[tmp1]=heap[i];heap[i]=tmp;i=tmp1;	}
		else
			break;
	}
}
void ins(int c,int t)
{
	int i;
	node tmp;
	hcnt++;heap[hcnt].cost=c;heap[hcnt].tag=t;
	i=hcnt;
	while(i>1)
	{
		if(heap[i]<heap[i>>1])
		{
			tmp=heap[i>>1];heap[i>>1]=heap[i];heap[i]=tmp;
			i>>=1;
		}
		else
			break;
	}
}
int main()
{
	long long min1=2110000000000000,ans;
	int N,i;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{	scanf("%d",&a[i]);a[i]+=i;}
	ins(0,a[1]);
	for(i=1;i<=N;i++)
	{
		ans=2110000000000000;
		while(hcnt>=1&&heap[1].tag<=i)
		{
			min1=min1<heap[1].cost-heap[1].tag?min1:heap[1].cost-heap[1].tag;
			del(1);
		}
		if(hcnt>=1) ans=heap[1].cost+heap[1].tag;
		ans=ans-i>min1+i?min1+i:ans-i;
		ins(ans,a[i+1]);
	}
	printf("%d",ans);
	return 0;
}
		
	


