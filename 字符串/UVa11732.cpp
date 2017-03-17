#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXNODE 4000010
#define SIGMA_SIZE 63 //26+26+10+1
using namespace std;
int P[256];
long long result;
struct trie
{
	int count[MAXNODE];
	int ch[MAXNODE][SIGMA_SIZE];
	int sz;
	void clear(){sz=1;memset(ch[0],0,sizeof(ch[0]));count[0]=0;}
	void insert(char *s)
	{
		int len=strlen(s);
		int i,p=0,q;
		for(i=0;i<len;i++)
		{
			if(!ch[p][P[s[i]]])
			{
				count[sz]=0;
				memset(ch[sz],0,sizeof(ch[sz]));
				ch[p][P[s[i]]]=sz;
				sz++;
			}
			q=ch[p][P[s[i]]];
			result+=count[q]*2;
			result+=(count[p]-count[q]);
			count[p]++;p=q;
		}
		count[p]++;				
	}
}str_set;
int main()
{
	int case_count=0,N,i,j,l;
	char jj,temp[1010];
	//initiallization of P array
	for(i=0,jj='0';jj<='9';P[jj]=i,i++,jj++);
	for(i=10,jj='a';jj<='z';P[jj]=i,i++,jj++);
	for(i=36,jj='A';jj<='Z';P[jj]=i,i++,jj++);
	P['#']=62;
	
	scanf("%d",&N);
	while(N)
	{
		case_count++;
		result=0;str_set.clear();
		for(i=1;i<=N;i++)
		{
			scanf("%s",temp);
			l=strlen(temp);
			temp[l]='#';temp[l+1]=0;
			str_set.insert(temp);
		}	
		printf("Case %d: %lld\n",case_count,result);
		scanf("%d",&N); 
	}
	system("pause");
	return 0;
}
