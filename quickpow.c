#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/*
    快速幂，a^n%k
*/
int qpow(int a,int n,int k)
{
    if(n==0)
        return 1;
    int res=a;
    n--;
    while(n)
    {
        if(n%2==0)
        {
            n=n>>1;
            a=(a%k*a)%k;
        }
        else
        {
            n--;
        }
        res=a%k*res%k;
    }
    return res;
}
int main()
{
    int a,n,k;
    scanf("%d%d%d",&a,&n,&k);
    printf("%d",qpow(a,n,k));

    return 0;
}
