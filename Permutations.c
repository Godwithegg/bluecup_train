#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//康托展开式
long long fac(long long n)
{
    if(n<=1)return 1;
    return n*fac(n-1);
}
//计算bckfqlajhemgiodnp是abcdefghijklmnopq全排列的第几位
//X=an*(n-1)!+an-1*(n-2)!+…+ai*(i-1)!+…+a2*1!+a1*0!
int main()
{
    char s[18]="bckfqlajhemgiodnp";
    long long sum=0;
    for(int i=0;i<17;i++)
    {
        long long k=0;
        for(long long j=i+1;j<17;j++)
        {
            if(s[i]>s[j])k++;
        }
        sum+=(k*fac(16-i));
    }
    printf("%lld",sum);
}
