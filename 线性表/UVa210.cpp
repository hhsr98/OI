#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define N 100
#define PROGRAM_SIZE 25
using namespace std;
int op_time[6],Q,P;
int statement[N][PROGRAM_SIZE+1][3];
int st_pointer[N];
int var[26];
int wait_q[10000],whead,wrear;
int stop_q[10000],shead,srear;
int main()
{
	char st[20];
	int i,j,case_count,ss,pp,cc,cnt,running,tt;
	bool lock_flag,quit;
	scanf("%d",&case_count);
	for(cc=1;cc<=case_count;cc++)
	{
		scanf("%d",&P);
		for(i=1;i<=5;i++) scanf("%d",&op_time[i]);
		scanf("%d",&Q);
		
		for(i=1;i<=P;i++)
		{
			cnt=0;
			do
			{
				cin>>st;
				cnt++;
				if(st[0]=='p'&&st[1]=='r')
				{
					statement[i][cnt][0]=2;
					cin>>st;
					statement[i][cnt][1]=st[0]-'a';
				}
				else if(st[0]=='l'&&st[1]=='o')
				{statement[i][cnt][0]=3;}
				else if(st[0]=='u'&&st[1]=='n')
				{statement[i][cnt][0]=4;}
				else if(st[0]=='e'&&st[1]=='n')
				{statement[i][cnt][0]=5;}
				else
				{
					statement[i][cnt][0]=1;
					statement[i][cnt][1]=st[0]-'a';cin>>st;
					scanf("%d",&statement[i][cnt][2]);
				}
			}
			while(statement[i][cnt][0]!=5);
		}
		
		memset(var,0,sizeof(var));
		for(i=1;i<=P;i++) {wait_q[i]=i;st_pointer[i]=0;}
		whead=0;wrear=P;shead=0;srear=0;
		lock_flag=false;
		
		while(whead!=wrear)
		{
			whead++;
			running=wait_q[whead];
			tt=0;pp=st_pointer[running];
			while(tt<Q)
			{
				quit=false;
				pp++;
				ss=statement[running][pp][0];
				switch(ss)
				{
					case 1:
						j=statement[running][pp][1];
						var[j]=statement[running][pp][2];
						break;
					case 2:
						printf("%d: %d\n",running,var[statement[running][pp][1]]);
						break;
					case 3:
						if(lock_flag) 
						{quit=true;srear++;stop_q[srear]=running;pp--;}
						else
						{lock_flag=true;}
						break;
					case 4:
						lock_flag=false;
						if(shead<srear)
						{
							shead++;
						    wait_q[whead]=stop_q[shead];
						    whead--;
						}
						break;
					case 5:
						quit=true;
						break;
				}
				if(quit) break;
				tt+=op_time[ss];
			}
			st_pointer[running]=pp;
			if(!quit)  {wrear++;wait_q[wrear]=running;}
		}
		if(cc!=case_count)printf("\n");
	}
	system("pause");
	return 0;
}
	
					
								
			
		
		  
		
