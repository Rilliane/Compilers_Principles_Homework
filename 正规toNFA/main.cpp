#include <iostream>
#include<stack>
#include<algorithm>
#include<Queue>
using namespace std;
int head[1001],cnt=0,n=0;//head:每一个点链表头部，cnt：边的数目 n:状态数目
int vis[10001]={0};
struct Edge
{
    char w;//转移条件
    int s,t;//起点，终点
    int next;//下一个节点
}e[100001];

void add(int s,int t,char w)
{
    cnt++;e[cnt].next=head[s];head[s]=cnt;e[cnt].t=t;e[cnt].w=w;
}
bool isChar(char x)
{
    if(x=='|')return true;
    if(x==')'||x=='('||x=='^'||x=='*')return true;
    return false;
}
struct NFA
{
    int start,end;
    bool isOne;
    char one;
}nFA[10001];

string s="0010(0|1)^01";
string ss;//后缀表达式
int main()
{
    cout<<"原始串："<<s<<endl;
    stack<char>st;
    int length=s.length();
    for(int i=1;i;i++)
    {

        s.insert(i,1,'*');
        i++;
        if(i>=s.length())break;
    }
    int i=1;
    while(true)
    {
        if(s[i]=='*')
        {
            if(s[i-1]=='('||s[i-1]=='|')
            {
                s.erase(i,1);

            }
            else if(s[i+1]==')'||s[i+1]=='|'||s[i+1]=='^')
            {
                s.erase(i,1);
            }
            else i++;


        }
        else{
            i++;
        }

        if(i>=s.length()-1)break;
    }
    s.erase(s.length()-1,1);

    //cout<<s<<endl;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')')
        {
            while(true)
            {
                if(st.empty())break;
                char temp=st.top();
                if(temp=='(')
                {
                    st.pop();
                    break;
                }
                else{
                    ss+=temp;
                    st.pop();
                }
            }
        }
        else if(s[i]=='^')//优先级最高，直接压栈
        {
            st.push(s[i]);
        }
        else if(s[i]=='*')
        {
            while(true)
            {
                if(st.empty())break;
                char temp=st.top();
                if(temp=='('||temp=='|')break;
                if(temp=='^'||temp=='*')
                {
                    st.pop();
                    ss+=temp;
                }
            }
            st.push(s[i]);
        }
        else if(s[i]=='|')
        {
            while(true)
            {
                if(st.empty())break;
                char temp=st.top();
                if(temp=='(')break;
                if(temp=='^')
                {
                    st.pop();
                    ss+=temp;
                }
                else if(temp=='*')
                {
                    st.pop();
                    ss+=temp;
                }
                else if(temp=='|')
                {
                    st.pop();
                    ss+=temp;
                }

            }
            st.push(s[i]);
        }
        else
        {
            ss+=s[i];
        }
    }
    while(!st.empty())
    {
      ss+=st.top();
      st.pop();
    }
    cout<<"后缀表达式："<<ss<<endl;

    stack<NFA>nst;

    i=0;
    while(true)
    {
        if(i>=ss.length())break;
        if(!isChar(ss[i]))
        {
            NFA temp;
            n++;
            temp.start=n;
            n++;
            temp.end=n;
            add(temp.start,temp.end,ss[i]);
            nst.push(temp);
        }
        else {
            if(ss[i]=='^')
            {
                NFA temp=nst.top();
                nst.pop();
                int newStart,newEnd;
                newStart=temp.start;
                newEnd=temp.end;
                add(temp.end,temp.start,'#');
                NFA newTemp;
                newTemp.start=newStart;
                newTemp.end=newEnd;
                nst.push(newTemp);
            }
            else if(ss[i]=='|'){
                NFA temp1=nst.top();
                nst.pop();
                NFA temp2=nst.top();
                nst.pop();
                int newStart,newEnd;
                n++;
                newStart=n;
                n++;
                newEnd=n;


                    add(temp1.end,newEnd,'#');
                    add(temp2.end,newEnd,'#');
                    add(newStart,temp1.start,'#');
                    add(newStart,temp2.start,'#');

                NFA newTemp;
                newTemp.start=newStart;
                newTemp.end=newEnd;
                nst.push(newTemp);

            }
            else if(ss[i]='*')
            {
                NFA temp1=nst.top();
                nst.pop();
                NFA temp2=nst.top();
                nst.pop();
                int newStart,newEnd;
                newStart=temp2.start;
                newEnd=temp1.end;

                add(temp2.end,temp1.start,'#');
                NFA newTemp;
                newTemp.start=newStart;
                newTemp.end=newEnd;
                nst.push(newTemp);

            }
        }
        i++;
    }
    NFA finalNFA=nst.top();
    nst.pop();
    cout<<"起点："<<finalNFA.start<<" 终点："<<finalNFA.end<<endl;
    queue<int>q;
    q.push(finalNFA.start);
    vis[finalNFA.start]=1;
    while(!q.empty())
    {
        int curNode=q.front();
        q.pop();
        cout<<"状态"<<curNode<<":"<<endl;
        for(int i=head[curNode];i;i=e[i].next)
        {
            int v=e[i].t;
            char w=e[i].w;
            cout<<"读入"<<w<<"转移到"<<v<<endl;
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }

}