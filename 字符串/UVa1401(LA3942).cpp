#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXL 120
#define MAXNODE 400010 
#define MOD 20071027
using namespace std;
struct trie
{
	bool val[MAXNODE];
	int ch[MAXNODE][26];
	int sz;
	trie()
	{sz=1;memset(ch[0],0,sizeof(ch[0]));}
	void clear()
	{sz=1;memset(ch[0],0,sizeof(ch[0]));}
	void insert(char *s)
	{
		int len=strlen(s);
		int i,p=0,idx;
		for(i=0;i<len;i++)
		{
			idx=s[i]-'a';
			if(!ch[p][idx])
			{
				ch[p][idx]=sz;
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz]=0;
				sz++;
			}
			p=ch[p][idx];
		}
		val[p]=1;
	}
};
char str[300010];
int record[300010];
bool flag[300010];
int S,lenstr;
trie str_set;
int find(int pos)
{
	int count=0,p=0,r=pos;
	if(r==lenstr) return 1;
	if(flag[pos]) return record[pos];
	while(pos<lenstr&&str_set.ch[p][str[pos]-'a'] )
	{
		p=str_set.ch[p][str[pos]-'a'];
		pos++;
		if(str_set.val[p]) count=(find(pos)+count)%MOD;
	}
	flag[r]=true;record[r]=count;
	return count;
}
int main()
{
	int count=0,i;
	char temp[MAXL];
	while(scanf("%s%d",str,&S)==2)
	{
		count++;
		lenstr=strlen(str);
		for(i=0;i<lenstr;i++) flag[i]=record[i]=0;
		str_set.clear();
		for(i=1;i<=S;i++){scanf("%s",temp);str_set.insert(temp);}
		printf("Case %d: %d\n",count,find(0));
	}
	system("pause");
	return 0;
}
			
 	 
