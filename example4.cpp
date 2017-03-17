#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	char aa[100];
	int b[10];
	int a,i;
/*	cout<<scanf("%s%d%*d",aa,&a);
	cout<<aa<<endl;
	cout<<a<<endl;*/
	printf("%d %d %d\n",'0','1','9');
	cout<<sizeof(b)<<' '<<sizeof(int);
	memset(b,-1,sizeof(b));
	for(i=0;i<10;i++) printf("%d ",b[i]);
	cout<<endl;
	memset(b,0,sizeof(int)*2);
	for(i=0;i<10;i++) printf("%d ",b[i]);
	system("pause");
	return 0;
}
