#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXNODE 10000000
using namespace std;
struct trie
{
	int sz;
	int ch[MAXNODE][2];
	int depth[MAXNODE];
	int passby[MAXNODE];
	trie() {sz=1;memset(ch[0],0,sizeof(ch[0]));depth[0]=0;passby[0]=0;}
	void clear(){sz=1;memset(ch[0],0,sizeof(ch[0]));depth[0]=0;passby[0]=0;}
	void insert(char* s)
	{
		int len=strlen(s),i,p;
		p=0;
		for(i=0;i<len;i++)
		{
			if(!ch[p][s[i]-'0'])
			{
				ch[p][s[i]-'0']=sz;
				memset(ch[sz],0,sizeof(ch[sz]));
				depth[sz]=depth[p]+1;passby[sz]=0;
				sz++;
			}
			p=ch[p][s[i]-'0'];
			passby[p]++;
		}
	}
};
trie str_set;
int main()
{
	int T,N,i,j,val,maxi;
	char temp[210];
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		str_set.clear();
		for(j=1;j<=N;j++) {scanf("%s",temp);str_set.insert(temp);}
		maxi=0;
		for(j=1;j<str_set.sz;j++)
		{
			val=str_set.passby[j]*str_set.depth[j];
			maxi=maxi>val?maxi:val;
		}
		printf("%d\n",maxi);
	}
	system("pause");
	return 0;
}
		
		
 
