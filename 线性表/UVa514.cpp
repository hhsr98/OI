#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXN 1000
using namespace std;
int rail_stack[MAXN+10][2],spointer,least_ready;
int main()
{
	int N,rail_order[MAXN+10],i;
	bool failf;
	scanf("%d",&N);
	while(N)
	{
		scanf("%d",&rail_order[1]);
		while(rail_order[1])
		{
			for(i=2;i<=N;i++) scanf("%d",&rail_order[i]);
			least_ready=1;
			spointer=0;
			failf=false;
			for(i=1;i<=N;i++)
			{
				if(rail_order[i]<rail_stack[spointer][1]) 
				{failf=true;break;}
				if(rail_order[i]==rail_stack[spointer][1])
				{
					rail_stack[spointer][1]--;
					if(rail_stack[spointer][1]<rail_stack[spointer][0])
					    spointer--;
				}
				else if(rail_order[i]==least_ready) 
				{least_ready++;}
				else if(rail_order[i]>least_ready)
				{
					spointer++;
					rail_stack[spointer][0]=least_ready;
					rail_stack[spointer][1]=rail_order[i]-1;
					least_ready=rail_order[i]+1;
				}
			}
			if(failf) printf("No\n");
			else printf("Yes\n");
			
			scanf("%d",&rail_order[1]);
		}
		
		scanf("%d",&N);
		if(N) printf("\n");
	}
	system("pause");
	return 0;
}
	

 
