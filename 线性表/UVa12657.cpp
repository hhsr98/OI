#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXN 100010
using namespace std;
bool RIGHT;
#define LEFT (!RIGHT)
int HEAD;
int linkk[MAXN][2];
int main()
{
	int case_cnt,N,M,i,xl,xr,yl,yr,order,X,Y;
	long long sum;
	bool fl;
	RIGHT=0;
	case_cnt=0;
	while(scanf("%d %d",&N,&M)!=0)
	{
		case_cnt++;
		//initialize the link
		for(i=0;i<=N+1;i++)
		{
			linkk[i][RIGHT]=i+1;
			linkk[i][LEFT]=i-1;
		}
		linkk[N+1][RIGHT]=-1;
		HEAD=0;
		
		for(i=1;i<=M;i++)
		{
			scanf("%d",&order);
			switch(order)
			{
				case 1:
					scanf("%d %d",&X,&Y);
					if(linkk[Y][LEFT]!=X)
					{
						xl=linkk[X][LEFT];
						xr=linkk[X][RIGHT];
						linkk[xl][RIGHT]=xr;linkk[xr][LEFT]=xl;
						yl=linkk[Y][LEFT];
						linkk[yl][RIGHT]=X;linkk[X][LEFT]=yl;
						linkk[X][RIGHT]=Y;linkk[Y][LEFT]=X;
					}
					break;
				case 2:
					scanf("%d %d",&X,&Y);
					if(linkk[Y][RIGHT]!=X)
					{
						xl=linkk[X][LEFT];
						xr=linkk[X][RIGHT];
						linkk[xl][RIGHT]=xr;linkk[xr][LEFT]=xl;
						yr=linkk[Y][RIGHT];
						linkk[yr][LEFT]=X;linkk[X][RIGHT]=yr;
						linkk[X][LEFT]=Y;linkk[Y][RIGHT]=X;
					}
					break;
				case 3:
					scanf("%d %d",&X,&Y);
					xl=linkk[X][LEFT];xr=linkk[X][RIGHT];
					yl=linkk[Y][LEFT];yr=linkk[Y][RIGHT];
					if(xr==Y)
					{
						linkk[xl][RIGHT]=Y;linkk[Y][LEFT]=xl;
						linkk[yr][LEFT]=X;linkk[X][RIGHT]=yr;
						linkk[Y][RIGHT]=X;linkk[X][LEFT]=Y;
					}
					else if(yr==X)
					{
						linkk[yl][RIGHT]=X;linkk[X][LEFT]=yl;
						linkk[xr][LEFT]=Y;linkk[Y][RIGHT]=xr;
						linkk[X][RIGHT]=Y;linkk[Y][LEFT]=X;
					}
					else
					{
						
						linkk[xl][RIGHT]=Y;linkk[Y][LEFT]=xl;
						linkk[xr][LEFT]=Y;linkk[Y][RIGHT]=xr;
						linkk[yl][RIGHT]=X;linkk[X][LEFT]=yl;
						linkk[yr][LEFT]=X;linkk[X][RIGHT]=yr;
					}
					break;
				case 4:
					RIGHT=!RIGHT;
					HEAD=(N+1)-HEAD;
					break;
			}
		}
		sum=0;
		for(i=linkk[HEAD][RIGHT],fl=1;i!=(N+1)-HEAD;i=linkk[i][RIGHT],fl=!fl)
		{	sum+=i*fl;}
		printf("Case %d: %lld\n",case_cnt,sum);	
	}
	system("pause");
	return 0;
}
	
