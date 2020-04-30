#include <iostream>
#include<fstream>
using namespace std;
string s;
int num=0,start=0;

int deleteZhushi1()
{
    while(true)
    {
        start++;
        if(s[start]=='}')
        {

            return start+1;
        }
    }
}
int deleteZhushi2()
{
    start++;
    while(true)
    {
        start++;
        if(s[start]=='*'&&s[start+1]==')')
        {
            return start+2;
        }
    }
}
int deleteZhushi3()
{
    start++;
    while(true)
    {
        start++;
        if(s[start]=='\n')return start+1;
    }
}
//返回下一条语句
string getNext()
{
    string ans="";
    int end=-1;
    while(true)
    {
        if(s[start]=='{')end=deleteZhushi1();
        else if(s[start]=='('&&s[start+1]=='*')end=deleteZhushi2();
        else if(s[start]=='/'&&s[start+1]=='/')end=deleteZhushi3();
        else if(s[start]!='\n'){
            ans+=s[start];
            start++;
        }
        else{
            if(ans!="")
            return ans;
            else start++;
        }
        if(end!=-1)
        {
            start=end;
            end=-1;
        }
    }

}


int main() {
    ifstream in("/Users/christine/Desktop/线上学习汇总/编译原理/3.pas");
    while(!in.eof()) {
        string temp;
        getline(in,temp);
        //if(temp=="")break;
        s += temp;
        s+='\n';
    }
    cout<<s;
    string ss[100];
    while(true)
    {
        ss[num]=getNext();
        int flag=0;
        for(int i=0;i<ss[num].length();i++)
            if(ss[num][i]!=' ')
            {
                flag=1;break;
            }
        if(flag==0)continue;
        cout<<num<<"  "<<ss[num]<<endl;
        num++;
        if(start>=s.length()-1)break;
    }
}

