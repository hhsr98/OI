#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int P,Q,N,i,j,k,l;
    long long val[3][3],temp[3][3],power[3][3],temp1;
    scanf("%d %d",&P,&Q);
    while(P!=0||Q!=0)
      {scanf("%d",&N);
       if(N==0) printf("2\n");
       else if(N==1) printf("%d\n",P);
       else
         {val[1][1]=1;val[1][2]=0;val[2][1]=0;val[2][2]=1;
          power[1][1]=0;power[1][2]=1;power[2][1]=-Q;power[2][2]=P;
          for(i=N-1;i!=0;i>>=1)
            {if(i&1)
               {for(j=1;j<=2;j++)
                  for(k=1;k<=2;k++)
                    {temp[j][k]=0;
                     for(l=1;l<=2;l++) temp[j][k]+=power[j][l]*val[l][k];
                    }
                for(j=1;j<=2;j++) for(k=1;k<=2;k++) val[j][k]=temp[j][k];
               }
             for(j=1;j<=2;j++)
                  for(k=1;k<=2;k++)
                    {temp[j][k]=0;
                     for(l=1;l<=2;l++) temp[j][k]+=power[j][l]*power[l][k];
                    }
             for(j=1;j<=2;j++) for(k=1;k<=2;k++) power[j][k]=temp[j][k];
            }
          temp1=2*val[2][1]+P*val[2][2];
          printf("%lld\n",temp1);
         }
       scanf("%d %d",&P,&Q);
      }
    system("pause");
    return 0;
}
