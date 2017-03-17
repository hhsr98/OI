#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<stack>
#define MAXM 1010
using namespace std;
int matrix_info[MAXM][2],pm;
stack<int> s;
int main()
{
	char expr[MAXM*10],ch;
	int N,i,mul_cnt,t1,t2,t3,t4;
	bool failf;
	scanf("%d\n",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%c",&ch);
		scanf("%d%d\n",&matrix_info[ch-'A'][0],&matrix_info[ch-'A'][1]);
	}
	while(scanf("%s",expr)==1)
	{
		pm=N-1;
		i=0;
		failf=false;mul_cnt=0;
		for(i=0;expr[i]!=0;i++)
		{
			if(expr[i]==')')
			{
				t2=s.top();
				s.pop();s.pop();
				if((!s.empty())&& (t1=s.top()) > -1)
				{
					if(matrix_info[t1][1]!=matrix_info[t2][0])
					{failf=true;break;}
					mul_cnt+=matrix_info[t1][0]*matrix_info[t1][1]*\
					   matrix_info[t2][1];
					pm++;
					matrix_info[pm][0]=matrix_info[t1][0];
					matrix_info[pm][1]=matrix_info[t2][1];
					s.pop();
					s.push(pm);
														
				}
				else
				{s.push(t2);}
			}
			else if(expr[i]=='(')
			{	s.push(-1);}
			else
			{
				pm++;
				t4=expr[i]-'A';
				if( (!s.empty()) &&(t3=s.top())>-1)
				{
					if(matrix_info[t3][1]!=matrix_info[t4][0])
					{	failf=true;break;}
					mul_cnt+=matrix_info[t3][0]*matrix_info[t3][1]*\
		   			matrix_info[t4][1];
		   		    matrix_info[pm][0]=matrix_info[t3][0];
			 	    matrix_info[pm][1]=matrix_info[t4][1];
				    s.pop();
					s.push(pm);	
				}
				else
				{	s.push(t4);}
				
				
			}
			
		}
		if(failf) printf("error\n");
		else printf("%d\n",mul_cnt);
		s.pop();
	}
	system("pause");
	return 0;	
	
}
