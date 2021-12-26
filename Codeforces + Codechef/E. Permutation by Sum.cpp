#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
void now_rem(map<int,int> remaining)
{
    cout<<"\n--------------------------------------\n";
    cout<<"now remaining = \n";
    for(auto i = remaining.begin(); i!=remaining.end(); i++)
        cout<<i->first<<" ";
    cout<<"\n--------------------------------------\n";
}

void pair_printer(vector<pair<int,int>> v)
{
    cout<<"\n------------pair------------\n";
    cout<<"value =     ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" ";
    cout<<"\n";
    cout<<"max value = ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].second<<" ";
    cout<<"\n-------------------------------\n";
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        int x = r-l+1;
        lli lower_limit = (x*(x+1))/2;
        lli Upper_limit = (x*((2*n)+1-x))/2;
        int a[n+1] = {0};
        map<int,int> remaining;

        for(int i=1; i<=n; i++)
            remaining[i] = i;

        if(lower_limit<=s && s<=Upper_limit)
        {
            if(x == 1)
            {
                if(1<=s && s<=n)
                {
                    a[l] = s;
                    remaining.erase(s);
                    //  now_rem(remaining);
                    for(int i=1; i<=n; i++)
                    {
                        if(a[i] == 0)
                        {
                            auto ptr = remaining.begin();
                            a[i] = ptr->first;
                            remaining.erase(ptr);
                        }
                    }
                    for(int i=1; i<=n; i++)
                        cout<<a[i]<<" ";

                    cout<<"\n";
                }
                else
                    cout<<"-1\n";
            }
            else if(x == n)
            {
                if( s == (n*(n+1))/2 )
                {
                    for(int i=1; i<=n; i++)
                        cout<<i<<" ";
                    cout<<"\n";
                }
                else
                    cout<<"-1\n";
            }
            else
            {
                vector<pair<int,int>> p;
                lli sum=0;
                for(int i=x,j=n; i>=1; i--,j--)
                {
                    // cout<<"value = "<<i<<" max value = "<<j<<"\n";
                    sum+=i;
                    p.insert(p.begin(), {i,j});
                }

                // pair_printer(p);
                //cout<<"sum = "<<sum<<"\n";
                if(sum == s)
                {
                   // cout<<"Found\n";
                    for(int i=0,j=l; i<p.size(); i++,j++)
                    {
                        a[j] = p[i].first;
                        remaining.erase(p[i].first);
                    }

                    // now_rem(remaining);

                    for(int i=1; i<=n; i++)
                    {
                        if(a[i] == 0)
                        {
                            auto ptr = remaining.begin();
                            a[i] = ptr->first;
                            remaining.erase(ptr);
                        }
                    }

                    for(int i=1; i<=n; i++)
                        cout<<a[i]<<" ";

                    cout<<"\n";

                    goto h;
                }
                else
                {
                    for(int i=x-1; i>=0; i--)
                    {
                        while(p[i].first<p[i].second)
                        {
                            p[i].first++;
                            sum++;
                            // pair_printer(p);
                            //  cout<<"sum = "<<sum<<"\n";
                            if(sum == s)
                            {
                                // cout<<"Found\n";

                                for(int i=0,j=l; i<p.size(); i++,j++)
                                {
                                    a[j] = p[i].first;
                                    remaining.erase(p[i].first);
                                }

                                // now_rem(remaining);

                                for(int i=1; i<=n; i++)
                                {
                                    if(a[i] == 0)
                                    {
                                        auto ptr = remaining.begin();
                                        a[i] = ptr->first;
                                        remaining.erase(ptr);
                                    }
                                }

                                for(int i=1; i<=n; i++)
                                    cout<<a[i]<<" ";

                                cout<<"\n";

                                goto h;
                            }
                        }

                    }


                }

                cout<<"-1\n";
            }

        }
        else
            cout<<"-1\n";
h:
        t--;
    }

    return 0;
}

