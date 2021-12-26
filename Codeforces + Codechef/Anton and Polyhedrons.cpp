#include<iostream>
using namespace std;
int main()
{
int n,counter = 0;
cin>>n;
string s[n];
for(int i=0;i<n;i++)
    {
    cin>>s[i];
    }
for(int i=0;i<n;i++)
    {
    if(s[i] == "Tetrahedron")
        {
            counter+=4;
        }
    else if(s[i] == "Cube")
        {
        counter+=6;
        }
    else if(s[i] == "Octahedron")
        {
        counter+=8;
        }
    else if(s[i] == "Dodecahedron")
        {
        counter+=12;
        }
    else if(s[i] == "Icosahedron")
        {
        counter+=20;
        }
    }
cout<<counter;
return 0;
}
