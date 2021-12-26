#include<iostream>
using namespace std;
int main()
{
string s;
string t;
cin>>s>>t;
int i = s.length()-1;
int j = t.length()-1;
int c=0;
while(i>=0 && j>=0 && s[i] == t[j])
    {
    //cout<<s[i]<<" == "<<t[j]<<"\n";
    i--;
    j--;
    c++;
    }
cout<<s.length()-c+t.length()-c<<"\n";
return 0;
}
