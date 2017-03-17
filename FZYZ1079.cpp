#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXM 3000010
unsigned char ch0[MAXM][26],ch1[MAXM][26],ch2[MAXM][26];
unsigned int ccnt=0;
bool endf[MAXM];
void insert(char a[],int len)
{
	int p=0,i;
	unsigned int tmp;
	for(i=0;i<len;i++)
	{
		tmp=ch0[p][a[i]-'a']+ch1[p][a[i]-'a']*256+ch2[p][a[i]-'a']*65536;
		if( !tmp )
		{
			ccnt++;
			ch0[p][a[i]-'a']=ccnt&0xFF;
			ch1[p][a[i]-'a']=(ccnt>>8)&0xFF;
			ch2[p][a[i]-'a']=ccnt>>16;
			tmp=ch0[p][a[i]-'a']+ch1[p][a[i]-'a']*256+ch2[p][a[i]-'a']*65536;
		}
		p=tmp;
	}
	endf[p]=true;
}
bool  find(char a[],int len)
{
	int p=0,i;
	unsigned int tmp;
	for(i=0;i<len;i++)
	{
		tmp=ch0[p][a[i]-'a']+ch1[p][a[i]-'a']*256+ch2[p][a[i]-'a']*65536;
		if( !tmp ) return false;
		p=tmp;
	}
	return endf[p];
}
int main()
{
	char cc,arg[30];
	int N,i;
	scanf("%d\n",&N);
	for(i=1;i<=N;i++)
	{
		cin>>cc>>arg;
		if(cc=='I')
		{	insert(arg,strlen(arg));}
		else
		{
			if(find(arg,strlen(arg)))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}

