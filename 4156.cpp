//动态规划 秒了

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool cmp(int a,int b)
{return a>b;}
int n,A[3005],B[3005],F[3005][3005];
int G(int a,int b)
{
    if(A[a]>B[b])return 200;
    if(A[a]==B[b])return 0;
    if(A[a]<B[b])return -200;
}
int dp(int x,int y)
{
    if(x==y)return F[x][y]=G(x,n);
    if(F[x][y]!=F[0][0])return F[x][y];
    return F[x][y]=max(dp(x+1,y)+G(x,n+x-y),dp(x,y-1)+G(y,n+x-y));
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&A[i]);
    for(i=1;i<=n;i++)scanf("%d",&B[i]);
    sort(A+1,A+n+1,cmp);
    sort(B+1,B+n+1,cmp);
    memset(F,-10,sizeof(F));
    printf("%d\n",dp(1,n));
}