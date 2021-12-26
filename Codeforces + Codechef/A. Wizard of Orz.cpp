#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    ui n;
    cin>>n;
    if(n==1)
        cout<<9<<"\n";
    else if(n==2)
        cout<<98<<"\n";
    else if(n==3)
    cout<<989<<"\n";
    else if(n==4)
         cout<<9890<<"\n";
    else
        {
            cout<<9890;
            int f=1;
            for(ui i=0;i<(n-4);i++,f++)
                {
                cout<<f;
                if(f==9)
                    f=-1;
                }
            cout<<"\n";
        }


    t--;
    }



return 0;
}
