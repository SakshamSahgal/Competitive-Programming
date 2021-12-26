#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
bool is_palendrome(string s,int a,int b)
{
    int noz=0;
    int noo=0;
    for(int i=0; i<s.size(); i++)
    {
        if( s[i] != s[s.size()-i-1] )
            return 0;

        if(s[i] == '0')
            noz++;

        else if(s[i] == '1')
            noo++;
    }
    if(noz == a && noo == b)
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int a,b;
        cin>>a>>b;
        int noz=0;
        int noo=0;
        int noq=0;
        string s;
        cin>>s;

        if( ( (s.size()%2 == 0) && (a%2 == 0 && b%2 == 0) ) || ( s.size()%2 == 1 ) )
        {
            for(int i=0; i<s.size(); i++)
            {
                if(s[i] == '0')
                    noz++;
                else if(s[i] == '1')
                    noo++;
                else
                    noq++;
            }

            int rz = a-noz;
            int ro = b - noo;
            if(rz<0 || ro<0)
            {
                cout<<"-1\n";
                goto k;
            }
            // cout<<"rz = "<<rz<<" ro = "<<ro<<"\n";
            if(noq == 0)
            {
                if(is_palendrome(s,a,b) == 1)
                {
                    cout<<s<<"\n";
                    goto k;
                }

                else
                {
                    cout<<"-1\n";
                    goto k;
                }

            }

            else
            {
                if(s.size()%2 == 0)
                {
                    for(int i=0; i<s.size(); i++)
                    {
                        if( s[i] == '1')
                        {
                            //  cout<<"\none found\n";
                            if(s[s.size()-i-1] != '?')
                            {
                                if(s[s.size()-i-1] != '1')
                                {
                                    cout<<"-1\n";
                                    goto k;
                                }
                            }
                        }
                        else if( s[i] == '0' )
                        {
                            //  cout<<"\nzero found\n";
                            if(s[s.size()-i-1] != '?')
                            {
                                if(s[s.size()-i-1] != '0')
                                {
                                    cout<<"-1\n";
                                    goto k;
                                }
                            }

                        }
                        else
                        {
                            // cout<<"\nquestion found\n";
                            if(s[s.size()-i-1] == '1')
                            {
                                if(ro<1)
                                {
                                    cout<<"-1\n";
                                    goto k;
                                }
                                else
                                {
                                    s[i] = '1';
                                    ro--;
                                }
                            }
                            else if(s[s.size()-i-1] == '0')
                            {
                                if(rz<1)
                                {
                                    cout<<"-1\n";
                                    goto k;
                                }
                                else
                                {
                                    s[i] = '0';
                                    rz--;
                                }
                            }
                            else
                            {
                                if(rz>=ro)
                                {

                                    if(rz<2)
                                    {
                                        cout<<"-1\n";
                                        goto k;
                                    }
                                    else
                                    {
                                        s[i] = '0';
                                        s[s.size()-i-1] = '0';
                                        rz-=2;
                                    }
                                }
                                else
                                {
                                    if(ro<2)
                                    {
                                        cout<<"-1\n";
                                        goto k;
                                    }
                                    else
                                    {
                                        s[i] = '1';
                                        s[s.size()-i-1] = '1';
                                        ro-=2;
                                    }
                                }
                            }
                        }

                    }
                }
                else
                {
                    if(s[s.size()/2] == '?')
                    {
                        if(a%2 == 1)
                        {
                            if(rz<1)
                            {
                                cout<<"-1\n";
                                goto k;
                            }
                            else
                            {
                                s[s.size()/2] = '0';
                                rz--;
                            }

                        }
                        else
                        {
                            if(ro<1)
                            {
                                cout<<"-1\n";
                                goto k;
                            }
                            else
                            {
                                s[s.size()/2] = '1';
                                ro--;
                            }
                        }
                    }

                    for(int i=0; i<s.size(); i++)
                    {
                        if( s[i] == '1')
                        {
                            //  cout<<"\none found\n";
                            if(s[s.size()-i-1] != '?')
                            {
                                if(s[s.size()-i-1] != '1')
                                {
                                    cout<<"-1\n";
                                    goto k;
                                }
                            }
                        }
                        else if( s[i] == '0' )
                        {
                            //  cout<<"\nzero found\n";
                            if(s[s.size()-i-1] != '?')
                            {
                                if(s[s.size()-i-1] != '0')
                                {
                                    cout<<"-1\n";
                                    goto k;
                                }
                            }

                        }
                        else
                        {
                            // cout<<"\nquestion found\n";
                            if(s[s.size()-i-1] == '1')
                            {
                                if(ro<1)
                                {
                                    cout<<"-1\n";
                                    goto k;
                                }
                                else
                                {
                                    s[i] = '1';
                                    ro--;
                                }
                            }
                            else if(s[s.size()-i-1] == '0')
                            {
                                if(rz<1)
                                {
                                    cout<<"-1\n";
                                    goto k;
                                }
                                else
                                {
                                    s[i] = '0';
                                    rz--;
                                }
                            }
                            else
                            {
                                if(rz>=ro)
                                {

                                    if(rz<2)
                                    {
                                        cout<<"-1\n";
                                        goto k;
                                    }
                                    else
                                    {
                                        s[i] = '0';
                                        s[s.size()-i-1] = '0';
                                        rz-=2;
                                    }
                                }
                                else
                                {
                                    if(ro<2)
                                    {
                                        cout<<"-1\n";
                                        goto k;
                                    }
                                    else
                                    {
                                        s[i] = '1';
                                        s[s.size()-i-1] = '1';
                                        ro-=2;
                                    }
                                }
                            }
                        }

                    }



                }



            }
            cout<<s<<"\n";
        }
        else
            cout<<"-1\n";
k:
        t--;
    }

    return 0;
}

