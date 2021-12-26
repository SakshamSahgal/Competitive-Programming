#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
    {
    int n,dif=0,a=0;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++)
        {
        cin>>s[i];
        }
        dif = s[0] - s[1];
        if(dif<0)
            {
            dif = (-1)*dif;
            }


    for(int i=0;i<n;i++)
        {
        for(int j=i+1;j<n;j++)
            {
            a = s[i] - s[j];
            if(a<0)
                {
                a = (-1)*a;
                }

            if(a<dif)
                {
                dif = a;
                }
            }
        }
    cout<<dif<<"\n";
    }
return 0;
}
