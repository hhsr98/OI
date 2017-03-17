#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 100010
using namespace std;
int sum[MAXN],rank[MAXN];
int c[MAXN];
int N,M;
#define lowbit(x) (x&(-x))
void set(int num)
{
	for(;num<=N;num+=lowbit(num)) c[num]++;
}
int get(int num)
{
	int s=0;
	num--;
	for(;num>0;num-=lowbit(num)) s+=c[num];
	return s;
}
bool cmp(int a,int b)
{
	return sum[a]<sum[b];
}
int main()
{
	int i,cnt,tmp;
	long long ans;
	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&sum[i]);
		sum[i]-=M;
		rank[i]=i;
		sum[i]+=sum[i-1];
	}
	sort(rank,rank+N+1,cmp);
	cnt=1;i=0;
	while(i<=N)
	{
		tmp=sum[rank[i]];
		for(;sum[rank[i]]==tmp&&i<=N;i++) sum[rank[i]]=cnt;
		cnt++;
	}
	ans=0;
	for(i=0;i<=N;i++)
	{
		set(sum[i]);
		ans+=get(sum[i]);
	}
	printf("%d",ans);
	return 0;
}

