#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
struct coordinate 
{
	int x;
	int y;
};
coordinate add(coordinate a,coordinate b)
{
	coordinate c;
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	return c;
}
int main()
{
	int a[10][2][10],i,j,k;
	coordinate a1,a2;
	a1.x=1;a1.y=2;
	a2.x=3;a2.y=4;
	printf("%d %d\n",add(a1,a2).x,add(a1,a2).y);
	printf("%d %d %d",add(a1,a2));
	system("pause");
	for(i=0;i<10;i++)
	  for(j=0;j<2;j++)
	    for(k=0;k<10;k++)
	      a[i][j][k]=i+j+k;
    //memset(a[1][1],0,sizeof(a[1][1]));
    memset(a,0,sizeof(a));
    for(i=0;i<10;i++)
      {for(j=0;j<2;j++)
         for(k=0;k<10;k++)
          printf("%d ",a[i][j][k]);
       printf("\n");
      }
    system("pause");
	return 0;
}
	
