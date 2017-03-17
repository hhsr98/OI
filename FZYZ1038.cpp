#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int fa[10010];
int f(int x)
{
	if(fa[x]==x) return x;
	fa[x]=f(fa[x]);
	return fa[x];
}
int main()
{
	int N,K,M;
	int i,x,y,anscnt;
	scanf("%d %d %d ",&N,&K,&M);
	for(i=1;i<=N;i++) fa[i]=i;
	for(i=1;i<=K;i++)
	{
		scanf("%d %d",&x,&y);
		if(f(x)!=f(y))
		{
			fa[fa[x]]=fa[y];
		}
	}
	anscnt=0;
	for(i=1;i<=M;i++)
	{
		scanf("%d %d",&x,&y);
		if(f(x)!=f(y))
		{
			fa[fa[x]]=fa[y];
			anscnt++;
		}
	}
	printf("%d",anscnt);
	return 0;
}

