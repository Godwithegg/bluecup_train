#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
/*
    约瑟夫环，N个人站成一排，以此报数，报道K的人出局，如此循环到最后一个人
*/
int main()
{
    int s=0;
    int n;
    int k;
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=2;i<=n;i++)
    {
        s=(s+k)%i;
    }
    printf("%d",s+1);
    return 0;

}
