#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXM 500010
using namespace std;
struct Node
{
	int key;
	int tag;
	int son[2];
	bool operator< (const Node &b) const
	{
		return tag<b.tag;
	}
	int cmp(int x) const
	{
		if(x==key) return -1;
		return x<key?0:1;
	}
}treap[MAXM];
int key[MAXM],tag[MAXM];
int ncnt;
void rotate(int &pos,int d)
{
	int s=treap[pos].son[d^1];
	treap[pos].son[d^1]=treap[s].son[d];
	treap[s].son[d]=pos;
	pos=s;
}
void insert(int &pos,int x,int t)
{
	if(!pos)
	{
		ncnt++;pos=ncnt;
		treap[ncnt].key=x;treap[ncnt].tag=t;
		treap[ncnt].son[0]=treap[ncnt].son[1]=0;
	}
	else
	{
		int d=treap[pos].cmp(x);
		insert(treap[pos].son[d],x,t);
		if(treap[pos]<treap[treap[pos].son[d]]) rotate(pos,d^1);
	}
}
void print(int pos)
{
	if(!pos) return;
	printf("%d ",treap[pos].key);
	print(treap[pos].son[0]);
	print(treap[pos].son[1]);
} 
int main()
{
	int N,root,i;
	scanf("%d",&N);
	for(i=1;i<=N;i++) scanf("%d",&key[i]);
	for(i=1;i<=N;i++) scanf("%d",&tag[i]);
	root=1;ncnt++;
	treap[1].key=key[1];treap[1].tag=tag[1];
	for(i=2;i<=N;i++) insert(root,key[i],tag[i]);
	print(root);
	return 0;
}

