#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MAX 10000+4
#define INF 0x7fffffff
/*
	最短路径 spfa模板
	1到n最短距离
	输入n,m m是路的数目，接下来a,b,w是a到b之间的距离

*/
int dist[MAX];
int mark[MAX];
int n,m;
int cnt;
int head[MAX];
struct node
{
    int to,next,w;
}e[MAX];
void add_edge(int to,int from,int w)
{
    e[cnt].to=to;
    e[cnt].w=w;
    e[cnt].next=head[from];
    head[from]=cnt++;
}
void init()
{
    for(int i=0;i<=n;i++)dist[i]=INF;
    memset(head,-1,sizeof(head));
    memset(mark,0,sizeof(mark));
    memset(e,-1,sizeof(e));
    cnt=0;
}
void spfa(int s)
{
    mark[s]=1;
    dist[s]=0;
    queue<int> que;
    que.push(s);
    while(que.size())
    {
        int p=que.front();
        que.pop();
        mark[p]=0;
        for(int i=head[p];i!=-1;i=e[i].next)
        {
            if(dist[p]+e[i].w<dist[e[i].to])
            {
                dist[e[i].to]=dist[p]+e[i].w;
                if(!mark[e[i].to])
                {
                    mark[e[i].to]=1;
                    que.push(e[i].to);
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add_edge(a,b,w);
        add_edge(b,a,w);
    }
    spfa(1);
    printf("%d",dist[n]);
    return 0;
}
