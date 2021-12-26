#include<iostream>
using namespace std;
int main()
{
short int n;
cin>>n;
short int t[n],one=0,two=0,three=0,counter = 0,i,j,k,printer[(n/3)],c=0;

for(int i=0;i<n;i++)
    {
    cin>>t[i];
    }
a:
one=0;
two=0;
three=0;
for(i=0;i<n;i++)
    {
    if(t[i] == 1)
        {
        one = 1;
        t[i] = 0;
        break;
        }
    }
for(j=0;j<n;j++)
    {
    if(t[j] == 2)
        {
        two = 1;
        t[j] = 0;
        break;
        }
    }
for(k=0;k<n;k++)
    {
    if(t[k] == 3)
        {
        three = 1;
        t[k] = 0;
        break;
        }
    }
if(one ==1 && two == 1 && three == 1)
    {
    printer[c] = (i+1);
    printer[c+1] = (j+1);
    printer[c+2] = (k+1);
    c+=3;
    counter++;
    goto a;
    }
cout<<counter<<"\n";
c = 2;
for(int i=0;i<(3*counter);i++)
    {
    cout<<printer[i]<<" ";
    if(i == c)
        {
        cout<<"\n";
        c+=3;
        }
    }
return 0;
}
