#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
void fuck(int a);
void shit(int b);
void fuck(int a)
{
     if(a==0) return;
     printf("fuck!\n");
     shit(a-1);
}
void shit(int b)
{
     if(b==0) return;
     printf("shit!\n");
     fuck(b-1);
}
int main()
{
    //fuck(10);
    int d=-13;
    d=d%3;
    printf("%d\n",d);
    printf("%d\n",1<<4);
    printf("%llf",log2(1000000));
    system("pause");
    return 0;
}
    
