#include<iostream>
#include<cstring>
#define usi unsigned short int
using namespace std;
/*
void printer(pair<string,string> x[],usi n)
{
cout<<"\n-----------------\n";
for(usi i=0;i<n;i++)
    {
    cout<<x[i].first<<"#"<<x[i].second<<"\n";
    }
cout<<"\n-----------------\n";
}*/
int main()
{

usi n,m;
cin>>n>>m;
pair<string,string> a[n];
pair<string,string> b[m];
string s;
usi k=0;
getchar(); //buffer flush
for(usi i=0;i<n;i++)
    {
        string str1,str2;
        getline(cin,s);
        k = 0;
        while(s[k] != ' ' && k<s.length())
            {
            str1 += s[k];
            k++;
            }


        for(usi j=(k+1);j<s.length();j++)
           str2 += s[j];
    a[i].first = str1;
    a[i].second = str2;
    }
for(usi i=0;i<m;i++)
    {
     string str1,str2;
    getline(cin,s);
     k = 0;
        while(s[k] != ' ' && k<s.length())
            {
            str1 += s[k];
            k++;
            }
    for(usi j=(k+1);j<(s.length()-1);j++)
           str2 += s[j];

    b[i].first = str1;
    b[i].second = str2;
    }
for(usi i=0;i<m;i++)
    {
    for(usi j=0;j<n;j++)
        {
        if(b[i].second == a[j].second)
            {
            cout<<b[i].first<<" "<<b[i].second<<"; #"<<a[j].first<<"\n";
            }
        }
    }
//printer(a,n);
//printer(b,n);
}




