#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
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
        int n;
        cin>>n;
        lli a[n];
        int nop=0;
        int non=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]>0)
                nop++;
            else if(a[i]<0)
                non++;
        }

        int noz = n - nop - non;
        sort(a,a+n);


        if(nop>=1)
        {
            if(nop == 1 || nop == 2)
            {
                if(nop == 2)
                {
                    if(non >=4)
                        cout<<(a[n-1]*a[0]*a[1]*a[2]*a[3])<<"\n"; //1 + 4 -
                    else
                    {
                        if(noz>=1)
                            cout<<0<<"\n";
                        else
                            cout<<a[0]*a[1]*a[2]*a[n-1]*a[n-2]<<"\n";
                    }
                }
                else
                {
                    if(non >=4)
                        cout<<(a[n-1]*a[0]*a[1]*a[2]*a[3])<<"\n";
                    else
                        cout<<0<<"\n";
                }

            }
            else if(nop == 3 || nop == 4)
            {
                if(nop==4)
                {
                    if(non >=4)
                        cout<<max(a[n-1]*a[0]*a[1]*a[2]*a[3],a[n-1]*a[n-2]*a[n-3]*a[0]*a[1])<<"\n"; //max pos 1 , pos 3
                    else if(non>=2)
                    {
                        cout<<(a[n-1]*a[n-2]*a[n-3]*a[0]*a[1])<<"\n"; // 3 +
                    }
                    else
                    {
                        if(noz>=1)
                            cout<<0<<"\n";
                        else
                            cout<<a[0]*a[n-1]*a[n-2]*a[n-3]*a[n-4]<<"\n"; //1-4+
                    }
                }
                else
                {
                    if(non >=4)
                        cout<<max(a[n-1]*a[0]*a[1]*a[2]*a[3],a[n-1]*a[n-2]*a[n-3]*a[0]*a[1])<<"\n"; //max pos 1 , pos 3
                    else if (non>=2)
                        cout<<(a[n-1]*a[n-2]*a[n-3]*a[0]*a[1])<<"\n"; // 3 +
                    else
                        cout<<0<<"\n";
                }
            }
            else
            {
                if(non >=4)
                {
                    lli x[3];
                    //1 pos
                    x[0] = a[0]*a[1]*a[2]*a[3]*a[n-1];
                    //3 pos
                    x[1] = a[0]*a[1]*a[n-1]*a[n-2]*a[n-3];
                    //5 pos
                    x[2] = a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5];
                    sort(x,x+3);
                    cout<<x[2]<<"\n";
                }
                else if(non>=2)
                {
                    //3 pos
                    lli c = a[0]*a[1]*a[n-1]*a[n-2]*a[n-3];
                    //5 pos
                    lli d = a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5];
                    cout<<max(c,d)<<"\n";
                }
                else
                 cout<<a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5]<<"\n";
            }
        }
        else
        {
            if(noz >=1)
                cout<<0<<"\n";
            else
            {
                //all -
                for(int i=n-1; i>=0; i--)
                {
                    if(a[i]<0)
                    {
                        cout<<a[i]*a[i-1]*a[i-2]*a[i-3]*a[i-4]<<"\n";
                        goto j;
                    }
                }
            }

        }

j:
        t--;
    }

    return 0;
}

