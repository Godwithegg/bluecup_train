
标题：螺旋折线

如图p1.png所示的螺旋折线经过平面上所有整点恰好一次。  
对于整点(X, Y)，我们定义它到原点的距离dis(X, Y)是从原点到(X, Y)的螺旋折线段的长度。  

例如dis(0, 1)=3, dis(-2, -1)=9  

给出整点坐标(X, Y)，你能计算出dis(X, Y)吗？

【输入格式】
X和Y  

对于40%的数据，-1000 <= X, Y <= 1000  
对于70%的数据，-100000 <= X， Y <= 100000  
对于100%的数据, -1000000000 <= X, Y <= 1000000000  

【输出格式】
输出dis(X, Y)  


【样例输入】
0 1

【样例输出】
3


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。


#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    long long x,y;
    long long sum=0;
    scanf("%lld%lld",&x,&y);
    if(x>=0&&y>=0){
        sum=max(x,y)*(max(x,y)-1)/2*8;
        sum=sum+max(x,y)+max(x,y)*2+x+max(x,y)-y;
    }else if(x<0&&y>=0){
        sum=max(-x,y)*(max(-x,y)-1)/2*8;
        sum=sum+max(-x,y)+max(-x,y)+x+y;
    }else if(x<0&&y<0){
        sum=(1+max(-x,-y))*max(-x,-y)/2*8;
        sum=sum+y-x;
    }else{
        sum=max(x,-y)*(max(x,-y)-1)/2*8;
        sum=sum+max(x,-y)+max(x,-y)*4+max(x,-y)-x-y;
    }
    printf("%lld",sum);

}