#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
char text[100010];
int nextt[100010];
int endd,cur;
int main()
{
	int i,pt;
	while(cin>>text)
	{
		nextt[0]=-1;endd=0;cur=-1;
		for(pt=0,i=0;text[i]!=0;i++)
		{
			switch(text[i])
			{
				case '[':
					nextt[pt]=cur;								
					cur=nextt[0];
					pt=0;
					break;
				case ']':
					nextt[pt]=cur;
					cur=-1;
					pt=endd;
					break;
				default :
					nextt[pt]=i+1;
					pt=nextt[pt];
					endd=cur>-1?endd:pt;
					nextt[pt]=-1;
					break;
			}
		}
		nextt[pt]=cur;
		for(i=nextt[0];i!=-1;i=nextt[i])
			printf("%c",text[i-1]);
		printf("\n");		
	}
	system("pause");
	return 0;
}
	
