#include<iostream>
#include<vector>
#define usi unsigned short int
using namespace std;
vector <int> m;
void vector_printer()
{
cout<<"\n---------------\n";
for(usi i=0;i<m.size();i++)
    cout<<m[i]<<" ";
cout<<"\n---------------\n";
}
void string_reverser(char s[],usi k)
{
char temp;
for(usi i=0;i<(k/2);i++)
    {
    temp = s[i];
    s[i] = s[k-1-i];
    s[k-1-i] = temp;
    }
}
void multiples_finder(usi n)
{
for(usi i=2;i<=n;i++)
    {
    if(n%i == 0)
        {
        m.push_back(i);
        }
    }

}
int main()
{
usi n;
cin>>n;
char s[n];
for(usi i=0;i<n;i++)
    cin>>s[i];
if(n==1)
    {
    cout<<s[0];
    }
else
    {
    multiples_finder(n);
    for(usi i=0;i<m.size();i++)
        {
        string_reverser(s,m[i]);
        }
    for(usi i=0;i<n;i++)
            cout<<s[i];
    }

return 0;
}
