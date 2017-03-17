#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXNODE 11000
#define SIGMA_SIZE 26
using namespace std;
int ch[MAXNODE][SIGMA_SIZE];
int tag[MAXNODE],F[MAXNODE],last[MAXNODE];
int sz;
void clear() {sz=0;memset(ch[0],0,sizeof(ch[0]));}
void insert(char* s,int number)
{
	int len=strlen(s),p=0;
	for(i=0;i<len;i++)
	{
		idx=s[i]-'a';
		if(!ch[p][idx])
		{
			ch[p][idx]=sz;
			tag[sz]=0;F[sz]=0;last[sz]=0;
			sz++;
		}
		p=ch[p][idx];
	}
	tag[p]=number;
}
void getFail()
{
	queue<int> q;
	for(i=0;i<SIGMA_SIZE;i++)
	{
		u=ch[0][i];
		F[u]=0;
		if(u) q.push(u);
	}
	while(!q.empty)
	{
		r=q.front(); q.pop();
		for(i=0;i<SIGMA_SIZE;i++)
		{
			u=ch[r][i];
			if(!u) {ch[r][i]=ch[F[r]][i];continue;}
			q.push(u);
			k=r;
			while(k&&!ch[F[k]][i]]) k=F[k];
			F[u]=F[k];
			if(tag[u]&&tag[k]) last[u]=k;
		}
	}
			
			
			
char str[160][80];
int main()
{
	int N;
	scanf("%d",&N);
	while(N)
	{
		clear();
		for(i=1;i<=N;i++)
		{
			scanf("%s",str[i]);
			insert(str[i],i);
		}
			
		scanf("%d",&N);
	}
	
 
