#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool all_same(string x)
{
    for(int i=0; i<x.size(); i++)
    {
        if(x[i] != x[0])
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    string s;
    cin>>s;
    lli moves=0;
    int now=0;
    int nob=0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'W')
            now++;
        else
            nob++;
    }

    if(all_same(s) == 1)
    {
        cout<<moves<<"\n";
    }
    else
    {
        vector <int> index;
        if( now%2 == 0 && nob%2 == 0 )
        {
            if(now<=nob)
            {
                for(int i=0; i<n-1; i++)
                {
                    if(s[i] == s[i+1] && s[i] == 'W')
                    {
                        s[i] = 'B';
                        s[i+1] = 'B';
                        moves++;
                        index.push_back(i+1);
                    }
                    if(i<=n-3)
                    {
                        if(s[i] == 'W' && s[i+1] == 'B' && s[i+2] == 'W')
                        {
                            moves+=2;
                            s[i] = 'B';
                            s[i+2] = 'B';
                            index.push_back(i+1);
                            index.push_back(i+2);
                        }
                    }

                }



                if(all_same(s) == 0)
                {
                    moves=0;
                    for(int i=0; i<n-1; i++)
                    {
                        if(s[i] == s[i+1] && s[i] == 'B')
                        {
                            s[i] = 'W';
                            s[i+1] = 'W';
                            moves++;
                            index.push_back(i+1);
                        }
                        if(i<=n-3)
                        {
                            if(s[i] == 'B' && s[i+1] == 'W' && s[i+2] == 'B')
                            {
                                moves+=2;
                                s[i] = 'W';
                                s[i+2] = 'W';
                                index.push_back(i+1);
                                index.push_back(i+2);
                            }

                        }

                    }

                    // cout<<s<<"\n";
                    //cout<<moves<<"\n";

                }

                cout<<s<<"\n";
                cout<<moves<<"\n";

            }
            else
            {
                for(int i=0; i<n-1; i++)
                {
                    if(s[i] == s[i+1] && s[i] == 'B')
                    {
                        s[i] = 'W';
                        s[i+1] = 'W';
                        moves++;
                        index.push_back(i+1);
                    }
                    if(i<=n-3)
                    {
                        if(s[i] == 'B' && s[i+1] == 'W' && s[i+2] == 'B')
                        {
                            moves+=2;
                            s[i] = 'W';
                            s[i+2] = 'W';
                            index.push_back(i+1);
                            index.push_back(i+2);
                        }

                    }

                }

                if(all_same(s) == 0)
                {
                    moves = 0;
                    for(int i=0; i<n-1; i++)
                    {
                        if(s[i] == s[i+1] && s[i] == 'W')
                        {
                            s[i] = 'B';
                            s[i+1] = 'B';
                            moves++;
                            index.push_back(i+1);
                        }
                        if(i<=n-3)
                        {
                            if(s[i] == 'W' && s[i+1] == 'B' && s[i+2] == 'W')
                            {
                                moves+=2;
                                s[i] = 'B';
                                s[i+2] = 'B';
                                index.push_back(i+1);
                                index.push_back(i+2);
                            }
                        }

                    }
                }

                cout<<s<<"\n";
                cout<<moves<<"\n";
            }
        }
        else if(now%2 == 0 || nob%2 == 0)
            {
                if(now%2 == 0)
                {

                }


            }
        else
            cout<<"-1\n";
    }

    return 0;
}
