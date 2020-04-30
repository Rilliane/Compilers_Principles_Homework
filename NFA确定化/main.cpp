#include <iostream>
#include<Queue>
#include<list>
#include<set>
int head[1001],cnt=0,n=0;//head:每一个点链表头部，cnt：边的数目 n:状态数目
using namespace std;
int s;
int t[101];
int tNum=0;
struct Edge
{
    char w;//转移条件
    int s,t;//起点，终点
    int next;//下一个节点
}e[100001];

struct State
{
    int label;
    int a[1001];//所有状态
    int aLength;//状态数目
};
int stateNum=0;
char terminals[101];
int terminalNum=0;
void add(int ss,int tt,char w)
{
    cnt++;e[cnt].next=head[ss];head[ss]=cnt;e[cnt].t=tt;e[cnt].w=w;
}
int shead[1001],scnt=0;
struct SEdge
{
    char w;
    State s,t;
    int next;
}se[100001];
ostream & operator<<( ostream & os,State state)
{
    os<<"length: "<<state.aLength<<" "<<"other: ";
    for(int i=1;i<=state.aLength;i++)
        os<<state.a[i]<<" ";
    os<<endl;
    return os;
}
ostream & operator<<( ostream & os,set<int> sset)
{
    for(auto i=sset.begin();i!=sset.end();i++)
        cout<<*i<<" ";
    return os;
}
void add(State ss,State tt,char w)
{
    scnt++;se[scnt].next=shead[ss.label];shead[ss.label]=scnt;se[scnt].t=tt;se[scnt].w=w;
}
bool operator == (State x,State y)
{
    if(x.aLength!=y.aLength)return  false;
    sort(x.a+1,x.a+x.aLength+1);
    sort(y.a+1,y.a+y.aLength+1);
    for(int i=1;i<=x.aLength;i++)
    {
        if(x.a[i]!=y.a[i])return false;
    }
    return true;
}
State getFirstState()
{
    int num=0;
    int fState[1001];
    num++;
    fState[num]=s;
    queue<int>tempQ;
    tempQ.push(s);
    int vis[1001]={0};
    vis[s]=1;
    while(!tempQ.empty())
    {
        int cur=tempQ.front();
        tempQ.pop();
        for(int i=head[cur];i;i=e[i].next)
        {
            int v=e[i].t;
            char w=e[i].w;
            if(v==cur)continue;
            if(w=='#')
            {
                if(vis[v]==0)
                {
                    vis[v]=1;
                    tempQ.push(v);
                    num++;
                    fState[num]=v;
                }
            }
        }
    }
    State firstState;
    firstState.label=1;
    firstState.aLength=num;
    for(int i=1;i<=num;i++)
        firstState.a[i]=fState[i];
    return firstState;

}

void getKong(int a,int ans[],int &length)
{
    int num=0;
    num++;
    ans[num]=a;
    queue<int>tempQ;
    tempQ.push(a);
    int vis[1001]={0};
    vis[a]=1;
    while(!tempQ.empty())
    {
        int cur=tempQ.front();
        tempQ.pop();
        for(int i=head[cur];i;i=e[i].next)
        {
            int v=e[i].t;
            char w=e[i].w;
            if(v==cur)continue;
            if(w=='#')
            {
                if(vis[v]==0)
                {
                    vis[v]=1;
                    tempQ.push(v);
                    num++;
                    ans[num]=v;
                }
            }
        }
    }
    length=num;

}
State getNextState(State origin,char c)
{
    cout<<"当前寻找字符："<<c<<" ";
      set<int>tempSet,tempSet1;
      for(int i=1;i<=origin.aLength;i++)
      {
          int ss=origin.a[i];
          for(int j=head[ss];j;j=e[j].next)
          {

              int tt=e[j].t;
              int w=e[j].w;
              if(w==c)
              {
                  tempSet.insert(tt);

              }
          }
      }
      tempSet1=tempSet;
      set<int>::iterator it;
      int ans[101],length=0;
      for(it=tempSet.begin();it!=tempSet.end();it++)
      {
          memset(ans,0,sizeof(ans));
          getKong(*it,ans,length);
          for(int i=1;i<=length;i++)
              tempSet1.insert(ans[i]);
      }
      State nextState;
      nextState.aLength=0;
      for(it=tempSet1.begin();it!=tempSet1.end();it++)
      {
          nextState.aLength++;
          nextState.a[nextState.aLength]=*it;
      }
      cout<<" nextState:"<<nextState<<endl;
      return nextState;
}

int main() {
    //cout<<"请输入NFA的起点："<<endl;
    //cin>>s;
    s=7;
    //cout<<"请输入NFA的全部终点，以-1结尾:"<<endl;
    /*
    while(true)
    {
        tNum++;
        int temp;
        cin>>temp;
        if(temp==-1)break;
        t[tNum]=temp;
    }
     */
    tNum=1;
    t[1]=8;
    //cout<<"请输入NFA的全部边，以 起点 终点 转移条件 的形式,最后一行输入0 0 0： "<<endl;
    /*
    while(true)
    {
        int x,y;
        string z;
        cin>>x>>y>>z;
        if(x==0)break;
        char newTerminal=z[0];
        add(x,y,z[0]);
        int flag=0;
        for(int i=1;i<=terminalNum;i++)
            if(terminals[i]==newTerminal)
            {
                flag=1;break;
            }
        if(flag==0)
        {
            terminalNum++;
            terminals[terminalNum]=newTerminal;
        }
    }*/
    add(7,5,'#');
    add(5,5,'a');
    add(5,5,'b');
    add(5,1,'#');
    add(1,3,'a');
    add(1,4,'b');
    add(3,2,'a');
    add(4,2,'b');
    add(2,6,'#');
    add(6,6,'a');
    add(6,6,'b');
    add(6,8,'#');
    terminals[1]='a';
    terminals[2]='b';
    terminals[3]='#';
    terminalNum=3;
    queue<State>q;
    stateNum++;
    list<State>stateList;
    State firstState=getFirstState();
    q.push(firstState);
    stateList.push_back(firstState);
    cout<<"-------------------调试过程--------------------"<<endl;
    while(!q.empty())
    {
        State curState=q.front();
        q.pop();cout<<"curState: "<<curState<<endl;
        for(int i=1;i<=terminalNum;i++)
        {
            if(terminals[i]=='#')continue;
            State tempState=getNextState(curState,terminals[i]);
            int flag=0;
            for(auto j=stateList.begin();j!=stateList.end();j++)
            {
                if(*j==tempState)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                stateNum++;
                tempState.label=stateNum;
                stateList.push_back(tempState);
                add(curState,tempState,terminals[i]);
                q.push(tempState);
            }
            else if(flag==1)
            {
                add(curState,tempState,terminals[i]);
            }
        }
    }
    cout<<endl;
    cout<<endl;
     cout<<"-------------------输出结果（确定化的DFA）-------------------"<<endl;
    for(auto i=stateList.begin();i!=stateList.end();i++)
    {
        cout<<"状态"<<i->label<<": "<<*i<<endl;
        for(int j=shead[i->label];j;j=se[j].next)
        {
            int tt=se[j].t.label;
            char w=se[j].w;
            cout<<"经过"<<w<<"转移到"<<"状态"<<tt<<" "<<se[j].t<<endl;
        }
    }

}