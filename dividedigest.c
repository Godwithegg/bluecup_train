#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
/*3=3 3=1+2 3=1+1+1 3ÖÖ*/
int total=0;
int dfs(int n,int m)
{
    if(n==0)
    {
        total++;
        return 0;
    }
    for(int i=m;i<=n;i++)
    {
        dfs(n-i,i);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    dfs(n,1);
    printf("%d",total);
}
