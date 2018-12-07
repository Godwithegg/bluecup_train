#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAX_N=10000;
const int INF=100000000;
int N,M;
int sx,sy,gx,gy;
int dist[MAX_N][MAX_N];
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char maze[MAX_N][MAX_N];
typedef pair<int ,int > P;
int bfs()
{
    queue<P> que;
    dist[sx][sy]=0;
    que.push(P(sx,sy));
    while(que.size())
    {
        P p=que.front();
        que.pop();
        if(p.first==gx&&p.second==gy)break;
        for(int i=0;i<4;i++)
        {
            int nx=p.first+d[i][0];
            int ny=p.second+d[i][1];
            if(nx>=0&&ny>=0&&nx<N&&ny<M&&maze[nx][ny]!='#')
            {
                que.push(P(nx,ny));
                dist[nx][ny]=dist[p.first][p.second]+1;
            }
        }
    }
    return dist[gx][gy];
}
int main()
{

    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        dist[i][j]=INF;
    for(int i=0;i<N;i++)scanf("%s",maze[i]);

    sx=sy=0;
    gx=N-1;
    gy=M-1;
    printf("%d",bfs());
    return 0;
}
