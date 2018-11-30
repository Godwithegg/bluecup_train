#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int> > que;  //将队列按照数值大小从小到大排列
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        que.push(k);
    }
    int total=0;
    while(!que.empty())
    {
        int a=que.top();
        que.pop();
        int b=que.top();
        que.pop();
        int sum=a+b;   //合并最小的两个果子
        total+=sum;
        if(!que.empty())  //如果当前还有果子没有被合并
        {
            que.push(sum);
        }
    }
    printf("%d",total);   //总共合并的次数
    return 0;
}
