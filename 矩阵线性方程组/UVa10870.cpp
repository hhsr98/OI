#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int D,N,M;
int power[30][30];
int val[30][30];
int f[30];

void mul(int a1[][30],int a2[][30],int a3[][30],int m,int d)
{
     int temp[30][30];
     int i,j,k;
     for(i=1;i<=d;i++)
       for(j=1;j<=d;j++)
         {temp[i][j]=0;
          for(k=1;k<=d;k++)
            temp[i][j]=(temp[i][j]+a1[i][k]*a2[k][j]%m)%m;
         }
     for(i=1;i<=d;i++)
       for(j=1;j<=d;j++)
         a3[i][j]=temp[i][j];
}
int main()
{
    int i,j,k,temp1;
    scanf("%d %d %d",&D,&N,&M);
    while(D!=0)
      {for(i=1;i<=D;i++)
         {scanf("%d",&power[D][D-i+1]);
          power[D][D-i+1]%=M;
          val[D][i]=0;
         }
       for(i=1;i<=D;i++)
          {scanf("%d",&f[i]);
           f[i]%=M;
          }
       if(N<=D) {printf("%d\n",f[N]);}
       else
         {for(i=1;i<=D-1;i++)
            for(j=1;j<=D;j++)
              {power[i][j]=(j==i+1)?1:0;
               val[i][j]=0;
              }
          for(i=1;i<=D;i++) val[i][i]=1;
          for(i=N-D;i!=0;i>>=1)
            {if(i&1) mul(power,val,val,M,D);
             mul(power,power,power,M,D);
            }
          temp1=0;     
          for(i=1;i<=D;i++)
            temp1=(temp1+f[i]*val[D][i]%M)%M;
          printf("%d\n",temp1); 
         }
       scanf("%d %d %d",&D,&N,&M);
      }
    system("pause");
    return 0;
}
          
       
          
