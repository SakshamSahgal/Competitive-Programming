#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli Eular_GCD(lli a,lli b)
{
    lli temp;
    if(a!=0 && b!=0)
    {
x:
        if(a == 0)
            return b;
        else if(b == 0)
            return a;
        else
        {
            temp = a;
            a = b;
            b = temp%b;
            goto x;
        }
    }
    else
        return max(a,b);
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli g,h;
        vector<pair<lli,lli>> index;
        vector<pair<lli,lli>> c;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i>0)
            {
                if( Eular_GCD(a[i],a[i-1]) != 1 )
                {
                    g = a[i];
                    h = a[i-1];

                    if(i>1)
                    {
                        if(Eular_GCD( a[i-2], (min(g,h)+1) ) == 1)
                        {
                            a[i] = min(g,h);
                            a[i-1] =  min(g,h)+1;
                        }
                        else
                        {
                            a[i] = min(g,h)+1;
                            a[i-1] =  min(g,h);
                        }
                    }
                    else
                    {
                        a[i] = min(g,h);
                        a[i-1] =  min(g,h)+1;
                    }

                    c.push_back(make_pair(a[i-1],a[i]));
                    index.push_back(make_pair(i,i+1));
                }
            }
        }

        for(int i=0;i<n;i++)
        {
              if(i>0)
            {
                if( Eular_GCD(a[i],a[i-1]) != 1 )
                {
                    g = a[i];
                    h = a[i-1];

                    if(i>1)
                    {
                        if(Eular_GCD( a[i-2], (min(g,h)+1) ) == 1)
                        {
                            a[i] = min(g,h);
                            a[i-1] =  min(g,h)+1;
                        }
                        else
                        {
                            a[i] = min(g,h)+1;
                            a[i-1] =  min(g,h);
                        }
                    }
                    else
                    {
                        a[i] = min(g,h);
                        a[i-1] =  min(g,h)+1;
                    }

                    c.push_back(make_pair(a[i-1],a[i]));
                    index.push_back(make_pair(i,i+1));
                }
            }
        }

        for(int i=0;i<n;i++)
        {
              if(i>0)
            {
                if( Eular_GCD(a[i],a[i-1]) != 1 )
                {
                    g = a[i];
                    h = a[i-1];

                    if(i>1)
                    {
                        if(Eular_GCD( a[i-2], (min(g,h)+1) ) == 1)
                        {
                            a[i] = min(g,h);
                            a[i-1] =  min(g,h)+1;
                        }
                        else
                        {
                            a[i] = min(g,h)+1;
                            a[i-1] =  min(g,h);
                        }
                    }
                    else
                    {
                        a[i] = min(g,h);
                        a[i-1] =  min(g,h)+1;
                    }

                    c.push_back(make_pair(a[i-1],a[i]));
                    index.push_back(make_pair(i,i+1));
                }
            }
        }


        /*
        cout<<"\n--------ARRAY NOW----------\n";
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n"; */

        cout<<c.size()<<"\n";
        for(int i=0; i<c.size(); i++)
        {
            cout<<index[i].first<<" "<<index[i].second<<" "<<c[i].first<<" "<<c[i].second<<"\n";
        }

        t--;
    }

    return 0;
}
