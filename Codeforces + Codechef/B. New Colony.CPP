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
    int n,k;
    cin>>n>>k;
    int h[n];

    for(int i=0;i<n;i++)
        cin>>h[i];

    int c=0;
    int j=-1;
    x:
    for(int i=0;i<=(n-1);)
        {
            if(i == (n-1) )
                {
                j = -1;
                break;
                }
            if(h[i]>=h[i+1])
                    i++;
            else
                {
                h[i]++;
                j=i+1;
                //cout<<"\n";
               // for(int j=0;j<n;j++)
                   // cout<<" "<<h[j];
                //cout<<"\n";
                break;
                }

        }
    //cout<<"j = "<<j<<"\n";
    c++;

    if(c==k)
        {
        cout<<j<<"\n";
        goto y;
        }

    if(j!=(-1))
        goto x;
    //cout<<c<<"\n";

    if(k>c)
        {
        cout<<"-1\n";
        goto y;
        }
    y:
    t--;
    }



return 0;
}
