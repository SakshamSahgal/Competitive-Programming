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
        int n,u,r,d,l;
        cin>>n>>u>>r>>d>>l;
        int u1 = u;
        int r1 = r;
        int d1 = d;
        int l1 = l;
        if(u<=(n-2) && l<=(n-2) && d<=(n-2) && r<=(n-2))
        {
            cout<<"YES\n";
        }
        else
        {

            if(u == n)
            {
                r1--;
                l1--;
            }
            if(r == n)
            {
                u1--;
                d1--;
            }
            if(d == n)
            {
                r1--;
                l1--;
            }
            if(l == n)
            {
                u1--;
                d1--;
            }



            if(u == (n-1))
            {
                if(l1>r1)
                {
                    l1--;
                }
                else
                {
                    r1--;
                }

            }
            if(r == (n-1))
            {
                if(u1>d1)
                    {
                    u1--;
                    }
                else
                    {
                    d1--;
                    }
            }
            if(d == (n-1))
                {
                    if(r1>l1)
                        {
                        r1--;
                        }
                    else
                        {
                        l1--;
                        }
                }
            if(l == (n-1))
                {
                    if(u1>d1)
                        {
                        u1--;
                        }
                    else
                        {
                        d1--;
                        }
                }
        //cout<<u1<<" "<<r1<<" "<<d1<<" "<<l1<<"\n";
        if(u1<0 || r1<0 || d1<0 || l1<0 )
            {
            cout<<"NO\n";
            }
        else
            cout<<"YES\n";
        }
        t--;
    }

    return 0;
}

