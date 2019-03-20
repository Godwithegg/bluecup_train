#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define MAX 1000000
int per[MAX];
int rank[MAX];
void init(int n)
{
    for(int i=0;i<=n;i++)
        per[i]=i;   //它的父亲就是它自己
}
int xfind(int x)
{
    if(x==per[x])
        return x;   //如果他的父亲就是它自己，返回该节点
    return per[x]=xfind(per[x]);    //如果它的父亲不是本身，那么继续向上找它的父亲
}
void unite(int x,int y)
{
    if(xfind(x)!=xfind(y))   //如果它们父亲不是同一个
        per[xfind(x)]=xfind(y);     //那么把一个人变成另一个人的儿子
}
int main()
{
    init(10000);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        unite(a,b);     //连接情况
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        if(per[i]==i)   //如果它的父亲还是本身的话，说明它和别人没有血缘关系，所以是独立的
            sum++;
    printf("%d",sum-1);
}
