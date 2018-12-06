#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
/*
    大整数加法，过于简单，减法省略
*/
char sa[10001];
char sb[10001];
int a[10001];
int b[10001];
int c[10004];
int k=0;
void adddigist()
{
    int n1=strlen(sa);
    int n2=strlen(sb);
    for(int i=0;i<n1;i++)
        a[n1-1-i]=sa[i]-'0';
    for(int i=0;i<n2;i++)
        b[n2-1-i]=sb[i]-'0';
    int d=0;
    int i=0;
    int j=0;

    while(i<n1&&j<n2)
    {
        d+=(a[i]+b[j]);
        c[k]+=d%10;
        i++;
        j++;
        k++;
        d/=10;
    }
    while(i<n1)
    {
        d+=a[i];
        c[k]+=d%10;
        i++;
        k++;
        d/=10;
    }
    while(j<n2)
    {
        d+=b[j];
        c[k]+=d%10;
        j++;
        k++;
        d/=10;
    }
    if(d)
        c[k++]=d;
}
int main()
{
    scanf("%s",sa);
    scanf("%s",sb);
    adddigist();
    for(int i=k-1;i>=0;i--)
        printf("%d",c[i]);

    return 0;
}
