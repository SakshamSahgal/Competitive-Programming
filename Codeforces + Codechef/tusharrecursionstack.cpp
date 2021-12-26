#include<iostream>
using namespace std;
int top=-1;
void push(char s[],char val)
{
    s[++top]=val;
}
void pop()
{
    --top;
}
void reverse(char s[],char val)
{
    if(top==-1)
    {
        //s[++top]=val;
        push(s,val);
        return;
    }
    else
    {
        char temp = s[top];
        pop();
        reverse(s,val);
        //s[++top]=temp;
        push(s,temp);
        return;

    }
}
void empty(char s[])
{
    if(top==-1)
        return;
    else
    {
        char temp=s[top];
        pop();
        empty(s);
        reverse(s,temp);
        return;
    }
}
int main()
{
    string str;
    cin>>str;
    char s[str.length()];
    for(int i=str.length()-1; i>=0; i--)
    {
        push(s,str[i]);
    }
    empty(s);
    while(top>=0)
    {
        cout<<s[top]<<" ";
        pop();
    }
}
