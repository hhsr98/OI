#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 150010
using namespace std;
int N,M;
double p[MAXN*2],s[MAXN];
int pcnt;
struct interval
{
	double l,r;
}occupy_o[MAXN];
bool cmpl(interval a,interval b)
{
	return a.l<b.l;
}
int find(double num)
{
	int ll=1,rr=pcnt*2,mid;
	if(p[ll]>=num) return ll;
	if(p[rr]<=num) return rr;
	while(rr-ll>1)
	{
		mid=(ll+rr)/2;
		if(num==p[mid]) return mid;
		if(num>p[mid]) ll=mid;
		else rr=mid;
	}
	return ll;
}

int main()
{
	int i,l1,l2,r1,r2;
	double tmpl,tmpr,ans,li,ri;
	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++) scanf("%lf %lf",&occupy_o[i].l,&occupy_o[i].r);
	sort(occupy_o+1,occupy_o+N+1,cmpl);
	i=1;
	while(i<=N)
	{
		tmpl=occupy_o[i].l;
		tmpr=occupy_o[i].r;
		for(i=i+1;occupy_o[i].l<=tmpr&&i<=N;i++)
			if(occupy_o[i].r>tmpr) tmpr=occupy_o[i].r;
		pcnt++;
		p[pcnt*2-1]=tmpl;p[pcnt*2]=tmpr;
		s[pcnt]=s[pcnt-1]+tmpr-tmpl;
	}
	for(i=1;i<=M;i++)
	{
		ans=0;
		scanf("%lf %lf ",&li,&ri);
		l1=find(li);r1=find(ri);
		l2=(l1+1)/2;r2=(r1+1)/2;
		if(p[l1]<=li)	ans+=(p[l1+1]-li)*(l1%2);
		else l2--;
		if(p[r1]<=ri) 	ans-=(p[r1+1]-ri)*(r1%2);
		else r2--;
		ans+=s[r2]-s[l2];
		ans=ri-li-ans;
		printf("%lf\n",ans);
	}
		
	return 0;
	 
}

