#include <iostream>

using namespace std;
int head[1001],cnt=0,n=0;//head:每一个点链表头部，cnt：边的数目 n:状态数目
struct Edge
{
    char w;//转移条件
    int s,t;//起点，终点
    int next;//下一个节点
}e[100001];
void add(int ss,int tt,char w)
{
    cnt++;e[cnt].next=head[ss];head[ss]=cnt;e[cnt].t=tt;e[cnt].w=w;
}
int startState;//DFA的初始状态
int endState[101]={0};//DFA的终止状态集合
bool isEnd[101];
int endNum=0;
bool f[101][101];
int terminalNum=0;
int terminals[101];
int getNext(int x,char c)
{
    for(int i=head[x];i;i=e[i].next)
        if(e[i].w==c)
            return e[i].t;
}
int fa[101];
int find(int x)
{
    if(fa[x]!=x)
        fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y)
{
    fa[x]=y;
}
int newStateNum=0;
int main() {

    n=4;
    startState=1;
    endNum=2;
    endState[1]=3;endState[2]=4;
    add(1,2,'a');add(2,1,'a');add(1,4,'b');add(2,3,'b');
    add(3,4,'b');add(4,3,'b');add(3,1,'a');add(4,2,'a');
    isEnd[1]=false;isEnd[2]=false;isEnd[3]=true;isEnd[4]=true;
    terminalNum=2;
    terminals[1]='a';terminals[2]='b';
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            f[i][j]=true;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(isEnd[i]==true&&isEnd[j]==false)
                f[i][j]=false;
            else if(isEnd[i]==false&&isEnd[j]==true)
                f[i][j]=false;

    while(true)
    {
        bool isChanged=false;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                if(f[i][j]==false)continue;
                for(int k=1;k<=terminalNum;k++)
                {
                    int x=getNext(i,terminals[k]);
                    int y=getNext(j,terminals[k]);
                    if(x>y)swap(x,y);
                    if(f[x][y]==false)
                    {
                        isChanged=true;
                        f[i][j]=false;
                    }
                }
            }
        if(isChanged==false)break;
    }

    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(f[i][j])
            {
                merge(i,j);
            }
        }
    int ans[101]={0};
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==i)
        {
            newStateNum++;
            ans[i]=newStateNum;

        }
    }
    for(int i=1;i<=n;i++)
        if(fa[i]!=i)
        {
            int x=find(i);
            ans[i]=ans[x];
        }
    for(int i=1;i<=newStateNum;i++)
    {
        cout<<"第"<<i<<"个简化的状态集合： ";
        for(int j=1;j<=n;j++)
        if(ans[j]==i)
        {
             cout<<j<<" ";
        }
        cout<<endl;
    }

}